// file      : xsd-frontend/semantic-graph/attribute-group.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef XSD_FRONTEND_SEMANTIC_GRAPH_ATTRIBUTE_GROUP_HXX
#define XSD_FRONTEND_SEMANTIC_GRAPH_ATTRIBUTE_GROUP_HXX

#include <xsd-frontend/semantic-graph/elements.hxx>

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

#endif  // XSD_FRONTEND_SEMANTIC_GRAPH_ATTRIBUTE_GROUP_HXX
