// file      : libxsd-frontend/traversal/compositors.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_TRAVERSAL_COMPOSITORS_HXX
#define LIBXSD_FRONTEND_TRAVERSAL_COMPOSITORS_HXX

#include <libxsd-frontend/traversal/elements.hxx>
#include <libxsd-frontend/semantic-graph/compositors.hxx>

namespace XSDFrontend
{
  namespace Traversal
  {
    //
    //
    struct ContainsParticle: Edge<SemanticGraph::ContainsParticle>
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
    struct ContainsCompositor: Edge<SemanticGraph::ContainsCompositor>
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
    struct Compositor : Node<SemanticGraph::Compositor>
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
    struct All : Node<SemanticGraph::All>
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
    struct Choice : Node<SemanticGraph::Choice>
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
    struct Sequence : Node<SemanticGraph::Sequence>
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
