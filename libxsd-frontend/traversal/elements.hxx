// file      : libxsd-frontend/traversal/elements.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_TRAVERSAL_ELEMENTS_HXX
#define LIBXSD_FRONTEND_TRAVERSAL_ELEMENTS_HXX

#include <libcutl/compiler/traversal.hxx>

#include <libxsd-frontend/types.hxx>
#include <libxsd-frontend/semantic-graph/elements.hxx>

#include <libxsd-frontend/export.hxx>

namespace XSDFrontend
{
  namespace Traversal
  {
    using namespace cutl;

    typedef compiler::dispatcher<SemanticGraph::Node> NodeDispatcher;
    typedef compiler::dispatcher<SemanticGraph::Edge> EdgeDispatcher;

    //
    //
    struct NodeBase: NodeDispatcher, EdgeDispatcher
    {
      void
      edge_traverser (EdgeDispatcher& d)
      {
        EdgeDispatcher::traverser (d);
      }

      EdgeDispatcher&
      edge_traverser ()
      {
        return *this;
      }

      using NodeDispatcher::dispatch;
      using EdgeDispatcher::dispatch;

      using EdgeDispatcher::iterate_and_dispatch;
    };

    struct EdgeBase: EdgeDispatcher, NodeDispatcher
    {
      void
      node_traverser (NodeDispatcher& d)
      {
        NodeDispatcher::traverser (d);
      }

      NodeDispatcher&
      node_traverser ()
      {
        return *this;
      }

      using EdgeDispatcher::dispatch;
      using NodeDispatcher::dispatch;

      using NodeDispatcher::iterate_and_dispatch;
    };

    inline EdgeBase&
    operator>> (NodeBase& n, EdgeBase& e)
    {
      n.edge_traverser (e);
      return e;
    }

    inline NodeBase&
    operator>> (EdgeBase& e, NodeBase& n)
    {
      e.node_traverser (n);
      return n;
    }

    //
    //
    template <typename T>
    struct Node: compiler::traverser_impl<T, SemanticGraph::Node>,
                 virtual NodeBase
    {
      typedef T Type;
    };

    template <typename T>
    struct Edge: compiler::traverser_impl<T, SemanticGraph::Edge>,
                 virtual EdgeBase
    {
      typedef T Type;
    };

    //
    // Edges
    //

    //
    //
    struct Names : Edge<SemanticGraph::Names>
    {
      Names ()
      {
      }

      Names (NodeBase& n)
      {
        node_traverser (n);
      }

      virtual void
      traverse (Type& e)
      {
        dispatch (e.named ());
      }
    };


    //
    //
    struct Belongs : Edge<SemanticGraph::Belongs>
    {
      Belongs ()
      {
      }

      Belongs (NodeBase& n)
      {
        node_traverser (n);
      }

      virtual void
      traverse (Type& e)
      {
        dispatch (e.type ());
      }
    };

    //
    // Nodes
    //

    //
    //
    struct Nameable : Node<SemanticGraph::Nameable>
    {
    };


    //
    //
    template <typename T>
    struct ScopeTemplate : Node<T>
    {
    public:
      virtual void
      traverse (T& s)
      {
        names (s);
      }

      template<typename X>
      void
      names (T& s,
             EdgeDispatcher& d,
             void (X::*pre_) (T&) = (void (ScopeTemplate<T>::*)(T&)) (0),
             void (X::*post_) (T&) = (void (ScopeTemplate<T>::*)(T&)) (0),
             void (X::*none_) (T&) = (void (ScopeTemplate<T>::*)(T&)) (0),
             void (X::*next_) (T&) = (void (ScopeTemplate<T>::*)(T&)) (0))
      {
        X* this_ (dynamic_cast<X*> (this));

        typename T::NamesIterator b (s.names_begin ()), e (s.names_end ());

        if (b != e)
        {
          if (pre_)
            (this_->*pre_) (s);

          //iterate_and_dispatch (b, e, d, *this_, next_, s);

          for (; b != s.names_end ();)
          {
            d.dispatch (*b);

            if (++b != s.names_end () && next_ != 0)
              (this_->*next_) (s);
          }

          if (post_)
            (this_->*post_) (s);
        }
        else
        {
          if (none_)
            (this_->*none_) (s);
        }
      }

      virtual void
      names (T& s, EdgeDispatcher& d)
      {
        names<ScopeTemplate<T> > (s, d);
      }

      virtual void
      names (T& s)
      {
        names (s,
               *this,
               &ScopeTemplate<T>::names_pre,
               &ScopeTemplate<T>::names_post,
               &ScopeTemplate<T>::names_none,
               &ScopeTemplate<T>::names_next);
      }

      virtual void
      names_pre (T&)
      {
      }

      virtual void
      names_next (T&)
      {
      }

      virtual void
      names_post (T&)
      {
      }

      virtual void
      names_none (T&)
      {
      }
    };


    //
    //
    typedef
    ScopeTemplate<SemanticGraph::Scope>
    Scope;


    //
    //
    struct Type : Node<SemanticGraph::Type>
    {
      virtual void
      traverse (SemanticGraph::Type&) = 0;
    };


    //
    //
    struct LIBXSD_FRONTEND_SYMEXPORT Instance: Node<SemanticGraph::Instance>
    {
      virtual void
      traverse (Type&);

      virtual void
      pre (Type&);

      virtual void
      belongs (Type&, EdgeDispatcher&);

      virtual void
      belongs (Type&);

      virtual void
      post (Type&);
    };


    //
    //
    struct LIBXSD_FRONTEND_SYMEXPORT Member: Node<SemanticGraph::Member>
    {
      virtual void
      traverse (Type&);

      virtual void
      pre (Type&);

      virtual void
      belongs (Type&, EdgeDispatcher&);

      virtual void
      belongs (Type&);

      virtual void
      post (Type&);
    };


    //
    //
    struct Inherits : Edge<SemanticGraph::Inherits>
    {
      Inherits ()
      {
      }

      Inherits (NodeBase& n)
      {
        node_traverser (n);
      }

      virtual void
      traverse (Type& e)
      {
        dispatch (e.base ());
      }
    };


    //
    //
    struct Extends : Edge<SemanticGraph::Extends>
    {
      Extends ()
      {
      }

      Extends (NodeBase& n)
      {
        node_traverser (n);
      }

      virtual void
      traverse (Type& e)
      {
        dispatch (e.base ());
      }
    };


    //
    //
    struct Restricts : Edge<SemanticGraph::Restricts>
    {
      Restricts ()
      {
      }

      Restricts (NodeBase& n)
      {
        node_traverser (n);
      }

      virtual void
      traverse (Type& e)
      {
        dispatch (e.base ());
      }
    };


    //
    //
    struct Argumented : Edge<SemanticGraph::Arguments>
    {
      Argumented ()
      {
      }

      Argumented (NodeBase& n)
      {
        node_traverser (n);
      }

      virtual void
      traverse (Type& a)
      {
        dispatch (a.type ());
      }
    };


    /*
    //
    //
    struct Contains : Edge<SemanticGraph::Contains>
    {
      virtual void
      traverse (Type& e)
      {
        dispatch (e.element ());
      }
    };
    */

    //
    //
    typedef
    Node<SemanticGraph::AnyType>
    AnyType;


    //
    //
    typedef
    Node<SemanticGraph::AnySimpleType>
    AnySimpleType;
  }
}

#include <libxsd-frontend/traversal/elements.txx>

#endif  // LIBXSD_FRONTEND_TRAVERSAL_ELEMENTS_HXX
