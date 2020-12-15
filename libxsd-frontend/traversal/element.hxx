// file      : libxsd-frontend/traversal/element.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_TRAVERSAL_ELEMENT_HXX
#define LIBXSD_FRONTEND_TRAVERSAL_ELEMENT_HXX

#include <libxsd-frontend/traversal/elements.hxx>
#include <libxsd-frontend/semantic-graph/element.hxx>

namespace XSDFrontend
{
  namespace Traversal
  {
    struct Element : Node<SemanticGraph::Element>
    {
      virtual void
      traverse (Type&);

      virtual void
      pre (Type&);

      virtual void
      belongs (Type&, EdgeDispatcher&);

      virtual void
      belongs (Type&);

      virtual void
      name (Type&);

      virtual void
      post (Type&);
    };
  }
}

#endif  // LIBXSD_FRONTEND_TRAVERSAL_ELEMENT_HXX
