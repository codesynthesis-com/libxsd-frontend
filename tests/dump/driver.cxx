// file      : tests/dump/driver.cxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2006-2010 Code Synthesis Tools CC
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <cult/types.hxx>

#include <xsd-frontend/parser.hxx>
#include <xsd-frontend/transformations/anonymous.hxx>

#include <xsd-frontend/semantic-graph.hxx>
#include <xsd-frontend/traversal.hxx>

#include <iostream>

using namespace Cult::Types;
using namespace XSDFrontend;

using std::wcerr;
using std::wcout;
using std::endl;

UnsignedLong indent = 0;

std::wostream&
ind (std::wostream& os)
{
  for (UnsignedLong n (0); n < indent; ++n)
    os << L"  ";

  return os;
}

namespace
{
  typedef Cult::Types::WideString String;

  // Nameable which is named in the namespace scope.
  //
  String
  ref_name (SemanticGraph::Nameable& n)
  {
    String const& scope (n.scope ().name ());

    return scope + (scope.empty () ? L"" : L"#") + n.name ();
  }

  struct List: Traversal::List
  {
    virtual Void
    traverse (Type& l)
    {
      if (l.annotated ())
        wcout << ind << "<" << l.annotation ().documentation () << ">"
              << endl;

      wcout << ind << "list " <<
        (l.named () ? l.name () : String ("<anonymous>"))
            << " " << ref_name (l.argumented ().type ()) << endl;
    }
  };

  struct Union: Traversal::Union
  {
    virtual Void
    traverse (Type& u)
    {
      if (u.annotated ())
        wcout << ind << "<" << u.annotation ().documentation () << ">"
              << endl;

      wcout << ind << "union " <<
        (u.named () ? u.name () : String ("<anonymous>")) << endl;
    }
  };

  struct Enumerator: Traversal::Enumerator
  {
    virtual Void
    traverse (Type& e)
    {
      if (e.annotated ())
        wcout << ind << "<" << e.annotation ().documentation () << ">"
              << endl;

      wcout << ind << "enumerator " << e.name () << endl;
    }
  };

  struct Enumeration: Traversal::Enumeration
  {
    virtual Void
    traverse (Type& e)
    {
      if (e.annotated ())
        wcout << ind << "<" << e.annotation ().documentation () << ">"
              << endl;

      wcout << ind << "enumeration " <<
        (e.named () ? e.name () : String ("<anonymous>")) << ": " <<
        ref_name (e.inherits ().base ()) << endl
            << ind << "{" << endl;

      indent++;
      Traversal::Enumeration::traverse (e);
      indent--;

      wcout << ind << "}" << endl;
    }
  };

  struct ContainsParticle: Traversal::ContainsParticle
  {
    virtual Void
    traverse (Type& cp)
    {
      wcout << ind << "[" << cp.min () << ", ";

      if (cp.max () == 0)
        wcout << "unbounded] ";
      else
        wcout << cp.max () << "] ";

      Traversal::ContainsParticle::traverse (cp);
    }
  };

  struct ContainsCompositor: Traversal::ContainsCompositor
  {
    virtual Void
    traverse (Type& cc)
    {
      wcout << ind << "[" << cc.min () << ", ";

      if (cc.max () == 0)
        wcout << "unbounded] ";
      else
        wcout << cc.max () << "] ";

      Traversal::ContainsCompositor::traverse (cc);
    }
  };

  struct Compositor: Traversal::All,
                     Traversal::Choice,
                     Traversal::Sequence
  {
    virtual Void
    traverse (SemanticGraph::All& a)
    {
      wcout << "all" << endl
            << ind << "{" << endl;

      indent++;

      Traversal::All::traverse (a);

      indent--;

      wcout << ind << "}" << endl;
    }

    virtual Void
    traverse (SemanticGraph::Choice& c)
    {
      wcout << "choice" << endl
            << ind << "{" << endl;

      indent++;

      Traversal::Choice::traverse (c);

      indent--;

      wcout << ind << "}" << endl;
    }

    virtual Void
    traverse (SemanticGraph::Sequence& s)
    {
      wcout << "sequence" << endl
            << ind << "{" << endl;

      indent++;

      Traversal::Sequence::traverse (s);

      indent--;

      wcout << ind << "}" << endl;
    }
  };

  struct Attribute: Traversal::Attribute
  {
    virtual Void
    traverse (Type& a)
    {
      if (a.annotated ())
        wcout << ind << "<" << a.annotation ().documentation () << ">"
              << endl;

      wcout << ind << (a.optional () ? "optional" : "required")
            << " attribute " << a.name ();

      SemanticGraph::Type& t (a.type ());

      if (t.named ())
        wcout << " " << ref_name (t) << endl;
      else
      {
        wcout << endl
              << ind << "{" << endl;
        indent++;

        belongs (a);

        indent--;
        wcout << ind << "}" << endl;
      }
    }
  };

