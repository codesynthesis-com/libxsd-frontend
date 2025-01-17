// file      : libxsd-frontend/semantic-graph/fundamental.cxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <libcutl/compiler/type-info.hxx>

#include <libxsd-frontend/semantic-graph/fundamental.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    namespace Fundamental
    {
      using compiler::type_info;

      // Type
      //
      namespace
      {
        struct TypeInit
        {
          TypeInit ()
          {
            type_info ti (typeid (Type));
            ti.add_base (typeid (SemanticGraph::Type));
            insert (ti);
          }
        } any_type_init_;
      }

      Type::
      Type ()
      {
      }

      // Byte
      //
      namespace
      {
        struct ByteInit
        {
          ByteInit ()
          {
            type_info ti (typeid (Byte));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } byte_init_;
      }

      Byte::
      Byte (Path const& file,
            unsigned long line,
            unsigned long column)
          : Node (file, line, column)
      {
      }

      // UnsignedByte
      //
      namespace
      {
        struct UnsignedByteInit
        {
          UnsignedByteInit ()
          {
            type_info ti (typeid (UnsignedByte));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } unsigned_byte_init_;
      }

      UnsignedByte::
      UnsignedByte (Path const& file,
                    unsigned long line,
                    unsigned long column)
          : Node (file, line, column)
      {
      }

      // Short
      //
      namespace
      {
        struct ShortInit
        {
          ShortInit ()
          {
            type_info ti (typeid (Short));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } short_init_;
      }

      Short::
      Short (Path const& file,
             unsigned long line,
             unsigned long column)
          : Node (file, line, column)
      {
      }

      // UnsignedShort
      //
      namespace
      {
        struct UnsignedShortInit
        {
          UnsignedShortInit ()
          {
            type_info ti (typeid (UnsignedShort));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } unsigned_short_init_;
      }

      UnsignedShort::
      UnsignedShort (Path const& file,
                     unsigned long line,
                     unsigned long column)
          : Node (file, line, column)
      {
      }

      // Int
      //
      namespace
      {
        struct IntInit
        {
          IntInit ()
          {
            type_info ti (typeid (Int));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } int_init_;
      }

      Int::
      Int (Path const& file,
           unsigned long line,
           unsigned long column)
          : Node (file, line, column)
      {
      }

      // UnsignedInt
      //
      namespace
      {
        struct UnsignedIntInit
        {
          UnsignedIntInit ()
          {
            type_info ti (typeid (UnsignedInt));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } unsigned_int_init_;
      }

      UnsignedInt::
      UnsignedInt (Path const& file,
                   unsigned long line,
                   unsigned long column)
          : Node (file, line, column)
      {
      }

      // Long
      //
      namespace
      {
        struct LongInit
        {
          LongInit ()
          {
            type_info ti (typeid (Long));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } long_init_;
      }

      Long::
      Long (Path const& file,
            unsigned long line,
            unsigned long column)
          : Node (file, line, column)
      {
      }

      // UnsignedLong
      //
      namespace
      {
        struct UnsignedLongInit
        {
          UnsignedLongInit ()
          {
            type_info ti (typeid (UnsignedLong));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } unsigned_long_init_;
      }

      UnsignedLong::
      UnsignedLong (Path const& file,
                    unsigned long line,
                    unsigned long column)
          : Node (file, line, column)
      {
      }

      // Integer
      //
      namespace
      {
        struct IntegerInit
        {
          IntegerInit ()
          {
            type_info ti (typeid (Integer));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } integer_init_;
      }

      Integer::
      Integer (Path const& file,
               unsigned long line,
               unsigned long column)
          : Node (file, line, column)
      {
      }

      // NonPositiveInteger
      //
      namespace
      {
        struct NonPositiveIntegerInit
        {
          NonPositiveIntegerInit ()
          {
            type_info ti (typeid (NonPositiveInteger));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } non_positive_integer_init_;
      }

      NonPositiveInteger::
      NonPositiveInteger (Path const& file,
                          unsigned long line,
                          unsigned long column)
          : Node (file, line, column)
      {
      }

      // NonNegativeInteger
      //
      namespace
      {
        struct NonNegativeIntegerInit
        {
          NonNegativeIntegerInit ()
          {
            type_info ti (typeid (NonNegativeInteger));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } non_negative_integer_init_;
      }

      NonNegativeInteger::
      NonNegativeInteger (Path const& file,
                          unsigned long line,
                          unsigned long column)
          : Node (file, line, column)
      {
      }

      // PositiveInteger
      //
      namespace
      {
        struct PositiveIntegerInit
        {
          PositiveIntegerInit ()
          {
            type_info ti (typeid (PositiveInteger));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } positive_integer_init_;
      }

      PositiveInteger::
      PositiveInteger (Path const& file,
                       unsigned long line,
                       unsigned long column)
          : Node (file, line, column)
      {
      }

      // NegativeInteger
      //
      namespace
      {
        struct NegativeIntegerInit
        {
          NegativeIntegerInit ()
          {
            type_info ti (typeid (NegativeInteger));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } negative_integer_init_;
      }

      NegativeInteger::
      NegativeInteger (Path const& file,
                       unsigned long line,
                       unsigned long column)
          : Node (file, line, column)
      {
      }

      // Boolean
      //
      namespace
      {
        struct BooleanInit
        {
          BooleanInit ()
          {
            type_info ti (typeid (Boolean));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } boolean_init_;
      }

      Boolean::
      Boolean (Path const& file,
               unsigned long line,
               unsigned long column)
          : Node (file, line, column)
      {
      }

      // Float
      //
      namespace
      {
        struct FloatInit
        {
          FloatInit ()
          {
            type_info ti (typeid (Float));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } float_init_;
      }

      Float::
      Float (Path const& file,
             unsigned long line,
             unsigned long column)
          : Node (file, line, column)
      {
      }

      // Double
      //
      namespace
      {
        struct DoubleInit
        {
          DoubleInit ()
          {
            type_info ti (typeid (Double));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } double_init_;
      }

      Double::
      Double (Path const& file,
              unsigned long line,
              unsigned long column)
          : Node (file, line, column)
      {
      }

      // Decimal
      //
      namespace
      {
        struct DecimalInit
        {
          DecimalInit ()
          {
            type_info ti (typeid (Decimal));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } decimal_init_;
      }

      Decimal::
      Decimal (Path const& file,
               unsigned long line,
               unsigned long column)
          : Node (file, line, column)
      {
      }

      // String
      //
      namespace
      {
        struct StringInit
        {
          StringInit ()
          {
            type_info ti (typeid (String));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } string_init_;
      }

      String::
      String (Path const& file,
              unsigned long line,
              unsigned long column)
          : Node (file, line, column)
      {
      }

      // NormalizedString
      //
      namespace
      {
        struct NormalizedStringInit
        {
          NormalizedStringInit ()
          {
            type_info ti (typeid (NormalizedString));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } normalized_string_init_;
      }

      NormalizedString::
      NormalizedString (Path const& file,
                        unsigned long line,
                        unsigned long column)
          : Node (file, line, column)
      {
      }

      // Token
      //
      namespace
      {
        struct TokenInit
        {
          TokenInit ()
          {
            type_info ti (typeid (Token));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } token_init_;
      }

      Token::
      Token (Path const& file,
             unsigned long line,
             unsigned long column)
          : Node (file, line, column)
      {
      }

      // Name
      //
      namespace
      {
        struct NameInit
        {
          NameInit ()
          {
            type_info ti (typeid (Name));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } name_init_;
      }

      Name::
      Name (Path const& file,
            unsigned long line,
            unsigned long column)
          : Node (file, line, column)
      {
      }


      // NameToken
      //
      namespace
      {
        struct NameTokenInit
        {
          NameTokenInit ()
          {
            type_info ti (typeid (NameToken));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } name_token_init_;
      }

      NameToken::
      NameToken (Path const& file,
                 unsigned long line,
                 unsigned long column)
          : Node (file, line, column)
      {
      }

      // NameTokens
      //
      namespace
      {
        struct NameTokensInit
        {
          NameTokensInit ()
          {
            type_info ti (typeid (NameTokens));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } name_tokens_init_;
      }

      NameTokens::
      NameTokens (Path const& file,
                  unsigned long line,
                  unsigned long column)
          : Node (file, line, column)
      {
      }

      // NCName
      //
      namespace
      {
        struct NCNameInit
        {
          NCNameInit ()
          {
            type_info ti (typeid (NCName));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } NC_name_init_;
      }

      NCName::
      NCName (Path const& file,
              unsigned long line,
              unsigned long column)
          : Node (file, line, column)
      {
      }

      // Language
      //
      namespace
      {
        struct LanguageInit
        {
          LanguageInit ()
          {
            type_info ti (typeid (Language));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } language_init_;
      }

      Language::
      Language (Path const& file,
                unsigned long line,
                unsigned long column)
          : Node (file, line, column)
      {
      }

      // QName
      //
      namespace
      {
        struct QNameInit
        {
          QNameInit ()
          {
            type_info ti (typeid (QName));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } q_name_init_;
      }

      QName::
      QName (Path const& file,
             unsigned long line,
             unsigned long column)
          : Node (file, line, column)
      {
      }

      // Id
      //
      namespace
      {
        struct IdInit
        {
          IdInit ()
          {
            type_info ti (typeid (Id));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } id_init_;
      }

      Id::
      Id (Path const& file,
          unsigned long line,
          unsigned long column)
          : Node (file, line, column)
      {
      }

      // IdRef
      //
      namespace
      {
        struct IdRefInit
        {
          IdRefInit ()
          {
            type_info ti (typeid (IdRef));
            ti.add_base (typeid (Type));
            ti.add_base (typeid (Specialization));
            insert (ti);
          }

        } id_ref_init_;
      }

      IdRef::
      IdRef (Path const& file,
             unsigned long line,
             unsigned long column)
          : Node (file, line, column)
      {
      }

      // IdRefs
      //
      namespace
      {
        struct IdRefsInit
        {
          IdRefsInit ()
          {
            type_info ti (typeid (IdRefs));
            ti.add_base (typeid (Type));
            ti.add_base (typeid (Specialization));
            insert (ti);
          }

        } id_refs_init_;
      }

      IdRefs::
      IdRefs (Path const& file,
              unsigned long line,
              unsigned long column)
          : Node (file, line, column)
      {
      }

      // AnyURI
      //
      namespace
      {
        struct AnyURIInit
        {
          AnyURIInit ()
          {
            type_info ti (typeid (AnyURI));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } any_URI_init_;
      }

      AnyURI::
      AnyURI (Path const& file,
              unsigned long line,
              unsigned long column)
          : Node (file, line, column)
      {
      }

      // Base64Binary
      //
      namespace
      {
        struct Base64BinaryInit
        {
          Base64BinaryInit ()
          {
            type_info ti (typeid (Base64Binary));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } base_64_binary_init_;
      }

      Base64Binary::
      Base64Binary (Path const& file,
                    unsigned long line,
                    unsigned long column)
          : Node (file, line, column)
      {
      }

      // HexBinary
      //
      namespace
      {
        struct HexBinaryInit
        {
          HexBinaryInit ()
          {
            type_info ti (typeid (HexBinary));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } hex_binary_init_;
      }

      HexBinary::
      HexBinary (Path const& file,
                 unsigned long line,
                 unsigned long column)
          : Node (file, line, column)
      {
      }

      // Date
      //
      namespace
      {
        struct DateInit
        {
          DateInit ()
          {
            type_info ti (typeid (Date));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } date_init_;
      }

      Date::
      Date (Path const& file,
            unsigned long line,
            unsigned long column)
          : Node (file, line, column)
      {
      }

      // DateTime
      //
      namespace
      {
        struct DateTimeInit
        {
          DateTimeInit ()
          {
            type_info ti (typeid (DateTime));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } date_time_init_;
      }

      DateTime::
      DateTime (Path const& file,
                unsigned long line,
                unsigned long column)
          : Node (file, line, column)
      {
      }

      // Duration
      //
      namespace
      {
        struct DurationInit
        {
          DurationInit ()
          {
            type_info ti (typeid (Duration));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } duration_init_;
      }

      Duration::
      Duration (Path const& file,
                unsigned long line,
                unsigned long column)
          : Node (file, line, column)
      {
      }

      // Day
      //
      namespace
      {
        struct DayInit
        {
          DayInit ()
          {
            type_info ti (typeid (Day));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } day_init_;
      }

      Day::
      Day (Path const& file,
           unsigned long line,
           unsigned long column)
          : Node (file, line, column)
      {
      }

      // Month
      //
      namespace
      {
        struct MonthInit
        {
          MonthInit ()
          {
            type_info ti (typeid (Month));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } month_init_;
      }

      Month::
      Month (Path const& file,
             unsigned long line,
             unsigned long column)
          : Node (file, line, column)
      {
      }

      // MonthDay
      //
      namespace
      {
        struct MonthDayInit
        {
          MonthDayInit ()
          {
            type_info ti (typeid (MonthDay));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } month_day_init_;
      }

      MonthDay::
      MonthDay (Path const& file,
                unsigned long line,
                unsigned long column)
          : Node (file, line, column)
      {
      }

      // Year
      //
      namespace
      {
        struct YearInit
        {
          YearInit ()
          {
            type_info ti (typeid (Year));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } year_init_;
      }

      Year::
      Year (Path const& file,
            unsigned long line,
            unsigned long column)
          : Node (file, line, column)
      {
      }

      // YearMonth
      //
      namespace
      {
        struct YearMonthInit
        {
          YearMonthInit ()
          {
            type_info ti (typeid (YearMonth));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } year_month_init_;
      }

      YearMonth::
      YearMonth (Path const& file,
                 unsigned long line,
                 unsigned long column)
          : Node (file, line, column)
      {
      }

      // Time
      //
      namespace
      {
        struct TimeInit
        {
          TimeInit ()
          {
            type_info ti (typeid (Time));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } time_init_;
      }

      Time::
      Time (Path const& file,
            unsigned long line,
            unsigned long column)
          : Node (file, line, column)
      {
      }

      // Entity
      //
      namespace
      {
        struct EntityInit
        {
          EntityInit ()
          {
            type_info ti (typeid (Entity));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } entity_init_;
      }

      Entity::
      Entity (Path const& file,
              unsigned long line,
              unsigned long column)
          : Node (file, line, column)
      {
      }

      // Entities
      //
      namespace
      {
        struct EntitiesInit
        {
          EntitiesInit ()
          {
            type_info ti (typeid (Entities));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } entities_init_;
      }

      Entities::
      Entities (Path const& file,
                unsigned long line,
                unsigned long column)
          : Node (file, line, column)
      {
      }

      // Notation
      //
      namespace
      {
        struct NotationInit
        {
          NotationInit ()
          {
            type_info ti (typeid (Notation));
            ti.add_base (typeid (Type));
            insert (ti);
          }

        } notation_init_;
      }

      Notation::
      Notation (Path const& file,
                unsigned long line,
                unsigned long column)
          : Node (file, line, column)
      {
      }
    }
  }
}
