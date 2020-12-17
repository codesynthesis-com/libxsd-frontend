// file      : libxsd-frontend/semantic-graph/any.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_SEMANTIC_GRAPH_ANY_HXX
#define LIBXSD_FRONTEND_SEMANTIC_GRAPH_ANY_HXX

#include <vector>

#include <libxsd-frontend/semantic-graph/elements.hxx>
#include <libxsd-frontend/semantic-graph/particle.hxx>
#include <libxsd-frontend/semantic-graph/namespace.hxx>

#include <libxsd-frontend/export.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    class LIBXSD_FRONTEND_SYMEXPORT Any: public virtual Nameable,
                                         public virtual Particle
    {
      typedef std::vector<String> Namespaces;

    public:
      typedef Namespaces::const_iterator NamespaceIterator;

      NamespaceIterator
      namespace_begin () const
      {
        return namespaces_.begin ();
      }

      NamespaceIterator
      namespace_end () const
      {
        return namespaces_.end ();
      }

    public:
      bool
      prototype_p ()
      {
        return prototype_ != 0;
      }

      Any&
      prototype ()
      {
        assert (prototype_ != 0);
        return *prototype_;
      }

      void
      prototype (Any& a)
      {
        assert (prototype_ == 0);
        prototype_ = &a;
      }

    public:
      Namespace&
      definition_namespace ();

    public:
      Any (Path const& file,
           unsigned long line,
           unsigned long column,
           String const& namespaces);

      Any (Path const& file,
           unsigned long line,
           unsigned long column,
           NamespaceIterator begin,
           NamespaceIterator end);

      using Nameable::add_edge_right;
      using Particle::add_edge_right;

    private:
      Any* prototype_;
      Namespaces namespaces_;
    };
  }
}

#endif  // LIBXSD_FRONTEND_SEMANTIC_GRAPH_ANY_HXX
