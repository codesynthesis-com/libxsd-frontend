// file      : libxsd-frontend/semantic-graph/complex.cxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <libcutl/compiler/type-info.hxx>

#include <libxsd-frontend/semantic-graph/complex.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    Complex::
    Complex ()
        : abstract_ (false), mixed_ (false), contains_compositor_ (0)
    {
    }

    Complex::
    Complex (Path const& file,
             unsigned long line,
             unsigned long column,
             bool abstract)
        : Node (file, line, column),
          abstract_ (abstract), mixed_ (false), contains_compositor_ (0)
    {
    }

    namespace
    {
      using compiler::type_info;

      struct ComplexInit
      {
        ComplexInit ()
        {
          type_info ti (typeid (Complex));
          ti.add_base (typeid (Type));
          ti.add_base (typeid (Scope));
          insert (ti);
        }
      } complex_init_;
    }
  }
}
