// file      : xsd-frontend/semantic-graph/complex.cxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2005-2011 Code Synthesis Tools CC
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <cutl/compiler/type-info.hxx>

#include <xsd-frontend/semantic-graph/complex.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    Complex::
    Complex ()
        : mixed_ (false), contains_compositor_ (0)
    {
    }

    Complex::
    Complex (Path const& file, unsigned long line, unsigned long column)
        : Node (file, line, column),
          mixed_ (false), contains_compositor_ (0)
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
