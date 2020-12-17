// file      : libxsd-frontend/transformations/restriction.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_TRANSFORMATIONS_RESTRICTION_HXX
#define LIBXSD_FRONTEND_TRANSFORMATIONS_RESTRICTION_HXX

#include <libxsd-frontend/types.hxx>

#include <libxsd-frontend/semantic-graph/elements.hxx> // Path
#include <libxsd-frontend/semantic-graph/schema.hxx>

#include <libxsd-frontend/export.hxx>

namespace XSDFrontend
{
  namespace Transformations
  {
    // This transformation performs two major tasks. It transfers omitted
    // attribute declarations from the base to derived-by-restriction type
    // and establishes correspondence between particles and compositors by
    // adding the "xsd-frontend-restriction-correspondence" key-value pair
    // in the context that contains a pointer to the corresponding particle
    // or compositor in the base. Note that restriction of anyType is
    // a special case and is not handled by this transformation.
    //
    class LIBXSD_FRONTEND_SYMEXPORT Restriction
    {
    public:
      struct Failed {};

      void
      transform (SemanticGraph::Schema&, SemanticGraph::Path const&);
    };
  }
}

#endif // LIBXSD_FRONTEND_TRANSFORMATIONS_RESTRICTION_HXX
