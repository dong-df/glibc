/* Function to parse an `unsigned long long int' from text.
   Copyright (C) 1995-2025 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#define	QUAD	1

#include <strtoul.c>

#ifdef _LIBC
# ifdef SHARED
#  include <shlib-compat.h>

#  if SHLIB_COMPAT (libc, GLIBC_2_0, GLIBC_2_2)
compat_symbol (libc, __strtoull_internal, __strtouq_internal, GLIBC_2_0);
#  endif

# endif
weak_alias (strtoull, strtouq)
weak_alias (strtoull, strtoumax)
weak_alias (__isoc23_strtoull, __isoc23_strtoumax)
#endif
