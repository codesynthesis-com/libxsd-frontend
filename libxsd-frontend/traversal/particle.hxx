// file      : libxsd-frontend/traversal/particle.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_TRAVERSAL_PARTICLE_HXX
#define LIBXSD_FRONTEND_TRAVERSAL_PARTICLE_HXX

#include <libxsd-frontend/traversal/elements.hxx>
#include <libxsd-frontend/semantic-graph/particle.hxx>

#include <libxsd-frontend/export.hxx>

namespace XSDFrontend
{
  namespace Traversal
  {
    struct LIBXSD_FRONTEND_SYMEXPORT Particle: Node<SemanticGraph::Particle>
    {
      virtual void
      traverse (Type&);

      virtual void
      pre (Type&);

      virtual void
      post (Type&);
    };
  }
}

#endif  // LIBXSD_FRONTEND_TRAVERSAL_PARTICLE_HXX
