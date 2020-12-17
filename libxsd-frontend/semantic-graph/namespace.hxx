// file      : libxsd-frontend/semantic-graph/namespace.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_SEMANTIC_GRAPH_NAMESPACE_HXX
#define LIBXSD_FRONTEND_SEMANTIC_GRAPH_NAMESPACE_HXX

#include <libxsd-frontend/semantic-graph/elements.hxx>

#include <libxsd-frontend/export.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    class LIBXSD_FRONTEND_SYMEXPORT Namespace : public virtual Scope
    {
    public:
      Namespace (Path const& file, unsigned long line, unsigned long column);

      void
      add_edge_right (BelongsToNamespace&) {}

      using Scope::add_edge_right;
    };
  }
}

#endif  // LIBXSD_FRONTEND_SEMANTIC_GRAPH_NAMESPACE_HXX
