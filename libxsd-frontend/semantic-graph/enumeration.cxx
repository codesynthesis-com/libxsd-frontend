// file      : libxsd-frontend/semantic-graph/enumeration.cxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <libcutl/compiler/type-info.hxx>

#include <libxsd-frontend/semantic-graph/enumeration.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    // Enumeration
    //
    Enumeration::
    Enumeration (Path const& file, unsigned long line, unsigned long column)
        : Node (file, line, column)
    {
    }

    // Enumerator
    //
    Enumerator::
    Enumerator (Path const& file, unsigned long line, unsigned long column)
        : Node (file, line, column)
    {
    }

    namespace
    {
      using compiler::type_info;

      // Enumeration
      //
      struct EnumerationInit
      {
        EnumerationInit ()
        {
          type_info ti (typeid (Enumeration));
          ti.add_base (typeid (Complex));
          insert (ti);
        }
      } enumeration_init_;


      // Enumerator
      //
      struct EnumeratorInit
      {
        EnumeratorInit ()
        {
          type_info ti (typeid (Enumerator));
          ti.add_base (typeid (Instance));
          insert (ti);
        }
      } enumerator_init_;
    }
  }
}
