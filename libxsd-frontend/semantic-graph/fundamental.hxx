// file      : libxsd-frontend/semantic-graph/fundamental.hxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#ifndef LIBXSD_FRONTEND_SEMANTIC_GRAPH_FUNDAMENTAL_HXX
#define LIBXSD_FRONTEND_SEMANTIC_GRAPH_FUNDAMENTAL_HXX

#include <libxsd-frontend/semantic-graph/elements.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    namespace Fundamental
    {
      // Type
      //
      class Type: public virtual SemanticGraph::Type
      {
      protected:
        Type ();
      };

      // Byte
      //
      class Byte: public virtual Type
      {
      public:
        Byte (Path const& file,
              unsigned long line,
              unsigned long column);
      };

      // UnsignedByte
      //
      class UnsignedByte: public virtual Type
      {
      public:
        UnsignedByte (Path const& file,
                      unsigned long line,
                      unsigned long column);
      };

      // Short
      //
      class Short: public virtual Type
      {
      public:
        Short (Path const& file,
               unsigned long line,
               unsigned long column);
      };

      // UnsignedShort
      //
      class UnsignedShort: public virtual Type
      {
      public:
        UnsignedShort (Path const& file,
                       unsigned long line,
                       unsigned long column);
      };

      // Int
      //
      class Int: public virtual Type
      {
      public:
        Int (Path const& file,
             unsigned long line,
             unsigned long column);
      };

      // UnsignedInt
      //
      class UnsignedInt: public virtual Type
      {
      public:
        UnsignedInt (Path const& file,
                     unsigned long line,
                     unsigned long column);
      };

      // Long
      //
      class Long: public virtual Type
      {
      public:
        Long (Path const& file,
              unsigned long line,
              unsigned long column);
      };

      // UnsignedLong
      //
      class UnsignedLong: public virtual Type
      {
      public:
        UnsignedLong (Path const& file,
                      unsigned long line,
                      unsigned long column);
      };

      // Integer
      //
      class Integer: public virtual Type
      {
      public:
        Integer (Path const& file,
                 unsigned long line,
                 unsigned long column);
      };

      // NonPositiveInteger
      //
      class NonPositiveInteger: public virtual Type
      {
      public:
        NonPositiveInteger (Path const& file,
                            unsigned long line,
                            unsigned long column);
      };

      // NonNegativeInteger
      //
      class NonNegativeInteger: public virtual Type
      {
      public:
        NonNegativeInteger (Path const& file,
                            unsigned long line,
                            unsigned long column);
      };

      // PositiveInteger
      //
      class PositiveInteger: public virtual Type
      {
      public:
        PositiveInteger (Path const& file,
                         unsigned long line,
                         unsigned long column);
      };

      // NegativeInteger
      //
      class NegativeInteger: public virtual Type
      {
      public:
        NegativeInteger (Path const& file,
                         unsigned long line,
                         unsigned long column);
      };

      // Boolean
      //
      class Boolean: public virtual Type
      {
      public:
        Boolean (Path const& file,
                 unsigned long line,
                 unsigned long column);
      };

      // Float
      //
      class Float: public virtual Type
      {
      public:
        Float (Path const& file,
               unsigned long line,
               unsigned long column);
      };

      // Double
      //
      class Double: public virtual Type
      {
      public:
        Double (Path const& file,
                unsigned long line,
                unsigned long column);
      };

      // Decimal
      //
      class Decimal: public virtual Type
      {
      public:
        Decimal (Path const& file,
                 unsigned long line,
                 unsigned long column);
      };

      // String
      //
      class String: public virtual Type
      {
      public:
        String (Path const& file,
                unsigned long line,
                unsigned long column);
      };

      // NormalizedString
      //
      class NormalizedString: public virtual Type
      {
      public:
        NormalizedString (Path const& file,
                          unsigned long line,
                          unsigned long column);
      };

      // Token
      //
      class Token: public virtual Type
      {
      public:
        Token (Path const& file,
               unsigned long line,
               unsigned long column);
      };

      // Name
      //
      class Name: public virtual Type
      {
      public:
        Name (Path const& file,
              unsigned long line,
              unsigned long column);
      };

      // NameToken
      //
      class NameToken: public virtual Type
      {
      public:
        NameToken (Path const& file,
                   unsigned long line,
                   unsigned long column);
      };

      // NameTokens
      //
      class NameTokens: public virtual Type
      {
      public:
        NameTokens (Path const& file,
                    unsigned long line,
                    unsigned long column);
      };

      // NCName
      //
      class NCName: public virtual Type
      {
      public:
        NCName (Path const& file,
                unsigned long line,
                unsigned long column);
      };

      // Language
      //
      class Language: public virtual Type
      {
      public:
        Language (Path const& file,
                  unsigned long line,
                  unsigned long column);
      };

      // QName
      //
      class QName: public virtual Type
      {
      public:
        QName (Path const& file,
               unsigned long line,
               unsigned long column);
      };

      // Id
      //
      class Id: public virtual Type
      {
      public:
        Id (Path const& file,
            unsigned long line,
            unsigned long column);
      };

      // IdRef
      //
      class IdRef: public virtual Type,
                   public virtual Specialization
      {
      public:
        IdRef (Path const& file,
               unsigned long line,
               unsigned long column);
      };

      // IdRefs
      //
      class IdRefs: public virtual Type,
                    public virtual Specialization
      {
      public:
        IdRefs (Path const& file,
                unsigned long line,
                unsigned long column);
      };

      // AnyURI
      //
      class AnyURI: public virtual Type
      {
      public:
        AnyURI (Path const& file,
                unsigned long line,
                unsigned long column);
      };

      // Base64Binary
      //
      class Base64Binary: public virtual Type
      {
      public:
        Base64Binary (Path const& file,
                      unsigned long line,
                      unsigned long column);
      };

      // HexBinary
      //
      class HexBinary: public virtual Type
      {
      public:
        HexBinary (Path const& file,
                   unsigned long line,
                   unsigned long column);
      };

      // Date
      //
      class Date: public virtual Type
      {
      public:
        Date (Path const& file,
              unsigned long line,
              unsigned long column);
      };

      // DateTime
      //
      class DateTime: public virtual Type
      {
      public:
        DateTime (Path const& file,
                  unsigned long line,
                  unsigned long column);
      };

      // Duration
      //
      class Duration: public virtual Type
      {
      public:
        Duration (Path const& file,
                  unsigned long line,
                  unsigned long column);
      };

      // Day
      //
      class Day: public virtual Type
      {
      public:
        Day (Path const& file,
             unsigned long line,
             unsigned long column);
      };

      // Month
      //
      class Month: public virtual Type
      {
      public:
        Month (Path const& file,
               unsigned long line,
               unsigned long column);
      };

      // MonthDay
      //
      class MonthDay: public virtual Type
      {
      public:
        MonthDay (Path const& file,
                  unsigned long line,
                  unsigned long column);
      };

      // Year
      //
      class Year: public virtual Type
      {
      public:
        Year (Path const& file,
              unsigned long line,
              unsigned long column);
      };

      // YearMonth
      //
      class YearMonth: public virtual Type
      {
      public:
        YearMonth (Path const& file,
                   unsigned long line,
                   unsigned long column);
      };

      // Time
      //
      class Time: public virtual Type
      {
      public:
        Time (Path const& file,
              unsigned long line,
              unsigned long column);
      };

      // Entity
      //
      class Entity: public virtual Type
      {
      public:
        Entity (Path const& file,
                unsigned long line,
                unsigned long column);
      };

      // Entities
      //
      class Entities: public virtual Type
      {
      public:
        Entities (Path const& file,
                  unsigned long line,
                  unsigned long column);
      };

      // Notation
      //
      class Notation: public virtual Type
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
