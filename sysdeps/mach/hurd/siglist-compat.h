/* Compatibility signal numbers and their names symbols.  Hurd version.
   Copyright (C) 1997-2025 Free Software Foundation, Inc.
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

#include <siglist-compat-def.h>
/* To get _NSIG definition.  */
#define _SIGNAL_H
#include <bits/signum-generic.h>

#if SHLIB_COMPAT (libc, GLIBC_2_0, GLIBC_2_1)
DEFINE_COMPAT_SIGLIST (33, GLIBC_2_0)
#endif

#if SHLIB_COMPAT (libc, GLIBC_2_1, GLIBC_2_32)
DEFINE_COMPAT_SIGLIST (_NSIG, GLIBC_2_1)
#endif
