// file      : libxsd-frontend/traversal/compositors.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_TRAVERSAL_COMPOSITORS_HXX
#define LIBXSD_FRONTEND_TRAVERSAL_COMPOSITORS_HXX

#include <libxsd-frontend/traversal/elements.hxx>
#include <libxsd-frontend/semantic-graph/compositors.hxx>

#include <libxsd-frontend/export.hxx>

namespace XSDFrontend
{
  namespace Traversal
  {
    //
    //
    struct LIBXSD_FRONTEND_SYMEXPORT ContainsParticle:
      Edge<SemanticGraph::ContainsParticle>
    {
      ContainsParticle ()
      {
      }

      ContainsParticle (NodeBase& n)
      {
        node_traverser (n);
      }

      virtual void
      traverse (Type&);
    };


    //
    //
    struct LIBXSD_FRONTEND_SYMEXPORT ContainsCompositor:
      Edge<SemanticGraph::ContainsCompositor>
    {
      ContainsCompositor ()
      {
      }

      ContainsCompositor (NodeBase& n)
      {
        node_traverser (n);
      }

      virtual void
      traverse (Type&);
    };

    //
    //
    struct LIBXSD_FRONTEND_SYMEXPORT Compositor:
      Node<SemanticGraph::Compositor>
    {
      virtual void
      traverse (Type&);

      virtual void
      pre (Type&);

      virtual void
      contains (Type&);

      virtual void
      contains (Type&, EdgeDispatcher&);

      virtual void
      post (Type&);
    };


    //
    //
    struct LIBXSD_FRONTEND_SYMEXPORT All: Node<SemanticGraph::All>
    {
      virtual void
      traverse (Type&);

      virtual void
      pre (Type&);

      virtual void
      contains (Type&);

      virtual void
      contains (Type&, EdgeDispatcher&);

      virtual void
      post (Type&);
    };


    //
    //
    struct LIBXSD_FRONTEND_SYMEXPORT Choice: Node<SemanticGraph::Choice>
    {
      virtual void
      traverse (Type&);

      virtual void
      pre (Type&);

      virtual void
      contains (Type&);

      virtual void
      contains (Type&, EdgeDispatcher&);

      virtual void
      post (Type&);
    };


    //
    //
    struct LIBXSD_FRONTEND_SYMEXPORT Sequence: Node<SemanticGraph::Sequence>
    {
      virtual void
      traverse (Type&);

      virtual void
      pre (Type&);

      virtual void
      contains (Type&);

      virtual void
      contains (Type&, EdgeDispatcher&);

      virtual void
      post (Type&);
    };
  }
}

#endif  // LIBXSD_FRONTEND_TRAVERSAL_COMPOSITORS_HXX
