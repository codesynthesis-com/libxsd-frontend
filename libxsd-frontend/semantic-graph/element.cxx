// file      : libxsd-frontend/semantic-graph/element.cxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <libcutl/compiler/type-info.hxx>

#include <libxsd-frontend/semantic-graph/element.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    // Element
    //
    Element::
    Element (Path const& file,
             unsigned long line,
             unsigned long column,
             bool global,
             bool qualified)
        : Node (file, line, column),
          Member (global, qualified),
          substitutes_ (0)
    {
    }

    namespace
    {
      using compiler::type_info;

      struct SubstitutesInit
      {
        SubstitutesInit ()
        {
          type_info ti (typeid (Substitutes));
          ti.add_base (typeid (Edge));
          insert (ti);
        }
      } substitutes_init_;

      struct ElementInit
      {
        ElementInit ()
        {
          type_info ti (typeid (Element));
          ti.add_base (typeid (Member));
          ti.add_base (typeid (Particle));
          insert (ti);
        }
      } element_init_;
    }
  }
}
