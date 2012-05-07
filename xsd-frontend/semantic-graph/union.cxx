// file      : xsd-frontend/semantic-graph/union.cxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2005-2011 Code Synthesis Tools CC
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <cutl/compiler/type-info.hxx>

#include <xsd-frontend/semantic-graph/union.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    Union::
    Union (Path const& file, UnsignedLong line, UnsignedLong column)
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
