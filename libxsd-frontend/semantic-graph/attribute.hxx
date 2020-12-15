// file      : libxsd-frontend/semantic-graph/attribute.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_SEMANTIC_GRAPH_ATTRIBUTE_HXX
#define LIBXSD_FRONTEND_SEMANTIC_GRAPH_ATTRIBUTE_HXX

#include <libxsd-frontend/semantic-graph/elements.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    class Attribute: public virtual Member
    {
    public:
      bool
      optional_p () const
      {
        return optional_;
      }

    public:
      Attribute (Path const& file,
                 unsigned long line,
                 unsigned long column,
                 bool optional,
                 bool global,
                 bool qualified);
    private:
      bool optional_;
    };
  }
}

#endif  // LIBXSD_FRONTEND_SEMANTIC_GRAPH_ATTRIBUTE_HXX