  struct AnyAttribute: Traversal::AnyAttribute
  {
    virtual Void
    traverse (Type& a)
    {
      if (a.annotated ())
        wcout << ind << "<" << a.annotation ().documentation () << ">"
              << endl;

      wcout << ind << "any-attribute '" << a.name () << "'" << endl;
    }
  };

  struct Element: Traversal::Element
  {
    virtual Void
    traverse (Type& e)
    {
      wcout << "element " << e.name ();

      SemanticGraph::Type& t (e.type ());

      if (t.named ())
        wcout << " " << ref_name (t) << endl;
      else
      {
        wcout << endl
              << ind << "{" << endl;
        indent++;

        belongs (e);

        indent--;
        wcout << ind << "}" << endl;
      }
    }
  };

  struct ElementFlat: Traversal::Element
  {
    virtual Void
    traverse (Type& e)
    {
      if (e.annotated ())
        wcout << ind << "<" << e.annotation ().documentation () << ">"
              << endl;

      wcout << ind << "element " << e.name () << endl;
    }
  };

  struct Any: Traversal::Any
  {
    virtual Void
    traverse (Type& a)
    {
      wcout << "any '" << a.name () << "'" << endl;
    }
  };

  struct AnyFlat: Traversal::Any
  {
    virtual Void
    traverse (Type& a)
    {
      if (a.annotated ())
        wcout << ind << "<" << a.annotation ().documentation () << ">"
              << endl;

      wcout << ind << "any '" << a.name () << "'" << endl;
    }
  };

  struct Complex: Traversal::Complex
  {
    virtual Void
    traverse (Type& c)
    {
      // Anonymous type definition can recursively refer to itself.
      //
      if (c.context ().count ("seen"))
      {
        wcout << ind << "complex <recursive-anonymous>" << endl;
        return;
      }

      c.context ().set ("seen", true);

      if (c.annotated ())
        wcout << ind << "<" << c.annotation ().documentation () << ">"
              << endl;

      wcout << ind << "complex " <<
        (c.named () ? c.name () : String ("<anonymous>"));

      if (c.inherits_p ())
        wcout << ": " << ref_name (c.inherits ().base ());

      wcout << endl
            << ind << "{" << endl;
      indent++;

      Traversal::Complex::traverse (c);

      indent--;
      wcout << ind << "}" << endl;

      c.context ().remove ("seen");
    }
  };

  struct GlobalAttribute: Traversal::Attribute
  {
    virtual Void
    traverse (Type& a)
    {
      if (a.annotated ())
        wcout << ind << "<" << a.annotation ().documentation () << ">"
              << endl;

      wcout << ind << "attribute " << a.name ();

      SemanticGraph::Type& t (a.type ());

      if (t.named ())
        wcout << " " << ref_name (t) << endl;
      else
      {
        wcout << endl
              << ind << "{" << endl;
        indent++;

        belongs (a);

        indent--;
        wcout << ind << "}" << endl;
      }
    }
  };

  struct GlobalElement: Traversal::Element
  {
    virtual Void
    traverse (Type& e)
    {
      if (e.annotated ())
        wcout << ind << "<" << e.annotation ().documentation () << ">"
              << endl;

      wcout << ind << "element " << e.name ();

      SemanticGraph::Type& t (e.type ());

      if (t.named ())
        wcout << " " << ref_name (t) << endl;
      else
      {
        wcout << endl
              << ind << "{" << endl;
        indent++;

        belongs (e);

        indent--;
        wcout << ind << "}" << endl;
      }
    }
  };

  struct Namespace: Traversal::Namespace
  {
    virtual Void
    traverse (Type& n)
    {
      wcout << ind << "namespace " << n.name () << endl
            << ind << "{" << endl;
      indent++;
      Traversal::Namespace::traverse (n);
      indent--;
      wcout << ind << "}" << endl;
    }
  };

