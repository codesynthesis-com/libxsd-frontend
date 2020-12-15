// file      : libxsd-frontend/traversal/namespace.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_TRAVERSAL_NAMESPACE_HXX
#define LIBXSD_FRONTEND_TRAVERSAL_NAMESPACE_HXX

#include <libxsd-frontend/traversal/elements.hxx>
#include <libxsd-frontend/semantic-graph/namespace.hxx>

namespace XSDFrontend
{
  namespace Traversal
  {
    struct Namespace: ScopeTemplate<SemanticGraph::Namespace>
    {
      virtual void
      traverse (Type& m)
      {
        pre (m);
        name (m);
        names (m);
        post (m);
      }

      virtual void
      pre (Type&)
      {
      }

      virtual void
      name (Type&)
      {
      }

      virtual void
      post (Type&)
      {
      }
    };
  }
}

#endif  // LIBXSD_FRONTEND_TRAVERSAL_NAMESPACE_HXX
