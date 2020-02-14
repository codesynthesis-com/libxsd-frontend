// file      : xsd-frontend/traversal/particle.cxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <xsd-frontend/traversal/particle.hxx>

namespace XSDFrontend
{
  namespace Traversal
  {
    // Particle
    //
    void Particle::
    traverse (Type& c)
    {
      pre (c);
      post (c);
    }

    void Particle::
    pre (Type&)
    {
    }

    void Particle::
    post (Type&)
    {
    }
  }
}
