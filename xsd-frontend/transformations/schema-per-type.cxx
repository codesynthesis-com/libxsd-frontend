// file      : xsd-frontend/transformations/schema-per-type.cxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2006-2009 Code Synthesis Tools CC
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <xsd-frontend/transformations/schema-per-type.hxx>

#include <xsd-frontend/semantic-graph.hxx>
#include <xsd-frontend/traversal.hxx>

#include <cult/containers/map.hxx>
#include <cult/containers/set.hxx>
#include <cult/containers/vector.hxx>

#include <sstream>
#include <iostream>

#include <strings.h> // strcasecmp

using std::wcerr;
using std::endl;

namespace XSDFrontend
{
  using namespace Cult;

  typedef WideString String;
  typedef Transformations::SchemaPerType::Failed Failed;

  typedef Containers::Vector<SemanticGraph::Schema*> Schemas;
  typedef Containers::Map<SemanticGraph::Type*,
                          SemanticGraph::Schema*> TypeSchemaMap;

  // Compare file paths case-insensitively.
  //
  struct FileComparator
  {
    Boolean
    operator() (NarrowString const& x, NarrowString const& y) const
    {
      return strcasecmp (x.c_str (), y.c_str ()) < 0;
    }
  };

  typedef Containers::Set<NarrowString, FileComparator> FileSet;

  namespace
  {
    // Go into included and imported schemas while making sure
    // we don't process the same stuff more than once.
    //
    struct Uses: Traversal::Includes,
                 Traversal::Imports,
                 Traversal::Implies
    {
      Uses (Schemas& schemas, SemanticGraph::Schema*& xsd)
          : schemas_ (schemas), xsd_ (xsd)
      {
        xsd_ = 0;
      }

      virtual Void
      traverse (SemanticGraph::Includes& i)
      {
        SemanticGraph::Schema& s (i.schema ());

        if (!s.context ().count ("xsd-frontend-schema-per-type-seen"))
        {
          schemas_.push_back (&s);
          s.context ().set ("xsd-frontend-schema-per-type-seen", true);
          Traversal::Includes::traverse (i);
        }
      }

      virtual Void
      traverse (SemanticGraph::Imports& i)
      {
        SemanticGraph::Schema& s (i.schema ());

        if (!s.context ().count ("xsd-frontend-schema-per-type-seen"))
        {
          schemas_.push_back (&s);
          s.context ().set ("xsd-frontend-schema-per-type-seen", true);
          Traversal::Imports::traverse (i);
        }
      }

      virtual Void
      traverse (SemanticGraph::Implies& i)
      {
        if (xsd_ == 0)
          xsd_ = &i.schema ();
      }

    private:
      Schemas& schemas_;
      SemanticGraph::Schema*& xsd_;
    };

    Void
    process_schema (SemanticGraph::Schema& s,
                    SemanticGraph::Schema& root,
                    SemanticGraph::Schema& xsd,
                    TypeSchemaMap& tsm,
                    FileSet& file_set,
                    Transformations::TypeSchemaTranslator& trans)
    {
      using namespace SemanticGraph;

      Path xsd_path ("XMLSchema.xsd");
      Namespace& ns (dynamic_cast<Namespace&> (s.names_begin ()->named ()));

      // We should be careful with iterator caching since we are going to
      // remove some of the nodes.
      //
      for (Scope::NamesIterator i (ns.names_begin ()); i != ns.names_end ();)
      {
        Nameable& n (i->named ());

        if (n.is_a<Type> ())
        {
          String name (n.name ());

          // Remove from the namespace.
          //
          Scope::NamesIterator tmp (i++);
          root.delete_edge (ns, n, *tmp);

          // Add a new schema node.
          //
          Path path;
          String wbase (trans.translate (ns.name (), name));

          try
          {
            NarrowString base (wbase.to_narrow ());

            // Escape directory separators.
            //
            for (NarrowString::Iterator i (base.begin ()), e (base.end ());
                 i != e; ++i)
            {
              if (*i == '/' || *i == '\\')
                *i = '_';
            }

            // Make sure it is unique.
            //
            NarrowString file_name (base);

            for (UnsignedLong i (1);
                 file_set.find (file_name) != file_set.end ();
                 ++i)
            {
              std::ostringstream os;
              os << i;
              file_name = base + os.str ();
            }

            file_set.insert (file_name);

            file_name += ".xsd";

            try
            {
              path = Path (file_name);
            }
            catch (InvalidPath const&)
            {
              wcerr << "error: '" << file_name.c_str () << "' is not a valid "
                    << "filesystem path" << endl;

              wcerr << "info: use type to file name translation mechanisms "
                    << "to resolve this" << endl;

              throw Failed ();
            }
          }
          catch (String::NonRepresentable const&)
          {
            wcerr << "error: '" << wbase << "' cannot be represented as a "
                  << "narrow string" << endl;

            wcerr << "info: use type to file name translation mechanisms "
                  << "to resolve this" << endl;

            throw Failed ();
          }

          Schema& ts (root.new_node<Schema> (path, 1, 1));
          root.new_edge<Implies> (ts, xsd, xsd_path);

          Namespace& tns (root.new_node<Namespace> (path, 1, 1));
          root.new_edge<Names> (ts, tns, ns.name ());
          root.new_edge<Names> (tns, n, name);

          // Add include to the original schema and enter into the
          // type-schema map.
          //
          root.new_edge<Includes> (s, ts, path);
          tsm[&dynamic_cast<Type&> (n)] = &ts;
        }
        else
          ++i;
      }
    }

