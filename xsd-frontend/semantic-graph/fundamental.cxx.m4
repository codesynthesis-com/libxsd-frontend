divert(-1)

# file      : xsd-frontend/semantic-graph/fundamental.cxx.m4
# author    : Boris Kolpackov <boris@codesynthesis.com>
# copyright : Copyright (c) 2005-2010 Code Synthesis Tools CC
# license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

include(`fundamental.m4')

define(`fundamental_type',
  `fundamental_type_impl(`make_class_name(`$1')', `make_var_name(`$1')')')


define(`fundamental_type_impl', `

      // $1
      //
      namespace
      {
        struct $1Init
        {
          $1Init ()
          {
            TypeInfo ti (typeid ($1));
            ti.add_base (Access::public_, true, typeid (Type));
            RTTI::insert (ti);
          }

        } $2_init_;
      }

      $1::
      $1 (Path const& file,
          SemanticGraph::UnsignedLong line,
          SemanticGraph::UnsignedLong column)
        : Node (file, line, column)
      {
      }')

divert(0)dnl
dnl
dnl
dnl
// file      : xsd-frontend/semantic-graph/fundamental.cxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : Copyright (c) 2005-2010 Code Synthesis Tools CC
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

// Note, that this file is automatically generated!
//

#include <xsd-frontend/semantic-graph/fundamental.hxx>

namespace XSDFrontend
{
  namespace SemanticGraph
  {
    namespace Fundamental
    {
      namespace RTTI = Cult::RTTI;

      using RTTI::Access;
      using RTTI::TypeInfo;


      // Type
      //
      namespace
      {
        struct TypeInit
        {
          TypeInit ()
          {
            TypeInfo ti (typeid (Type));
            ti.add_base (Access::public_, true, typeid (SemanticGraph::Type));
            RTTI::insert (ti);
          }

        } any_type_init_;
      }

      Type::
      Type ()
      {
      }
dnl
dnl Integers.
dnl
fundamental_type(`byte')
fundamental_type(`unsigned byte')
fundamental_type(`short')
fundamental_type(`unsigned short')
fundamental_type(`int')
fundamental_type(`unsigned int')
fundamental_type(`long')
fundamental_type(`unsigned long')
fundamental_type(`integer')
fundamental_type(`non positive integer')
fundamental_type(`non negative integer')
fundamental_type(`positive integer')
fundamental_type(`negative integer')
dnl
dnl Boolean.
dnl
fundamental_type(`boolean')
dnl
dnl Floats.
dnl
fundamental_type(`float')
fundamental_type(`double')
fundamental_type(`decimal')
dnl
dnl Strings.
dnl
fundamental_type(`string')
fundamental_type(`normalized string')
fundamental_type(`token')
fundamental_type(`name')
fundamental_type(`name token')
fundamental_type(`name tokens')
fundamental_type(`NC name')
fundamental_type(`language')
dnl
dnl Qualified name.
dnl
fundamental_type(`q name')
dnl
dnl ID/IDREF.
dnl
fundamental_type(`id')


      // IdRef
      //
      namespace
      {
        struct IdRefInit
        {
          IdRefInit ()
          {
            TypeInfo ti (typeid (IdRef));
	    ti.add_base (Access::public_, true, typeid (Type));
            ti.add_base (Access::public_, true, typeid (Specialization));
            RTTI::insert (ti);
          }

        } id_ref_init_;
      }

      IdRef::
      IdRef (Path const& file,
             SemanticGraph::UnsignedLong line,
             SemanticGraph::UnsignedLong column)
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
            TypeInfo ti (typeid (IdRefs));
	    ti.add_base (Access::public_, true, typeid (Type));
            ti.add_base (Access::public_, true, typeid (Specialization));
            RTTI::insert (ti);
          }

        } id_refs_init_;
      }

      IdRefs::
      IdRefs (Path const& file,
              SemanticGraph::UnsignedLong line,
              SemanticGraph::UnsignedLong column)
          : Node (file, line, column)
      {
      }
dnl
dnl URI.
dnl
fundamental_type(`any URI')
dnl
dnl Binary.
dnl
fundamental_type(`base 64 binary')
fundamental_type(`hex binary')
dnl
dnl Date/time.
dnl
fundamental_type(`date')
fundamental_type(`date time')
fundamental_type(`duration')
fundamental_type(`day')
fundamental_type(`month')
fundamental_type(`month day')
fundamental_type(`year')
fundamental_type(`year month')
fundamental_type(`time')
dnl
dnl Entity.
dnl
fundamental_type(`entity')
fundamental_type(`entities')
dnl
dnl Notation.
dnl
fundamental_type(`notation')
dnl
    }
  }
}
