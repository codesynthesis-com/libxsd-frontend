// file      : xsd-frontend/traversal/union.cxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2005-2009 Code Synthesis Tools CC
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <xsd-frontend/traversal/union.hxx>

namespace XSDFrontend
{
  namespace Traversal
  {
    Void Union::
    traverse (Type& l)
    {
      pre (l);
      name (l);
      post (l);
    }

    Void Union::
    pre (Type&)
    {
    }

    Void Union::
    name (Type&)
    {
    }

    Void Union::
    post (Type&)
    {
    }
  }
}
