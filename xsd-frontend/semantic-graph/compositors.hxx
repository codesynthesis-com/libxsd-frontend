// file      : xsd-frontend/semantic-graph/compositors.hxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2006-2011 Code Synthesis Tools CC
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef XSD_FRONTEND_SEMANTIC_GRAPH_COMPOSITORS_HXX
#define XSD_FRONTEND_SEMANTIC_GRAPH_COMPOSITORS_HXX

#include <list>

#include <xsd-frontend/semantic-graph/elements.hxx>
#include <xsd-frontend/semantic-graph/particle.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    //
    //
    class ContainsCompositor: public virtual Edge
    {
    public:
      Compositor&
      compositor () const
      {
        return *compositor_;
      }

      Node&
      container () const
      {
        return *container_;
      }

    public:
      UnsignedLong
      min () const
      {
        return min_;
      }

      UnsignedLong
      max () const
      {
        return max_;
      }

    public:
      ContainsCompositor (UnsignedLong min, UnsignedLong max);

      Void
      set_left_node (Node& n)
      {
        container_ = &n;
      }

      Void
      set_right_node (Compositor& n)
      {
        compositor_ = &n;
      }

      Void
      clear_left_node (Node& n)
      {
        assert (container_ == &n);
        container_ = 0;
      }

      Void
      clear_right_node (Compositor& n)
      {
        assert (compositor_ == &n);
        compositor_ = 0;
      }

    private:
      Compositor* compositor_;
      Node* container_;
      UnsignedLong min_, max_;
    };

    //
    //
    class Compositor: public virtual Particle
    {
      typedef std::list<ContainsParticle*> ContainsList;

    public:
      typedef pointer_iterator<ContainsList::iterator> ContainsIterator;
      typedef
      pointer_iterator<ContainsList::const_iterator>
      ContainsConstIterator;

      ContainsIterator
      contains_begin ()
      {
        return contains_.begin ();
      }

      ContainsIterator
      contains_end ()
      {
        return contains_.end ();
      }

      ContainsConstIterator
      contains_begin () const
      {
        return contains_.begin ();
      }

      ContainsConstIterator
      contains_end () const
      {
        return contains_.end ();
      }

    public:
      Boolean
      contained_compositor_p ()
      {
        return contained_compositor_ != 0;
      }

      ContainsCompositor&
      contained_compositor ()
      {
        assert (contained_compositor_ != 0);
        return *contained_compositor_;
      }

    public:
      UnsignedLong
      min () const
      {
        if (contained_compositor_ != 0)
          return contained_compositor_->min ();
        else
          return Particle::min ();
      }

      UnsignedLong
      max () const
      {
        if (contained_compositor_ != 0)
          return contained_compositor_->max ();
        else
          return Particle::max ();
      }

    public:
      Compositor (): contained_compositor_ (0) {}

      Void
      add_edge_left (ContainsParticle& e)
      {
        contains_.push_back (&e);
      }

      Void
      add_edge_left (ContainsParticle& e, ContainsIterator const& after)
      {
        if (after.base () == contains_.end ())
          contains_.push_front (&e);
        else
        {
          ContainsList::iterator i (after.base ());
          contains_.insert (++i, &e);
        }
      }

      Void
      remove_edge_left (ContainsParticle& e)
      {
        for (ContainsList::iterator i (contains_.begin ());
             i != contains_.end (); ++i)
        {
          if (*i == &e)
          {
            contains_.erase (i);
            break;
          }
        }
      }

      Void
      add_edge_right (ContainsCompositor& e)
      {
        contained_compositor_ = &e;
      }

      Void
      remove_edge_right (ContainsCompositor& e)
      {
        assert (contained_compositor_ == &e);
        contained_compositor_ = 0;
      }

      using Node::add_edge_right;
      using Particle::add_edge_right;
      using Particle::remove_edge_right;

    private:
      ContainsList contains_;
      ContainsCompositor* contained_compositor_;
    };

    //
    //
    class All: public virtual Compositor
    {
    public:
      All (Path const& file, UnsignedLong line, UnsignedLong column);
    };

    //
    //
    class Choice: public virtual Compositor
    {
    public:
      Choice (Path const& file, UnsignedLong line, UnsignedLong column);
    };

    //
    //
    class Sequence: public virtual Compositor
    {
    public:
      Sequence (Path const& file, UnsignedLong line, UnsignedLong column);
    };
  }
}

#endif  // XSD_FRONTEND_SEMANTIC_GRAPH_COMPOSITORS_HXX
