/* Change access and modification times of open file.  Hurd version.
   Copyright (C) 1991-2025 Free Software Foundation, Inc.
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

#include <sys/time.h>
#include <errno.h>
#include <stddef.h>
#include <hurd.h>
#include <hurd/fd.h>

#include "utime-helper.c"

/* Change the access time of FILE to TSP[0] and
   the modification time of FILE to TSP[1].  */
int
utimensat (int fd, const char *file, const struct timespec tsp[2],
	   int flags)
{
  error_t err;
  file_t port;

  if (file)
    {
      port = __file_name_lookup_at (fd, flags, file, 0, 0);
      if (port == MACH_PORT_NULL)
	return -1;

      err = hurd_futimens (port, tsp);

      __mach_port_deallocate (__mach_task_self (), port);
    }
  else
    err = HURD_DPORT_USE (fd, hurd_futimens (port, tsp));

  if (err)
    return __hurd_fail (err);
  return 0;
}
