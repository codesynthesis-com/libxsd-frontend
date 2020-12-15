// file      : libxsd-frontend/semantic-graph/namespace.cxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <libcutl/compiler/type-info.hxx>

#include <libxsd-frontend/semantic-graph/namespace.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    Namespace::
    Namespace (Path const& file, unsigned long line, unsigned long column)
        : Node (file, line, column)
    {
    }

    namespace
    {
      using compiler::type_info;

      struct NamespaceInit
      {
        NamespaceInit ()
        {
          type_info ti (typeid (Namespace));
          ti.add_base (typeid (Scope));
          insert (ti);
        }
      } namespace_init_;
    }
  }
}
