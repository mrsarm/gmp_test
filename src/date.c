/* date.c

   Copyright (C) 2015 Mariano Ruiz <mrsarm@gmail.com>
   This file is part of the gmp_test C-project.

   The gmp_test C-project is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */


#define _POSIX_C_SOURCE 200809L

#include "date.h"
#include <stdio.h>
#include <time.h>

long get_time() {
    long ms; // Milliseconds
    long s;  // Seconds
    struct timespec spec;

    clock_gettime(CLOCK_REALTIME, &spec);

    s  = spec.tv_sec;
    ms = spec.tv_nsec / 1.0e6; // Convert nanoseconds to milliseconds
    return (s*1000l) + ms;
}
