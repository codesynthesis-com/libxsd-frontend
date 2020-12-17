// file      : libxsd-frontend/semantic-graph/attribute-group.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_SEMANTIC_GRAPH_ATTRIBUTE_GROUP_HXX
#define LIBXSD_FRONTEND_SEMANTIC_GRAPH_ATTRIBUTE_GROUP_HXX

#include <libxsd-frontend/semantic-graph/elements.hxx>

#include <libxsd-frontend/export.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    class LIBXSD_FRONTEND_SYMEXPORT AttributeGroup: public virtual Scope
    {
    public:
      AttributeGroup (Path const& file,
                      unsigned long line,
                      unsigned long column);
    };
  }
}

#endif  // LIBXSD_FRONTEND_SEMANTIC_GRAPH_ATTRIBUTE_GROUP_HXX
