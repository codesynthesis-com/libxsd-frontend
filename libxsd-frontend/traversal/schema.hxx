// file      : libxsd-frontend/traversal/schema.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_TRAVERSAL_SCHEMA_HXX
#define LIBXSD_FRONTEND_TRAVERSAL_SCHEMA_HXX

#include <libxsd-frontend/traversal/elements.hxx>
#include <libxsd-frontend/semantic-graph/schema.hxx>

namespace XSDFrontend
{
  namespace Traversal
  {
    //
    //
    struct Uses: Edge<SemanticGraph::Uses>
    {
      Uses ()
      {
      }

      Uses (NodeBase& n)
      {
        node_traverser (n);
      }

      virtual void
      traverse (Type& e)
      {
        dispatch (e.schema ());
      }
    };

    //
    //
    struct Implies: Edge<SemanticGraph::Implies>
    {
      Implies ()
      {
      }

      Implies (NodeBase& n)
      {
        node_traverser (n);
      }

      virtual void
      traverse (Type& e)
      {
        dispatch (e.schema ());
      }
    };


    //
    //
    struct Sources: Edge<SemanticGraph::Sources>
    {
      Sources ()
      {
      }

      Sources (NodeBase& n)
      {
        node_traverser (n);
      }

      virtual void
      traverse (Type& e)
      {
        dispatch (e.schema ());
      }
    };


    //
    //
    struct Includes: Edge<SemanticGraph::Includes>
    {
      Includes ()
      {
      }

      Includes (NodeBase& n)
      {
        node_traverser (n);
      }

      virtual void
      traverse (Type& e)
      {
        dispatch (e.schema ());
      }
    };


    //
    //
    struct Imports: Edge<SemanticGraph::Imports>
    {
      Imports ()
      {
      }

      Imports (NodeBase& n)
      {
        node_traverser (n);
      }

      virtual void
      traverse (Type& e)
      {
        dispatch (e.schema ());
      }
    };


    //
    //
    struct Schema: ScopeTemplate<SemanticGraph::Schema>
    {
      virtual void
      traverse (Type& s)
      {
        pre (s);

        iterate_and_dispatch (
          s.uses_begin (), s.uses_end (), edge_traverser ());

        names (s);

        post (s);
      }

      virtual void
      pre (Type&)
      {
      }

      virtual void
      post (Type&)
      {
      }
    };
  }
}

#endif  // LIBXSD_FRONTEND_TRAVERSAL_SCHEMA_HXX
