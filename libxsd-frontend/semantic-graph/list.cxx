// file      : libxsd-frontend/semantic-graph/list.cxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <libcutl/compiler/type-info.hxx>

#include <libxsd-frontend/semantic-graph/list.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    List::
    List (Path const& file, unsigned long line, unsigned long column)
        : Node (file, line, column)
    {
    }

    namespace
    {
      using compiler::type_info;

      struct ListInit
      {
        ListInit ()
        {
          type_info ti (typeid (List));
          ti.add_base (typeid (Specialization));
          insert (ti);
        }
      } list_init_;
    }
  }
}