    struct Type: Traversal::List,
                 Traversal::Complex,
                 Traversal::Member
    {
      Type (SemanticGraph::Schema& schema,
            SemanticGraph::Schema& root,
            Char const* by_value_key,
            TypeSchemaMap& tsm)
          : schema_ (schema),
            root_ (root),
            by_value_key_ (by_value_key),
            tsm_ (tsm)
      {
        *this >> names_ >> *this;
      }

      virtual Void
      traverse (SemanticGraph::List& l)
      {
        SemanticGraph::Type& t (l.argumented ().type ());

        Boolean weak (
          by_value_key_ == 0 ||
          !t.context ().count (by_value_key_) ||
          !t.context ().get<Boolean> (by_value_key_));

        set_dep (t, weak);
      }

      virtual Void
      traverse (SemanticGraph::Complex& c)
      {
        if (c.inherits_p ())
          set_dep (c.inherits ().base (), false);

        Traversal::Complex::names (c);
      }

      virtual Void
      traverse (SemanticGraph::Member& m)
      {
        SemanticGraph::Type& t (m.type ());

        Boolean weak (
          by_value_key_ == 0 ||
          !t.context ().count (by_value_key_) ||
          !t.context ().get<Boolean> (by_value_key_));

        set_dep (t, weak);
      }

    private:
      Void
      set_dep (SemanticGraph::Type& t, Boolean weak)
      {
        using namespace SemanticGraph;

        TypeSchemaMap::Iterator i (tsm_.find (&t));

        // If a type is not present in the map then it must be
        // a built-in type.
        //
        if (i == tsm_.end ())
          return;

        // Check if we already saw this type. Theoretically, it could
        // be that we need to upgrade the type of include from weak to
        // strong. But because inheritance is handled first, the type
        // in the set will already be with the right type.
        //
        if (type_set_.find (&t) != type_set_.end ())
          return;

        type_set_.insert (&t);

        Schema& s (*i->second);
        Path path (s.used_begin ()->path ());
        SemanticGraph::Uses* u;

        if (s.names_begin ()->name () == schema_.names_begin ()->name ())
          u = &root_.new_edge<Includes> (schema_, s, path);
        else
          u = &root_.new_edge<Imports> (schema_, s, path);

        if (weak)
          u->context().set ("weak", true);
      }

    private:
      SemanticGraph::Schema& schema_;
      SemanticGraph::Schema& root_;
      Char const* by_value_key_;
      TypeSchemaMap& tsm_;
      Containers::Set<SemanticGraph::Type*> type_set_;

      Traversal::Names names_;
    };
  }

  namespace Transformations
  {
    SchemaPerType::
    SchemaPerType (TypeSchemaTranslator& trans, Char const* by_value_key)
        : by_value_key_ (by_value_key), trans_ (trans)
    {
    }

    Schemas SchemaPerType::
    transform (SemanticGraph::Schema& root)
    {
      // Collect initial schema nodes.
      //
      Schemas schemas;
      SemanticGraph::Schema* xsd;

      {
        Traversal::Schema schema;
        Uses uses (schemas, xsd);

        schema >> uses >> schema;

        // Some twisted schemas do recusive inclusions.
        //
        root.context ().set ("xsd-frontend-schema-per-type-seen", true);

        schema.dispatch (root);
      }

      // wcerr << schemas.size () << " initial schema nodes" << endl;

      // Add the schema file names to the file set.
      //
      FileSet file_set;

      for (Schemas::Iterator i (schemas.begin ()); i != schemas.end (); ++i)
      {
        NarrowString s ((*i)->used_begin ()->path ().leaf ());

        Size p (s.rfind ('.'));
        file_set.insert (
          p != NarrowString::npos ? NarrowString (s, 0, p) : s);
      }

      // Process each schema node.
      //
      TypeSchemaMap tsm;

      for (Schemas::Iterator i (schemas.begin ()); i != schemas.end (); ++i)
      {
        process_schema (**i, root, *xsd, tsm, file_set, trans_);
      }

      // wcerr << tsm.size () << " type schema nodes" << endl;

      // Establish include/import dependencies. While at it add the
      // new schemas to the list which we will return.
      //
      for (TypeSchemaMap::Iterator i (tsm.begin ()); i != tsm.end (); ++i)
      {
        SemanticGraph::Schema& s (*i->second);
        Type t (s, root, by_value_key_, tsm);
        t.dispatch (*i->first);
        schemas.push_back (&s);
      }

      return schemas;
    }

    TypeSchemaTranslator::
    ~TypeSchemaTranslator ()
    {
    }
  }
}
