// file      : libxsd-frontend/types.cxx
// license   : GNU GPL v2 + exceptions; see accompanying LICENSE file

#include <cstdlib> // std::mbstowcs

#include <libxsd-frontend/types.hxx>
#include <libxsd-frontend/export.hxx>

namespace XSDFrontend
{
  // NonRepresentable
  //
  char const* NonRepresentable::
  what () const throw ()
  {
    return "character is not representable in the narrower encoding";
  }

  // StringTemplate
  //

  // Specialization for char to wchar_t conversion.
  //
  template <>
  LIBXSD_FRONTEND_SYMEXPORT void StringTemplate<wchar_t, char>::
  from_narrow (char const* s)
  {
    size_type size (std::mbstowcs (0, s, 0) + 1);

    // I dare to change the guts!
    //
    resize (size - 1);

    wchar_t* p (const_cast<wchar_t*> (data ()));

    std::mbstowcs (p, s, size);
  }

  // Specialization for wchar_t to char conversion.
  //
  template <>
  LIBXSD_FRONTEND_SYMEXPORT StringTemplate<char>
  StringTemplate<wchar_t, char>::
  to_narrow () const
  {
    size_type size (std::wcstombs (0, c_str (), 0));

    if (size == size_type (-1))
      throw NonRepresentable ();

    // I dare to change the guts!
    //
    StringTemplate<char> r;
    r.resize (size);

    char* p (const_cast<char*> (r.data ()));

    std::wcstombs (p, c_str (), size + 1);

    return r;
  }
}
