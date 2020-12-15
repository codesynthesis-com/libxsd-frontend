// file      : libxsd-frontend/traversal/attribute.cxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <libxsd-frontend/traversal/attribute.hxx>

namespace XSDFrontend
{
  namespace Traversal
  {
    void Attribute::
    traverse (Type& a)
    {
      pre (a);
      belongs (a);
      name (a);
      post (a);
    }

    void Attribute::
    pre (Type&)
    {
    }

    void Attribute::
    belongs (Type& a, EdgeDispatcher& d)
    {
      d.dispatch (a.belongs ());
    }

    void Attribute::
    belongs (Type& a)
    {
      belongs (a, *this);
    }

    void Attribute::
    name (Type&)
    {
    }

    void Attribute::
    post (Type&)
    {
    }
  }
}
