// file      : libxsd-frontend/generators/dependencies.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_GENERATORS_DEPENDENCIES_HXX
#define LIBXSD_FRONTEND_GENERATORS_DEPENDENCIES_HXX

#include <vector>

#include <libxsd-frontend/types.hxx>

#include <libxsd-frontend/semantic-graph/elements.hxx> // Path
#include <libxsd-frontend/semantic-graph/schema.hxx>

#include <libxsd-frontend/export.hxx>

namespace XSDFrontend
{
  namespace Generators
  {
    // Return the list of included/imported schema paths (transitively and
    // including the main schema file) which can then be used to produce
    // make dependencies, etc.
    //
    class LIBXSD_FRONTEND_SYMEXPORT Dependencies
    {
    public:
      std::vector<SemanticGraph::Path>
      generate (SemanticGraph::Schema&, SemanticGraph::Path const&);
    };
  }
}

#endif // LIBXSD_FRONTEND_GENERATORS_DEPENDENCIES_HXX
