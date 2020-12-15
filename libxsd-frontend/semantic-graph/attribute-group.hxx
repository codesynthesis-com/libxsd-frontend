// file      : libxsd-frontend/semantic-graph/attribute-group.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_SEMANTIC_GRAPH_ATTRIBUTE_GROUP_HXX
#define LIBXSD_FRONTEND_SEMANTIC_GRAPH_ATTRIBUTE_GROUP_HXX

#include <libxsd-frontend/semantic-graph/elements.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    class AttributeGroup: public virtual Scope
    {
    public:
      AttributeGroup (Path const& file,
                      unsigned long line,
                      unsigned long column);
    };
  }
}

#endif  // LIBXSD_FRONTEND_SEMANTIC_GRAPH_ATTRIBUTE_GROUP_HXX
