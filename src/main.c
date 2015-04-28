/* main.c

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

#include <gmp.h>
#include <stdio.h>
#include "date.h"
#include <locale.h>

#define		LIMIT		1l * 1000l * 1000l


int main(int argc, char * argv[]) {
    setlocale(LC_NUMERIC, "");
    printf("Starting numeric calculations (%'d iterations) ...\n", LIMIT);
    long start, end;

    start = get_time();
    mpz_t result;
    mpz_init(result);                                       // var result = 0
    mpz_set_str(result, "1", 10);                           // result = 1 ("1" expressed in base 10)
    for (long i=0; i<LIMIT; i++) {
        mpz_add(result, result, result);                    // result = result + result
        //mpz_out_str(stdout, 10, result); printf("\n");    // Print value in base 10
    }
    mpz_clear(result);                                      // Free spaces
    end = get_time();
    double duration = ( ((double)end) - ((double)start) ) / 1000.0;
    printf("... numeric calculations done in %.3f seconds.\n", duration);
    return 0;
}
