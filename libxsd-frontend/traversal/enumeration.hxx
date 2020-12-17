// file      : libxsd-frontend/traversal/enumeration.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_TRAVERSAL_ENUMERATION_HXX
#define LIBXSD_FRONTEND_TRAVERSAL_ENUMERATION_HXX

#include <libxsd-frontend/traversal/elements.hxx>
#include <libxsd-frontend/semantic-graph/enumeration.hxx>

#include <libxsd-frontend/export.hxx>

namespace XSDFrontend
{
  namespace Traversal
  {
    struct LIBXSD_FRONTEND_SYMEXPORT Enumeration:
      ScopeTemplate<SemanticGraph::Enumeration>
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
      post (Type&);
    };

    struct LIBXSD_FRONTEND_SYMEXPORT Enumerator:
      Node<SemanticGraph::Enumerator>
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

#endif  // LIBXSD_FRONTEND_TRAVERSAL_ENUMERATION_HXX
