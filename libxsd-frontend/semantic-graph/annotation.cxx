// file      : libxsd-frontend/semantic-graph/annotation.cxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <libcutl/compiler/type-info.hxx>

#include <libxsd-frontend/semantic-graph/annotation.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    using compiler::type_info;

    // Annotates
    //
    namespace
    {
      struct AnnotatesInit
      {
        AnnotatesInit ()
        {
          type_info ti (typeid (Annotates));
          ti.add_base (typeid (Edge));
          insert (ti);
        }
      } annotates_init_;
    }

    // Annotation
    //
    namespace
    {
      struct AnnotationInit
      {
        AnnotationInit ()
        {
          type_info ti (typeid (Annotation));
          ti.add_base (typeid (Node));
          insert (ti);
        }
      } annotation_init_;
    }
  }
}
