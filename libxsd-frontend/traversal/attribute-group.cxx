// file      : libxsd-frontend/traversal/attribute-group.cxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <libxsd-frontend/traversal/attribute-group.hxx>

namespace XSDFrontend
{
  namespace Traversal
  {
    void AttributeGroup::
    traverse (Type& g)
    {
      pre (g);
      names (g);
      post (g);
    }

    void AttributeGroup::
    pre (Type&)
    {
    }

    void AttributeGroup::
    post (Type&)
    {
    }
  }
}
