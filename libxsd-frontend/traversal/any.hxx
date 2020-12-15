// file      : libxsd-frontend/traversal/any.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_TRAVERSAL_ANY_HXX
#define LIBXSD_FRONTEND_TRAVERSAL_ANY_HXX

#include <libxsd-frontend/traversal/elements.hxx>
#include <libxsd-frontend/semantic-graph/any.hxx>

namespace XSDFrontend
{
  namespace Traversal
  {
    typedef
    Node<SemanticGraph::Any>
    Any;
  }
}

#endif  // LIBXSD_FRONTEND_TRAVERSAL_ANY_HXX