  // Go into implied/included/imported schemas while making sure
  // we don't recurse forever.
  //
  struct Uses: Traversal::Imports,
               Traversal::Includes,
               Traversal::Sources
               //Traversal::Implies @@ Need a --with-implies option
  {
    virtual Void
    traverse (SemanticGraph::Imports& i)
    {
      if (traverse_uses (i, "imports"))
        Traversal::Imports::traverse (i);
    }

    virtual Void
    traverse (SemanticGraph::Includes& i)
    {
      if (traverse_uses (i, "includes"))
        Traversal::Includes::traverse (i);
    }

    virtual Void
    traverse (SemanticGraph::Sources& s)
    {
      if (traverse_uses (s, "sources"))
        Traversal::Sources::traverse (s);
    }

    /*
    virtual Void
    traverse (SemanticGraph::Implies& i)
    {
      if (traverse_uses (i, "implies"))
        Traversal::Implies::traverse (i);
    }
    */

    Boolean
    traverse_uses (SemanticGraph::Uses& u, String const& type)
    {
      SemanticGraph::Schema& s (u.schema ());

      if (s.context ().count ("seen"))
      {
        wcout << ind << "recursively " << type << " " << u.path () << endl;
        return false;
      }

      s.context ().set ("seen", true);

      if (s.annotated ())
        wcout << ind << "<" << s.annotation ().documentation () << ">" << endl;

      wcout << ind << type << " " << u.path () << endl;

      return true;
    }
  };

  struct Schema: Traversal::Schema
  {
    virtual Void
    traverse (Type& s)
    {
      wcout << ind << "{" << endl;
      indent++;
      Traversal::Schema::traverse (s);
      indent--;
      wcout << ind << "}" << endl;
    }
  };
}

struct AnonymousNameTranslator: Transformations::AnonymousNameTranslator
{
  virtual WideString
  translate (WideString const& file,
             WideString const& ns,
             WideString const& name,
             WideString const& xpath)
  {
    wcout << "anonymous: " << file << " " << ns << " " << name << " " <<
      xpath << endl;

    return name;
  }
};


Int
main (Int argc, Char* argv[])
{
  try
  {
    if (argc < 2)
    {
      wcerr << argv[0] << ": error: no input file." << endl;
      return 1;
    }

    // Parse options.
    //
    Int i (1);
    Boolean anon (false);

    for (; i < argc; ++i)
    {
      if (argv[i] == NarrowString ("--anonymous"))
        anon = true;
      else
        break;
    }

    // Parse schema.
    //
    SemanticGraph::Path path (argv[i], boost::filesystem::native);

    Parser parser (true, false, true);
    Evptr<SemanticGraph::Schema> tu (parser.parse (path));

    //
    //
    if (anon)
    {
      try
      {
        AnonymousNameTranslator transl;
        Transformations::Anonymous transf (transl);
        transf.transform (*tu, path, true);
      }
      catch (Transformations::Anonymous::Failed const&)
      {
        // Diagnostics has already been issued.
        //
        return 1;
      }
    }

    //
    //
    Schema schema;
    Uses uses;

    schema >> uses >> schema;

    Traversal::Names schema_names;
    Namespace ns;
    Traversal::Names ns_names;

    schema >> schema_names >> ns >> ns_names;

    //
    //
    List list;
    Union union_;
    Complex complex;
    Enumeration enumeration;
    GlobalElement global_element;
    GlobalAttribute global_attribute;

    Traversal::Names complex_names;
    Traversal::Names enumeration_names;
    ContainsCompositor contains_compositor;

    ns_names >> list;
    ns_names >> union_;
    ns_names >> complex;
    ns_names >> enumeration;
    ns_names >> global_attribute;
    ns_names >> global_element;

    complex >> complex_names;
    complex >> contains_compositor;

    enumeration >> enumeration_names;

    //
    //
    Compositor compositor;
    ContainsParticle contains_particle;

    contains_compositor >> compositor;
    compositor >> contains_particle >> compositor;

    //
    //
    Any any;
    AnyFlat any_flat;
    Element element;
    ElementFlat element_flat;
    Attribute attribute;
    AnyAttribute any_attribute;
    Traversal::Belongs belongs;

    element >> belongs;
    attribute >> belongs;

    global_element >> belongs;
    global_attribute >> belongs;

    complex_names >> attribute;
    complex_names >> any_attribute;
    complex_names >> any_flat;
    complex_names >> element_flat;

    contains_particle >> any;
    contains_particle >> element;

    belongs >> list;
    belongs >> union_;
    belongs >> complex;
    belongs >> enumeration;

    //
    //
    Enumerator enumerator;
    enumeration_names >> enumerator;

    //
    //
    if (tu->annotated ())
      wcout << ind << "<" << tu->annotation ().documentation () << ">"
            << endl;

    wcout << ind << "primary" << endl;
    tu->context ().set ("seen", true);
    schema.dispatch (*tu);

    return 0;
  }
  catch (InvalidSchema const&)
  {
    // Diagnostic has already been issued.
  }
  catch (SemanticGraph::InvalidPath const&)
  {
    wcerr << argv[0] << ": error: '" << argv[1] << "' is not a valid "
      << "filesystem path" << endl;
  }

  return 1;
}
