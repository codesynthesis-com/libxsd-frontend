// file      : libxsd-frontend/traversal/any-attribute.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_TRAVERSAL_ANY_ATTRIBUTE_HXX
#define LIBXSD_FRONTEND_TRAVERSAL_ANY_ATTRIBUTE_HXX

#include <libxsd-frontend/traversal/elements.hxx>
#include <libxsd-frontend/semantic-graph/any-attribute.hxx>

namespace XSDFrontend
{
  namespace Traversal
  {
    typedef
    Node<SemanticGraph::AnyAttribute>
    AnyAttribute;
  }
}

#endif  // LIBXSD_FRONTEND_TRAVERSAL_ANY_ATTRIBUTE_HXX
