// file      : libxsd-frontend/transformations/enum-synthesis.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_TRANSFORMATIONS_ENUM_SYNTHESIS_HXX
#define LIBXSD_FRONTEND_TRANSFORMATIONS_ENUM_SYNTHESIS_HXX

#include <libxsd-frontend/types.hxx>

#include <libxsd-frontend/semantic-graph/elements.hxx> // Path
#include <libxsd-frontend/semantic-graph/schema.hxx>

#include <libxsd-frontend/export.hxx>

namespace XSDFrontend
{
  namespace Transformations
  {
    // This transformation replaces unions of one or more enumerations
    // with the same base with an equivalent synthesized enumeration.
    // This transformation assumes that there are no anonymous types.
    //
    class LIBXSD_FRONTEND_SYMEXPORT EnumSynthesis
    {
    public:
      void
      transform (SemanticGraph::Schema&, SemanticGraph::Path const&);
    };
  }
}

#endif // LIBXSD_FRONTEND_TRANSFORMATIONS_ENUM_SYNTHESIS_HXX
