// file      : libxsd-frontend/traversal/union.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_TRAVERSAL_UNION_HXX
#define LIBXSD_FRONTEND_TRAVERSAL_UNION_HXX

#include <libxsd-frontend/traversal/elements.hxx>
#include <libxsd-frontend/semantic-graph/union.hxx>

#include <libxsd-frontend/export.hxx>

namespace XSDFrontend
{
  namespace Traversal
  {
    struct LIBXSD_FRONTEND_SYMEXPORT Union: Node<SemanticGraph::Union>
    {
      virtual void
      traverse (Type&);

      virtual void
      pre (Type&);

      virtual void
      argumented (Type&);

      virtual void
      argumented (Type&, EdgeDispatcher& d);

      virtual void
      name (Type&);

      virtual void
      post (Type&);
    };
  }
}

#endif  // LIBXSD_FRONTEND_TRAVERSAL_UNION_HXX
