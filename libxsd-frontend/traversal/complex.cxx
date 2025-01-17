// file      : libxsd-frontend/traversal/complex.cxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <libxsd-frontend/traversal/complex.hxx>

namespace XSDFrontend
{
  namespace Traversal
  {
    void Complex::
    traverse (Type& c)
    {
      pre (c);
      name (c);
      inherits (c);
      names (c);
      contains_compositor (c);
      post (c);
    }

    void Complex::
    pre (Type&)
    {
    }

    void Complex::
    name (Type&)
    {
    }

    void Complex::
    inherits (Type& c)
    {
      inherits (c, *this);
    }

    void Complex::
    inherits (Type& c, EdgeDispatcher& d)
    {
      if (c.inherits_p ())
        d.dispatch (c.inherits ());
    }

    void Complex::
    contains_compositor (Type& c)
    {
      contains_compositor (c, *this);
    }

    void Complex::
    contains_compositor (Type& c, EdgeDispatcher& d)
    {
      if (c.contains_compositor_p ())
        d.dispatch (c.contains_compositor ());
    }

    void Complex::
    post (Type&)
    {
    }
  }
}
