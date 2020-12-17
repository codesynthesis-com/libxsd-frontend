// file      : libxsd-frontend/semantic-graph/fundamental.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_SEMANTIC_GRAPH_FUNDAMENTAL_HXX
#define LIBXSD_FRONTEND_SEMANTIC_GRAPH_FUNDAMENTAL_HXX

#include <libxsd-frontend/semantic-graph/elements.hxx>

#include <libxsd-frontend/export.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    namespace Fundamental
    {
      // Type
      //
      class LIBXSD_FRONTEND_SYMEXPORT Type: public virtual SemanticGraph::Type
      {
      protected:
        Type ();
      };

      // Byte
      //
      class LIBXSD_FRONTEND_SYMEXPORT Byte: public virtual Type
      {
      public:
        Byte (Path const& file,
              unsigned long line,
              unsigned long column);
      };

      // UnsignedByte
      //
      class LIBXSD_FRONTEND_SYMEXPORT UnsignedByte: public virtual Type
      {
      public:
        UnsignedByte (Path const& file,
                      unsigned long line,
                      unsigned long column);
      };

      // Short
      //
      class LIBXSD_FRONTEND_SYMEXPORT Short: public virtual Type
      {
      public:
        Short (Path const& file,
               unsigned long line,
               unsigned long column);
      };

      // UnsignedShort
      //
      class LIBXSD_FRONTEND_SYMEXPORT UnsignedShort: public virtual Type
      {
      public:
        UnsignedShort (Path const& file,
                       unsigned long line,
                       unsigned long column);
      };

      // Int
      //
      class LIBXSD_FRONTEND_SYMEXPORT Int: public virtual Type
      {
      public:
        Int (Path const& file,
             unsigned long line,
             unsigned long column);
      };

      // UnsignedInt
      //
      class LIBXSD_FRONTEND_SYMEXPORT UnsignedInt: public virtual Type
      {
      public:
        UnsignedInt (Path const& file,
                     unsigned long line,
                     unsigned long column);
      };

      // Long
      //
      class LIBXSD_FRONTEND_SYMEXPORT Long: public virtual Type
      {
      public:
        Long (Path const& file,
              unsigned long line,
              unsigned long column);
      };

      // UnsignedLong
      //
      class LIBXSD_FRONTEND_SYMEXPORT UnsignedLong: public virtual Type
      {
      public:
        UnsignedLong (Path const& file,
                      unsigned long line,
                      unsigned long column);
      };

      // Integer
      //
      class LIBXSD_FRONTEND_SYMEXPORT Integer: public virtual Type
      {
      public:
        Integer (Path const& file,
                 unsigned long line,
                 unsigned long column);
      };

      // NonPositiveInteger
      //
      class LIBXSD_FRONTEND_SYMEXPORT NonPositiveInteger: public virtual Type
      {
      public:
        NonPositiveInteger (Path const& file,
                            unsigned long line,
                            unsigned long column);
      };

      // NonNegativeInteger
      //
      class LIBXSD_FRONTEND_SYMEXPORT NonNegativeInteger: public virtual Type
      {
      public:
        NonNegativeInteger (Path const& file,
                            unsigned long line,
                            unsigned long column);
      };

      // PositiveInteger
      //
      class LIBXSD_FRONTEND_SYMEXPORT PositiveInteger: public virtual Type
      {
      public:
        PositiveInteger (Path const& file,
                         unsigned long line,
                         unsigned long column);
      };

      // NegativeInteger
      //
      class LIBXSD_FRONTEND_SYMEXPORT NegativeInteger: public virtual Type
      {
      public:
        NegativeInteger (Path const& file,
                         unsigned long line,
                         unsigned long column);
      };

      // Boolean
      //
      class LIBXSD_FRONTEND_SYMEXPORT Boolean: public virtual Type
      {
      public:
        Boolean (Path const& file,
                 unsigned long line,
                 unsigned long column);
      };

      // Float
      //
      class LIBXSD_FRONTEND_SYMEXPORT Float: public virtual Type
      {
      public:
        Float (Path const& file,
               unsigned long line,
               unsigned long column);
      };

      // Double
      //
      class LIBXSD_FRONTEND_SYMEXPORT Double: public virtual Type
      {
      public:
        Double (Path const& file,
                unsigned long line,
                unsigned long column);
      };

      // Decimal
      //
      class LIBXSD_FRONTEND_SYMEXPORT Decimal: public virtual Type
      {
      public:
        Decimal (Path const& file,
                 unsigned long line,
                 unsigned long column);
      };

      // String
      //
      class LIBXSD_FRONTEND_SYMEXPORT String: public virtual Type
      {
      public:
        String (Path const& file,
                unsigned long line,
                unsigned long column);
      };

      // NormalizedString
      //
      class LIBXSD_FRONTEND_SYMEXPORT NormalizedString: public virtual Type
      {
      public:
        NormalizedString (Path const& file,
                          unsigned long line,
                          unsigned long column);
      };

      // Token
      //
      class LIBXSD_FRONTEND_SYMEXPORT Token: public virtual Type
      {
      public:
        Token (Path const& file,
               unsigned long line,
               unsigned long column);
      };

      // Name
      //
      class LIBXSD_FRONTEND_SYMEXPORT Name: public virtual Type
      {
      public:
        Name (Path const& file,
              unsigned long line,
              unsigned long column);
      };

      // NameToken
      //
      class LIBXSD_FRONTEND_SYMEXPORT NameToken: public virtual Type
      {
      public:
        NameToken (Path const& file,
                   unsigned long line,
                   unsigned long column);
      };

      // NameTokens
      //
      class LIBXSD_FRONTEND_SYMEXPORT NameTokens: public virtual Type
      {
      public:
        NameTokens (Path const& file,
                    unsigned long line,
                    unsigned long column);
      };

      // NCName
      //
      class LIBXSD_FRONTEND_SYMEXPORT NCName: public virtual Type
      {
      public:
        NCName (Path const& file,
                unsigned long line,
                unsigned long column);
      };

      // Language
      //
      class LIBXSD_FRONTEND_SYMEXPORT Language: public virtual Type
      {
      public:
        Language (Path const& file,
                  unsigned long line,
                  unsigned long column);
      };

      // QName
      //
      class LIBXSD_FRONTEND_SYMEXPORT QName: public virtual Type
      {
      public:
        QName (Path const& file,
               unsigned long line,
               unsigned long column);
      };

      // Id
      //
      class LIBXSD_FRONTEND_SYMEXPORT Id: public virtual Type
      {
      public:
        Id (Path const& file,
            unsigned long line,
            unsigned long column);
      };

      // IdRef
      //
      class LIBXSD_FRONTEND_SYMEXPORT IdRef: public virtual Type,
                                             public virtual Specialization
      {
      public:
        IdRef (Path const& file,
               unsigned long line,
               unsigned long column);
      };

      // IdRefs
      //
      class LIBXSD_FRONTEND_SYMEXPORT IdRefs: public virtual Type,
                                              public virtual Specialization
      {
      public:
        IdRefs (Path const& file,
                unsigned long line,
                unsigned long column);
      };

      // AnyURI
      //
      class LIBXSD_FRONTEND_SYMEXPORT AnyURI: public virtual Type
      {
      public:
        AnyURI (Path const& file,
                unsigned long line,
                unsigned long column);
      };

      // Base64Binary
      //
      class LIBXSD_FRONTEND_SYMEXPORT Base64Binary: public virtual Type
      {
      public:
        Base64Binary (Path const& file,
                      unsigned long line,
                      unsigned long column);
      };

      // HexBinary
      //
      class LIBXSD_FRONTEND_SYMEXPORT HexBinary: public virtual Type
      {
      public:
        HexBinary (Path const& file,
                   unsigned long line,
                   unsigned long column);
      };

      // Date
      //
      class LIBXSD_FRONTEND_SYMEXPORT Date: public virtual Type
      {
      public:
        Date (Path const& file,
              unsigned long line,
              unsigned long column);
      };

      // DateTime
      //
      class LIBXSD_FRONTEND_SYMEXPORT DateTime: public virtual Type
      {
      public:
        DateTime (Path const& file,
                  unsigned long line,
                  unsigned long column);
      };

      // Duration
      //
      class LIBXSD_FRONTEND_SYMEXPORT Duration: public virtual Type
      {
      public:
        Duration (Path const& file,
                  unsigned long line,
                  unsigned long column);
      };

      // Day
      //
      class LIBXSD_FRONTEND_SYMEXPORT Day: public virtual Type
      {
      public:
        Day (Path const& file,
             unsigned long line,
             unsigned long column);
      };

      // Month
      //
      class LIBXSD_FRONTEND_SYMEXPORT Month: public virtual Type
      {
      public:
        Month (Path const& file,
               unsigned long line,
               unsigned long column);
      };

      // MonthDay
      //
      class LIBXSD_FRONTEND_SYMEXPORT MonthDay: public virtual Type
      {
      public:
        MonthDay (Path const& file,
                  unsigned long line,
                  unsigned long column);
      };

      // Year
      //
      class LIBXSD_FRONTEND_SYMEXPORT Year: public virtual Type
      {
      public:
        Year (Path const& file,
              unsigned long line,
              unsigned long column);
      };

      // YearMonth
      //
      class LIBXSD_FRONTEND_SYMEXPORT YearMonth: public virtual Type
      {
      public:
        YearMonth (Path const& file,
                   unsigned long line,
                   unsigned long column);
      };

      // Time
      //
      class LIBXSD_FRONTEND_SYMEXPORT Time: public virtual Type
      {
      public:
        Time (Path const& file,
              unsigned long line,
              unsigned long column);
      };

      // Entity
      //
      class LIBXSD_FRONTEND_SYMEXPORT Entity: public virtual Type
      {
      public:
        Entity (Path const& file,
                unsigned long line,
                unsigned long column);
      };

      // Entities
      //
      class LIBXSD_FRONTEND_SYMEXPORT Entities: public virtual Type
      {
      public:
        Entities (Path const& file,
                  unsigned long line,
                  unsigned long column);
      };

      // Notation
      //
      class LIBXSD_FRONTEND_SYMEXPORT Notation: public virtual Type
      {
      public:
        Notation (Path const& file,
                  unsigned long line,
                  unsigned long column);
      };
    }
  }
}

#endif  // LIBXSD_FRONTEND_SEMANTIC_GRAPH_FUNDAMENTAL_HXX
