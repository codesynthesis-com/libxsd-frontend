// file      : libxsd-frontend/traversal/elements.cxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <libxsd-frontend/traversal/elements.hxx>

namespace XSDFrontend
{
  namespace Traversal
  {
    // Instance
    //
    void Instance::
    traverse (Type& a)
    {
      pre (a);
      belongs (a);
      post (a);
    }

    void Instance::
    pre (Type&)
    {
    }

    void Instance::
    belongs (Type& a, EdgeDispatcher& d)
    {
      d.dispatch (a.belongs ());
    }

    void Instance::
    belongs (Type& a)
    {
      belongs (a, edge_traverser ());
    }

    void Instance::
    post (Type&)
    {
    }


    // Member
    //
    void Member::
    traverse (Type& a)
    {
      pre (a);
      belongs (a);
      post (a);
    }

    void Member::
    pre (Type&)
    {
    }

    void Member::
    belongs (Type& a, EdgeDispatcher& d)
    {
      d.dispatch (a.belongs ());
    }

    void Member::
    belongs (Type& a)
    {
      belongs (a, edge_traverser ());
    }

    void Member::
    post (Type&)
    {
    }
  }
}
