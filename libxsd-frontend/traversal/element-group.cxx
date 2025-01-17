// file      : libxsd-frontend/traversal/element-group.cxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <libxsd-frontend/traversal/element-group.hxx>

namespace XSDFrontend
{
  namespace Traversal
  {
    void ElementGroup::
    traverse (Type& g)
    {
      pre (g);
      names (g);
      contains_compositor (g);
      post (g);
    }

    void ElementGroup::
    pre (Type&)
    {
    }

    void ElementGroup::
    contains_compositor (Type& g, EdgeDispatcher& d)
    {
      d.dispatch (g.contains_compositor ());
    }

    void ElementGroup::
    contains_compositor (Type& g)
    {
      contains_compositor (g, *this);
    }

    void ElementGroup::
    post (Type&)
    {
    }
  }
}
