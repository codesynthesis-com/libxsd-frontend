// file      : libxsd-frontend/semantic-graph/element-group.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_SEMANTIC_GRAPH_ELEMENT_GROUP_HXX
#define LIBXSD_FRONTEND_SEMANTIC_GRAPH_ELEMENT_GROUP_HXX

#include <libxsd-frontend/semantic-graph/elements.hxx>
#include <libxsd-frontend/semantic-graph/compositors.hxx>

#include <libxsd-frontend/export.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    class LIBXSD_FRONTEND_SYMEXPORT ElementGroup: public virtual Scope
    {
    public:
      ContainsCompositor&
      contains_compositor ()
      {
        assert (contains_compositor_ != 0);
        return *contains_compositor_;
      }

    public:
      ElementGroup (Path const& file, unsigned long line, unsigned long column);

      void
      add_edge_left (ContainsCompositor& e)
      {
        contains_compositor_ = &e;
      }

      using Scope::add_edge_left;

    private:
      ContainsCompositor* contains_compositor_;
    };
  }
}

#endif  // LIBXSD_FRONTEND_SEMANTIC_GRAPH_ELEMENT_GROUP_HXX
