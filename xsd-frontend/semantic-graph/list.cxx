// file      : xsd-frontend/semantic-graph/list.cxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2005-2011 Code Synthesis Tools CC
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <cutl/compiler/type-info.hxx>

#include <xsd-frontend/semantic-graph/list.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    List::
    List (Path const& file, UnsignedLong line, UnsignedLong column)
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
