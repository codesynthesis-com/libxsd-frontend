// file      : libxsd-frontend/transformations/schema-per-type.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_TRANSFORMATIONS_SCHEMA_PER_TYPE_HXX
#define LIBXSD_FRONTEND_TRANSFORMATIONS_SCHEMA_PER_TYPE_HXX

#include <vector>

#include <libxsd-frontend/types.hxx>

#include <libxsd-frontend/semantic-graph/elements.hxx> // Path
#include <libxsd-frontend/semantic-graph/schema.hxx>

#include <libxsd-frontend/export.hxx>

namespace XSDFrontend
{
  namespace Transformations
  {
    class LIBXSD_FRONTEND_SYMEXPORT SchemaPerTypeTranslator
    {
    public:
      virtual
      ~SchemaPerTypeTranslator ();

      // The following two functions should return empty string if
      // there is no match.
      //
      virtual String
      translate_type (String const& ns, String const& name) = 0;

      virtual NarrowString
      translate_schema (NarrowString const& abs_path) = 0;
    };

    // This transformation restructures the semantic graph to have
    // each type definition in a seperate schema file.
    //
    class LIBXSD_FRONTEND_SYMEXPORT SchemaPerType
    {
    public:
      struct Failed {};

      // If a type of an element or attribute has a context entry
      // with the by_value_key key and it is true, then the schema
      // for this type is included "strongly".
      //
      SchemaPerType (SchemaPerTypeTranslator&,
                     bool fat_type_file,
                     char const* by_value_key = 0);

      std::vector<SemanticGraph::Schema*>
      transform (SemanticGraph::Schema&);

    private:
      bool fat_type_file_;
      char const* by_value_key_;
      SchemaPerTypeTranslator& trans_;
    };
  }
}

#endif // LIBXSD_FRONTEND_TRANSFORMATIONS_SCHEMA_PER_TYPE_HXX
