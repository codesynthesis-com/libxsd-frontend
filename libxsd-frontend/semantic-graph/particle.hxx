// file      : libxsd-frontend/semantic-graph/particle.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_SEMANTIC_GRAPH_PARTICLE_HXX
#define LIBXSD_FRONTEND_SEMANTIC_GRAPH_PARTICLE_HXX

#include <libxsd-frontend/semantic-graph/elements.hxx>

#include <libxsd-frontend/export.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    //
    //
    class Particle;
    class Compositor;


    //
    //
    class LIBXSD_FRONTEND_SYMEXPORT ContainsParticle: public virtual Edge
    {
    public:
      Particle&
      particle () const
      {
        return *particle_;
      }

      Compositor&
      compositor () const
      {
        return *compositor_;
      }

    public:
      unsigned long
      min () const
      {
        return min_;
      }

      unsigned long
      max () const
      {
        return max_;
      }

    public:
      ContainsParticle (unsigned long min, unsigned long max);

      void
      set_left_node (Compositor& n)
      {
        compositor_ = &n;
      }

      void
      set_right_node (Particle& n)
      {
        particle_ = &n;
      }

      void
      clear_left_node (Compositor& n)
      {
        assert (compositor_ == &n);
        compositor_ = 0;
      }

      void
      clear_right_node (Particle& n)
      {
        assert (particle_ == &n);
        particle_ = 0;
      }

    private:
      Particle* particle_;
      Compositor* compositor_;
      unsigned long min_, max_;
    };

    //
    //
    class LIBXSD_FRONTEND_SYMEXPORT Particle: public virtual Node
    {
    public:
      bool
      contained_particle_p ()
      {
        return contained_particle_ != 0;
      }

      ContainsParticle&
      contained_particle ()
      {
        assert (contained_particle_ != 0);
        return *contained_particle_;
      }

    public:
      unsigned long
      min () const
      {
        assert (contained_particle_ != 0);
        return contained_particle_->min ();
      }

      unsigned long
      max () const
      {
        assert (contained_particle_ != 0);
        return contained_particle_->max ();
      }

    public:
      Particle ();

      void
      add_edge_right (ContainsParticle& e)
      {
        contained_particle_ = &e;
      }

      void
      remove_edge_right (ContainsParticle& e)
      {
        assert (contained_particle_ == &e);
        contained_particle_ = 0;
      }

    private:
      ContainsParticle* contained_particle_;
    };
  }
}

#endif  // LIBXSD_FRONTEND_SEMANTIC_GRAPH_PARTICLE_HXX
