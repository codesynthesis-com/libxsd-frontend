// file      : libxsd-frontend/traversal/union.cxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <libxsd-frontend/traversal/union.hxx>

namespace XSDFrontend
{
  namespace Traversal
  {
    void Union::
    traverse (Type& u)
    {
      pre (u);
      argumented (u);
      name (u);
      post (u);
    }

    void Union::
    pre (Type&)
    {
    }

    void Union::
    argumented (Type& u)
    {
      argumented (u, *this);
    }

    void Union::
    argumented (Type& u, EdgeDispatcher& d)
    {
      iterate_and_dispatch (u.argumented_begin (), u.argumented_end (), d);
    }

    void Union::
    name (Type&)
    {
    }

    void Union::
    post (Type&)
    {
    }
  }
}
