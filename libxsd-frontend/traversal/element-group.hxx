// file      : libxsd-frontend/traversal/element-group.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_TRAVERSAL_ELEMENT_GROUP_HXX
#define LIBXSD_FRONTEND_TRAVERSAL_ELEMENT_GROUP_HXX

#include <libxsd-frontend/traversal/elements.hxx>
#include <libxsd-frontend/semantic-graph/element-group.hxx>

namespace XSDFrontend
{
  namespace Traversal
  {
    struct ElementGroup: ScopeTemplate<SemanticGraph::ElementGroup>
    {
      virtual void
      traverse (Type&);

      virtual void
      pre (Type&);

      virtual void
      contains_compositor (Type&);

      virtual void
      contains_compositor (Type&, EdgeDispatcher&);

      virtual void
      post (Type&);
    };
  }
}

#endif  // LIBXSD_FRONTEND_TRAVERSAL_ELEMENT_GROUP_HXX
