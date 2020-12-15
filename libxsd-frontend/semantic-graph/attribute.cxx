// file      : libxsd-frontend/semantic-graph/attribute.cxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <libcutl/compiler/type-info.hxx>

#include <libxsd-frontend/semantic-graph/attribute.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    Attribute::
    Attribute (Path const& file,
               unsigned long line,
               unsigned long column,
               bool optional,
               bool global,
               bool qualified)
        : Node (file, line, column),
          Member (global, qualified),
          optional_ (optional)
    {
    }

    namespace
    {
      using compiler::type_info;

      struct AttributeInit
      {
        AttributeInit ()
        {
          type_info ti (typeid (Attribute));
          ti.add_base (typeid (Member));
          insert (ti);
        }
      } attribute_init_;
    }
  }
}
