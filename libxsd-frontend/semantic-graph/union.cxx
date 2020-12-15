// file      : libxsd-frontend/semantic-graph/union.cxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <libcutl/compiler/type-info.hxx>

#include <libxsd-frontend/semantic-graph/union.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    Union::
    Union (Path const& file, unsigned long line, unsigned long column)
        : Node (file, line, column)
    {
    }

    namespace
    {
      using compiler::type_info;

      struct UnionInit
      {
        UnionInit ()
        {
          type_info ti (typeid (Union));
          ti.add_base (typeid (Specialization));
          insert (ti);
        }
      } union_init_;
    }
  }
}
