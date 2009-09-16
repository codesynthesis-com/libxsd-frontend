// file      : xsd-frontend/traversal/attribute.hxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2005-2009 Code Synthesis Tools CC
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef XSD_FRONTEND_TRAVERSAL_ATTRIBUTE_HXX
#define XSD_FRONTEND_TRAVERSAL_ATTRIBUTE_HXX

#include <xsd-frontend/traversal/elements.hxx>

#include <xsd-frontend/semantic-graph/attribute.hxx>


namespace XSDFrontend
{
  namespace Traversal
  {
    struct Attribute : Node<SemanticGraph::Attribute>
    {
      virtual Void
      traverse (Type&);

      virtual Void
      pre (Type&);

      virtual Void
      belongs (Type&, EdgeDispatcherBase&);

      virtual Void
      belongs (Type&);

      virtual Void
      name (Type&);

      virtual Void
      post (Type&);
    };
  }
}

#endif  // XSD_FRONTEND_TRAVERSAL_ATTRIBUTE_HXX
