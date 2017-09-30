/*
 * The MIT License
 *
 * Copyright 2016 Anthony Campbell.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
/**
 * @author Anthony Campbell contact@claydonkey.com
 */

/*
 * File:   main.h
 * Author: Anthony Campbell
 *
 * Created on 06 October 2016, 13:49
 */

#include <gmp.h>


#ifndef MAIN_H
    #define MAIN_H


/*
 * The MIT License
 *
 * Copyright 2016 Anthony Campbell.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
/**
 * @author Anthony Campbell contact@claydonkey.com
 */

#   ifdef GMGMP_EXPORTS
#       define gmexport __declspec(dllexport)
#   else
#       define gmexport __declspec(dllimport)
#   endif

#ifdef __cplusplus
extern "C" {
    #endif



void make_returnstring_base(mpz_t a, int b);

void make_returnstring_bin(mpz_t a);

void make_returnstring_dec(mpz_t a);

void make_returnstring_hex(mpz_t a);

gmexport double gmp_real(char const* a_string);

gmexport char const* gmp_string(double a_real);

gmexport char const* gmp_tohex(char const* a_string);

gmexport char const* gmp_tobin(char const* a_string);

gmexport char const* gmp_tobase(char const* a_string, int b);

gmexport char const * gmp_todec(char const* a_string);

gmexport char const* gmp_add(char const* a_string, char const* b_string);

gmexport char const* gmp_sub(char const* a_string, char const* b_string);

gmexport char const* gmp_mul(char const* a_string, char const* b_string);

gmexport char const* gmp_div(char const* a_string, char const* b_string);

gmexport char const* gmp_mod(char const* a_string, char const* b_string);

gmexport char const* gmp_neg(char const* a_string);

gmexport char const* gmp_abs(char const* a_string);

gmexport char const* gmp_pow(char const* base_string, char const* n_string);

gmexport char const* gmp_powmod(char const* base_string, char const* n_string, char const* mod_string);

gmexport char const* gmp_sqrt(char const* a_string);

gmexport char const* gmp_sqrtrem(char const* a_string);

gmexport char const* gmp_root(char const* a_string, char const* n_string);

gmexport char const* gmp_rootrem(char const* a_string, char const* n_string);

gmexport double gmp_compare(char const* a_string, char const* b_string);

gmexport double gmp_abscompare(char const* a_string, char const* b_string);

gmexport double gmp_sign(char const* a_string);

gmexport double gmp_even(char const* a_string);

gmexport double gmp_odd(char const* a_string);

gmexport double gmp_probab_prime(char const* a_string, double reps);

gmexport char const * gmp_probab_nextprime(char const* a_string);

gmexport char const * gmp_gcd(char const* a_string, char const* b_string);

gmexport char const * gmp_lcm(char const* a_string, char const* b_string);

gmexport char const * gmp_factorial(char const* n_string);

gmexport char const * gmp_fibonacci(char const* n_string);

gmexport char const * gmp_min(char const* a_string, char const* b_string);

gmexport char const * gmp_max(char const* a_string, char const* b_string);




    #ifdef __cplusplus
}
    #endif
#endif // MAIN_H



