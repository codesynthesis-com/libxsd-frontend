// file      : libxsd-frontend/semantic-graph/element.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_SEMANTIC_GRAPH_ELEMENT_HXX
#define LIBXSD_FRONTEND_SEMANTIC_GRAPH_ELEMENT_HXX

#include <libxsd-frontend/semantic-graph/elements.hxx>
#include <libxsd-frontend/semantic-graph/particle.hxx>

#include <libxsd-frontend/export.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    class Element;

    class Substitutes: public virtual Edge
    {
    public:
      Element&
      substitution () const
      {
        return *substitution_;
      }

      Element&
      root () const
      {
        return *root_;
      }

    public:
      void
      set_left_node (Element& n)
      {
        substitution_ = &n;
      }

      void
      set_right_node (Element& n)
      {
        root_ = &n;
      }

    private:
      Element* root_;
      Element* substitution_;
    };


    class LIBXSD_FRONTEND_SYMEXPORT Element: public virtual Member,
                                             public virtual Particle
    {
    public:
      bool
      substitutes_p () const
      {
        return substitutes_ != 0;
      }

      Substitutes&
      substitutes () const
      {
        assert (substitutes_ != 0);
        return *substitutes_;
      }

    public:
      Element (Path const& file,
               unsigned long line,
               unsigned long column,
               bool global,
               bool qualified);

      void
      add_edge_left (Substitutes& e)
      {
        substitutes_ = &e;
      }

      void
      add_edge_right (Substitutes&) {}

      using Member::add_edge_left;
      using Member::add_edge_right;
      using Particle::add_edge_right;

    private:
      Substitutes* substitutes_;
    };
  }
}

#endif  // LIBXSD_FRONTEND_SEMANTIC_GRAPH_ELEMENT_HXX
