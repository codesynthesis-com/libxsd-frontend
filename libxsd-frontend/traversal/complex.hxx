// file      : libxsd-frontend/traversal/complex.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_TRAVERSAL_COMPLEX_HXX
#define LIBXSD_FRONTEND_TRAVERSAL_COMPLEX_HXX

#include <libxsd-frontend/traversal/elements.hxx>
#include <libxsd-frontend/semantic-graph/complex.hxx>

#include <libxsd-frontend/export.hxx>

namespace XSDFrontend
{
  namespace Traversal
  {
    struct LIBXSD_FRONTEND_SYMEXPORT Complex:
      ScopeTemplate<SemanticGraph::Complex>
    {
      virtual void
      traverse (Type&);

      virtual void
      pre (Type&);

      virtual void
      name (Type&);

      virtual void
      inherits (Type&);

      void
      inherits (Type&, EdgeDispatcher&);

      virtual void
      contains_compositor (Type&);

      void
      contains_compositor (Type&, EdgeDispatcher&);

      virtual void
      post (Type&);
    };
  }
}

#endif  // LIBXSD_FRONTEND_TRAVERSAL_COMPLEX_HXX
