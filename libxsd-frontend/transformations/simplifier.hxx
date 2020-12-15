// file      : libxsd-frontend/transformations/simplifier.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_TRANSFORMATIONS_SIMPLIFIER_HXX
#define LIBXSD_FRONTEND_TRANSFORMATIONS_SIMPLIFIER_HXX

#include <libxsd-frontend/types.hxx>

#include <libxsd-frontend/semantic-graph/elements.hxx> // Path
#include <libxsd-frontend/semantic-graph/schema.hxx>

namespace XSDFrontend
{
  namespace Transformations
  {
    // This transformation performs various schema simplifications
    // (e.g., removing empty compositors, etc). This transformation
    // assumes that there are no anonymous types.
    //
    class Simplifier
    {
    public:
      void
      transform (SemanticGraph::Schema&, SemanticGraph::Path const&);
    };
  }
}

#endif // LIBXSD_FRONTEND_TRANSFORMATIONS_SIMPLIFIER_HXX
