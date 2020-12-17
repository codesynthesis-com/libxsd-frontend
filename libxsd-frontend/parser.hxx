// file      : libxsd-frontend/parser.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_PARSER_HXX
#define LIBXSD_FRONTEND_PARSER_HXX

#include <set>
#include <memory> // std::unique_ptr

#include <libxsd-frontend/types.hxx>
#include <libxsd-frontend/semantic-graph/schema.hxx>

#include <libxsd-frontend/export.hxx>

namespace XSDFrontend
{
  struct InvalidSchema {};

  class LIBXSD_FRONTEND_SYMEXPORT LocationTranslator
  {
  public:
    virtual
    ~LocationTranslator ();

    virtual NarrowString
    translate (NarrowString const& location) = 0;
  };

  // Set of disabled warning IDs. Special ID "all" disables all
  // warnings.
  //
  typedef std::set<NarrowString> WarningSet;

  class LIBXSD_FRONTEND_SYMEXPORT Parser
  {
  public:
    ~Parser ();

    Parser (bool proper_restriction,
            bool multiple_imports,
            bool full_schema_check);

    Parser (bool proper_restriction,
            bool multiple_imports,
            bool full_schema_check,
            LocationTranslator&,
            const WarningSet& disabled);

  private:
    Parser (Parser const&);
    Parser& operator= (Parser const&);

  public:
    // Parse a schema file. Throws InvalidSchema in case of a failure.
    //
    std::unique_ptr<SemanticGraph::Schema>
    parse (SemanticGraph::Path const&);

    // Parse a number of schema files all into one semantic graph.
    // Each schema file is imported from an unnamed root translation
    // unit. Throws InvalidSchema in case of a failure.
    //
    std::unique_ptr<SemanticGraph::Schema>
    parse (SemanticGraph::Paths const&);

    // Returns a schema graph that corresponds to the XML Schema
    // namespace with built-in type definitions. The path is fake
    // and is only used as a lable.
    //
    std::unique_ptr<SemanticGraph::Schema>
    xml_schema (SemanticGraph::Path const&);

  private:
    class Impl;
    std::unique_ptr<Impl> impl_;
  };
}

#endif  // LIBXSD_FRONTEND_PARSER_HXX
