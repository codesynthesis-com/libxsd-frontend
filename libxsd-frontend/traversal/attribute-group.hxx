// file      : libxsd-frontend/traversal/attribute-group.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_TRAVERSAL_ATTRIBUTE_GROUP_HXX
#define LIBXSD_FRONTEND_TRAVERSAL_ATTRIBUTE_GROUP_HXX

#include <libxsd-frontend/traversal/elements.hxx>
#include <libxsd-frontend/semantic-graph/attribute-group.hxx>

namespace XSDFrontend
{
  namespace Traversal
  {
    struct AttributeGroup: ScopeTemplate<SemanticGraph::AttributeGroup>
    {
      virtual void
      traverse (Type&);

      virtual void
      pre (Type&);

      virtual void
      post (Type&);
    };
  }
}

#endif  // LIBXSD_FRONTEND_TRAVERSAL_ATTRIBUTE_GROUP_HXX
