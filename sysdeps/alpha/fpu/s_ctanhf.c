/* Return hyperbole tangent of complex float value.
   Copyright (C) 2004-2025 Free Software Foundation, Inc.
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
   License along with the GNU C Library.  If not, see
   <https://www.gnu.org/licenses/>.  */

#define __ctanhf __ctanhf_not_defined
#define ctanhf ctanhf_not_defined

#include <complex.h>
#include <math.h>

#undef __ctanhf
#undef ctanhf

static _Complex float internal_ctanhf (_Complex float x);

#define M_DECL_FUNC(f) internal_ctanhf
#include <math-type-macros-float.h>

/* Disable any aliasing from base template.  */
#undef declare_mgen_alias
#define declare_mgen_alias(__to, __from)

#include <math/s_ctanh_template.c>
#include "cfloat-compat.h"

c1_cfloat_rettype
__c1_ctanhf (c1_cfloat_decl (x))
{
  _Complex float r = internal_ctanhf (c1_cfloat_value (x));
  return c1_cfloat_return (r);
}

c2_cfloat_rettype
__c2_ctanhf (c2_cfloat_decl (x))
{
  _Complex float r = internal_ctanhf (c2_cfloat_value (x));
  return c2_cfloat_return (r);
}

cfloat_versions (ctanh);
