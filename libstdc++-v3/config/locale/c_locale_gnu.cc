// Wrapper for underlying C-language localization -*- C++ -*-

// Copyright (C) 2001 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
// USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

//
// ISO C++ 14882: 22.8  Standard locale categories.
//

// Written by Benjamin Kosnik <bkoz@redhat.com>

#include <locale>
#include <stdexcept>
#include <langinfo.h>

namespace std 
{
  void
  locale::facet::_S_create_c_locale(__c_locale& __cloc, const char* __s)
  {
    // XXX
    // Perhaps locale::categories could be made equivalent to LC_*_MASK ?
    // _M_c_locale = __newlocale(1 << LC_ALL, __s, 0);
    // _M_c_locale = __newlocale(locale::all, __s, 0);
    __cloc = __newlocale(1 << LC_ALL, __s, 0);
    if (!__cloc)
      {
	// This named locale is not supported by the underlying OS.
	__throw_runtime_error("attempt to create locale from unknown name");
      }
  }
  
  void
  locale::facet::_S_destroy_c_locale(__c_locale& __cloc)
  { __freelocale(__cloc); }

  __c_locale
  locale::facet::_S_clone_c_locale(__c_locale& __cloc)
  { return __duplocale(__cloc); }
}  // namespace std