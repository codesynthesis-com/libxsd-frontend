// file      : libxsd-frontend/semantic-graph/enumeration.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_SEMANTIC_GRAPH_ENUMERATION_HXX
#define LIBXSD_FRONTEND_SEMANTIC_GRAPH_ENUMERATION_HXX

#include <libxsd-frontend/semantic-graph/elements.hxx>
#include <libxsd-frontend/semantic-graph/complex.hxx>

#include <libxsd-frontend/export.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    class LIBXSD_FRONTEND_SYMEXPORT Enumeration: public virtual Complex
    {
    public:
      Enumeration (Path const& file, unsigned long line, unsigned long column);
    };


    class LIBXSD_FRONTEND_SYMEXPORT Enumerator: public virtual Instance
    {
    public:
      Enumerator (Path const& file, unsigned long line, unsigned long column);
    };
  }
}

#endif  // LIBXSD_FRONTEND_SEMANTIC_GRAPH_ENUMERATION_HXX
