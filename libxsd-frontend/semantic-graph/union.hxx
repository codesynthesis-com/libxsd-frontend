// file      : libxsd-frontend/semantic-graph/union.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_SEMANTIC_GRAPH_UNION_HXX
#define LIBXSD_FRONTEND_SEMANTIC_GRAPH_UNION_HXX

#include <libxsd-frontend/semantic-graph/elements.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    class Union: public virtual Specialization
    {
    public:
      Union (Path const& file, unsigned long line, unsigned long column);
    };
  }
}

#endif  // LIBXSD_FRONTEND_SEMANTIC_GRAPH_UNION_HXX
