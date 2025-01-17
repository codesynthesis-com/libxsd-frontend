// file      : libxsd-frontend/semantic-graph/element-group.cxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <libcutl/compiler/type-info.hxx>

#include <libxsd-frontend/semantic-graph/element-group.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    ElementGroup::
    ElementGroup (Path const& file, unsigned long line, unsigned long column)
        : Node (file, line, column), contains_compositor_ (0)
    {
    }

    namespace
    {
      using compiler::type_info;

      struct ElementGroupInit
      {
        ElementGroupInit ()
        {
          type_info ti (typeid (ElementGroup));
          ti.add_base (typeid (Scope));
          insert (ti);
        }
      } element_group_init_;
    }
  }
}
