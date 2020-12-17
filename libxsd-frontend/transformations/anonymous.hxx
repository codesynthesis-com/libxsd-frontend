// file      : libxsd-frontend/transformations/anonymous.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_TRANSFORMATIONS_ANONYMOUS_HXX
#define LIBXSD_FRONTEND_TRANSFORMATIONS_ANONYMOUS_HXX

#include <libxsd-frontend/types.hxx>

#include <libxsd-frontend/semantic-graph/elements.hxx> // Path
#include <libxsd-frontend/semantic-graph/schema.hxx>

#include <libxsd-frontend/export.hxx>

namespace XSDFrontend
{
  namespace Transformations
  {
    class LIBXSD_FRONTEND_SYMEXPORT AnonymousNameTranslator
    {
    public:
      virtual
      ~AnonymousNameTranslator ();

      // The file argument is empty for the currect translation
      // unit.
      //
      virtual String
      translate (String const& file,
                 String const& ns,
                 String const& name,
                 String const& xpath) = 0;
    };

    // This transformation morphs anonymous types into named ones
    // with the names derived from the enclosing attributes and
    // elements. If the detect_unstable_conflicts argument is true
    // then the transformation detects and reports unstable conflicts
    // in name assignment.
    //
    class LIBXSD_FRONTEND_SYMEXPORT Anonymous
    {
    public:
      struct Failed {};

      Anonymous (AnonymousNameTranslator&);

      void
      transform (SemanticGraph::Schema&,
                 SemanticGraph::Path const&,
                 bool detect_unstable_conflicts);

    private:
      AnonymousNameTranslator& trans_;
    };
  }
}

#endif // LIBXSD_FRONTEND_TRANSFORMATIONS_ANONYMOUS_HXX
