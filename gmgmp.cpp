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

#include <cstdlib>
#include "gmgmp.h"
#include <gmp.h>
#include <string.h>


template<typename A> A gm_cast(double);

template<> inline unsigned long gm_cast<unsigned long>(double d) {
    if ((double) (unsigned long) (0) <= d && d <= (double) (unsigned long) (ULONG_MAX)) return (unsigned long) (d);
    else return 0;
}

template<> inline long gm_cast<long>(double d) {
    if ((double) (long) (LONG_MIN) <= d && d <= (double) (long) (LONG_MAX)) return (long) (d);
    else return 0;
}

template<> inline unsigned int gm_cast<unsigned int>(double d) {
    if ((double) (unsigned int) (0) <= d && d <= (double) (unsigned int) (UINT_MAX)) return (unsigned int) (d);
    else return 0;
}

template<> inline int gm_cast<int>(double d) {
    if ((double) (int) (INT_MIN) <= d && d <= (double) (int) (INT_MAX)) return (int) (d);
    else return 0;
}
/*template<> inline bool gm_cast<bool>(double d) {
	return (d>=0.5);
}*/



  char * returnstring = NULL;

void make_returnstring_base(mpz_t a, int b) {
    free((void*)returnstring);
    returnstring = (char *)(malloc(mpz_sizeinbase(a, b) + 2));
    if (returnstring == NULL) {
	returnstring = strdup("");
    } else {
	mpz_get_str((char*)returnstring, b, a);
    }
}

void make_returnstring_bin(mpz_t a) {
    free((char*)returnstring);
    returnstring = (char *) (malloc(mpz_sizeinbase(a, 2) + 4));
    if (returnstring == NULL) {
	returnstring = strdup("");
    } else {
	mpz_get_str((char*)returnstring + 2, 2, a);
	if (returnstring[2] == '-') {
	    returnstring[0] = '-';
	    returnstring[1] = '0';
	    returnstring[2] = 'b';
	} else {
	    returnstring[0] = '0';
	    returnstring[1] = 'b';
	}
    }
}

void make_returnstring_dec(mpz_t a) {
    free((char*)returnstring);
    returnstring = (char *) (malloc(mpz_sizeinbase(a, 10) + 2));
    if (returnstring == NULL) {
	returnstring = strdup("");
    } else {
	mpz_get_str(returnstring, 10, a);
    }
}

void make_returnstring_hex(mpz_t a) {
    free((char*)returnstring);
    returnstring = (char *) (malloc(mpz_sizeinbase(a, 16) + 4));
    if (returnstring == NULL) {
	returnstring = strdup("");
    } else {
	mpz_get_str(returnstring + 2, 16, a);
	if (returnstring[2] == '-') {
	    returnstring[0] = '-';
	    returnstring[1] = '0';
	    returnstring[2] = 'x';
	} else {
	    returnstring[0] = '0';
	    returnstring[1] = 'x';
	}
    }
}

gmexport double gmp_real(char const* a_string) {
    mpz_t a;
    mpz_init_set_str(a, a_string, 0);
    double result = mpz_get_d(a);
    mpz_clear(a);
    return result;
}

gmexport char const* gmp_string(double a_real) {
    mpz_t a;
    mpz_init_set_d(a, a_real);
    make_returnstring_hex(a);
    mpz_clear(a);
    return returnstring;
}

gmexport char const* gmp_tohex(char const* a_string) {
    mpz_t a;
    mpz_init_set_str(a, a_string, 0);
    make_returnstring_hex(a);
    mpz_clear(a);
    return returnstring;
}

gmexport char const* gmp_tobin(char const* a_string) {
    mpz_t a;
    mpz_init_set_str(a, a_string, 0);
    make_returnstring_bin(a);
    mpz_clear(a);
    return returnstring;
}

gmexport char const* gmp_tobase(char const* a_string, int b) {
    mpz_t a;
    mpz_init_set_str(a, a_string, 0);
    make_returnstring_base(a, b);
    mpz_clear(a);
    return returnstring;
}

gmexport char const* gmp_todec(char const* a_string) {
    mpz_t a;
    mpz_init_set_str(a, a_string, 0);
    make_returnstring_dec(a);
    mpz_clear(a);
    return returnstring;
}

gmexport char const* gmp_add(char const* a_string, char const* b_string) {
    mpz_t a, b;
    mpz_init_set_str(a, a_string, 0);
    mpz_init_set_str(b, b_string, 0);
    mpz_add(a, a, b);
    make_returnstring_hex(a);
    mpz_clear(a);
    mpz_clear(b);
    return returnstring;
}

gmexport char const* gmp_sub(char const* a_string, char const* b_string) {
    mpz_t a, b;
    mpz_init_set_str(a, a_string, 0);
    mpz_init_set_str(b, b_string, 0);
    mpz_sub(a, a, b);
    make_returnstring_hex(a);
    mpz_clear(a);
    mpz_clear(b);
    return returnstring;
}

gmexport char const* gmp_mul(char const* a_string, char const* b_string) {
    mpz_t a, b;
    mpz_init_set_str(a, a_string, 0);
    mpz_init_set_str(b, b_string, 0);
    mpz_mul(a, a, b);
    make_returnstring_hex(a);
    mpz_clear(a);
    mpz_clear(b);
    return returnstring;
}

gmexport char const* gmp_div(char const* a_string, char const* b_string) {
    mpz_t a, b;
    mpz_init_set_str(a, a_string, 0);
    mpz_init_set_str(b, b_string, 0);
    if (mpz_sgn(b) == 0) {
	free((char*)returnstring);
	returnstring = strdup("0x0");
    } else {
	mpz_tdiv_q(a, a, b);
	make_returnstring_hex(a);
    }
    mpz_clear(a);
    mpz_clear(b);
    return returnstring;
}

gmexport char const* gmp_mod(char const* a_string, char const* b_string) {
    mpz_t a, b;
    mpz_init_set_str(a, a_string, 0);
    mpz_init_set_str(b, b_string, 0);
    if (mpz_sgn(b) == 0) {
	free((char*)returnstring);
	returnstring = strdup("0x0");
    } else {
	mpz_tdiv_r(a, a, b);
	make_returnstring_hex(a);
    }
    mpz_clear(a);
    mpz_clear(b);
    return returnstring;
}

gmexport char const* gmp_neg(char const* a_string) {
    mpz_t a;
    mpz_init_set_str(a, a_string, 0);
    mpz_neg(a, a);
    make_returnstring_hex(a);
    mpz_clear(a);
    return returnstring;
}

gmexport char const* gmp_abs(char const* a_string) {
    mpz_t a;
    mpz_init_set_str(a, a_string, 0);
    mpz_abs(a, a);
    make_returnstring_hex(a);
    mpz_clear(a);
    return returnstring;
}

gmexport char const* gmp_pow(char const* base_string, char const* n_string) {
    mpz_t a, b;
    mpz_init_set_str(a, base_string, 0);
    mpz_init_set_str(b, n_string, 0);
    if (!mpz_fits_ulong_p(b)) {
	free((char*)returnstring);
	returnstring = strdup("0x0");
    } else {
	mpz_pow_ui(a, a, mpz_get_ui(b));
	make_returnstring_hex(a);
    }
    mpz_clear(a);
    mpz_clear(b);
    return returnstring;
}

gmexport char const* gmp_powmod(char const* base_string, char const* n_string, char const* mod_string) {
    mpz_t a, b, c;
    mpz_init_set_str(a, base_string, 0);
    mpz_init_set_str(b, n_string, 0);
    mpz_init_set_str(c, mod_string, 0);
    if (mpz_sgn(c) < 0) {
	free((char*)returnstring);
	returnstring = strdup("0x0");
    } else {
	mpz_powm(a, a, b, c);
	make_returnstring_hex(a);
    }
    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(c);
    return returnstring;
}

gmexport char const* gmp_sqrt(char const* a_string) {
    mpz_t a;
    mpz_init_set_str(a, a_string, 0);
    if (mpz_sgn(a) < 0) {
	free((char*)returnstring);
	returnstring = strdup("0x0");
    } else {
	mpz_sqrt(a, a);
	make_returnstring_hex(a);
    }
    mpz_clear(a);
    return returnstring;
}

gmexport char const * gmp_sqrtrem(char const* a_string) {
    mpz_t a, b;
    mpz_init_set_str(a, a_string, 0);
    mpz_init(b);
    if (mpz_sgn(a) < 0) {
	free((char*)returnstring);
	returnstring = strdup("0x0");
    } else {
	mpz_sqrtrem(a, b, a);
	make_returnstring_hex(b);
    }
    mpz_clear(a);
    mpz_clear(b);
    return returnstring;
}

gmexport char const * gmp_root(char const* a_string, char const* n_string) {
    mpz_t a, b;
    mpz_init_set_str(a, a_string, 0);
    mpz_init_set_str(a, n_string, 0);
    if ((mpz_sgn(a) < 0 && mpz_even_p(b)) || !mpz_fits_ulong_p(b)) {
	free((char*)returnstring);
	returnstring = strdup("0x0");
    } else {
	mpz_root(a, a, mpz_get_ui(b));
	make_returnstring_hex(a);
    }
    mpz_clear(a);
    mpz_clear(b);
    return returnstring;
}

gmexport char const * gmp_rootrem(char const* a_string, char const* n_string) {
    mpz_t a, b;
    mpz_init_set_str(a, a_string, 0);
    mpz_init_set_str(a, n_string, 0);
    if ((mpz_sgn(a) < 0 && mpz_even_p(b)) || !mpz_fits_ulong_p(b)) {
	free((char*)returnstring);
	returnstring = strdup("0x0");
    } else {
	mpz_rootrem(a, b, a, mpz_get_ui(b));
	make_returnstring_hex(b);
    }
    mpz_clear(a);
    mpz_clear(b);
    return returnstring;
}

gmexport double gmp_compare(char const* a_string, char const* b_string) {
    mpz_t a, b;
    mpz_init_set_str(a, a_string, 0);
    mpz_init_set_str(b, b_string, 0);
    int result = mpz_cmp(a, b);
    mpz_clear(a);
    mpz_clear(b);
    return result;
}

gmexport double gmp_abscompare(char const* a_string, char const* b_string) {
    mpz_t a, b;
    mpz_init_set_str(a, a_string, 0);
    mpz_init_set_str(b, b_string, 0);
    int result = mpz_cmpabs(a, b);
    mpz_clear(a);
    mpz_clear(b);
    return result;
}

gmexport double gmp_sign(char const* a_string) {
    mpz_t a;
    mpz_init_set_str(a, a_string, 0);
    int result = mpz_sgn(a);
    mpz_clear(a);
    return result;
}

gmexport double gmp_even(char const* a_string) {
    mpz_t a;
    mpz_init_set_str(a, a_string, 0);
    bool result = mpz_even_p(a);
    mpz_clear(a);
    return result;
}

gmexport double gmp_odd(char const* a_string) {
    mpz_t a;
    mpz_init_set_str(a, a_string, 0);
    bool result = mpz_odd_p(a);
    mpz_clear(a);
    return result;
}

gmexport double gmp_probab_prime(char const* a_string, double reps) {
    mpz_t a;
    mpz_init_set_str(a, a_string, 0);
    int result = mpz_probab_prime_p(a, gm_cast<int>(reps));
    mpz_clear(a);
    return result;
}

gmexport char const * gmp_probab_nextprime(char const* a_string) {
    mpz_t a;
    mpz_init_set_str(a, a_string, 0);
    mpz_nextprime(a, a);
    make_returnstring_hex(a);
    mpz_clear(a);
    return returnstring;
}

gmexport char const * gmp_gcd(char const* a_string, char const* b_string) {
    mpz_t a, b;
    mpz_init_set_str(a, a_string, 0);
    mpz_init_set_str(b, b_string, 0);
    mpz_gcd(a, a, b);
    make_returnstring_hex(a);
    mpz_clear(a);
    mpz_clear(b);
    return returnstring;
}

gmexport char const * gmp_lcm(char const* a_string, char const* b_string) {
    mpz_t a, b;
    mpz_init_set_str(a, a_string, 0);
    mpz_init_set_str(b, b_string, 0);
    mpz_lcm(a, a, b);
    make_returnstring_hex(a);
    mpz_clear(a);
    mpz_clear(b);
    return returnstring;
}

gmexport char const * gmp_factorial(char const* n_string) {
    mpz_t a;
    mpz_init_set_str(a, n_string, 0);
    if (!mpz_fits_ulong_p(a)) {
	free((char*)returnstring);
	returnstring = strdup("0x0");
    } else {
	mpz_fac_ui(a, mpz_get_ui(a));
	make_returnstring_hex(a);
    }
    mpz_clear(a);
    return returnstring;
}

gmexport char const  * gmp_fibonacci(char const* n_string) {
    mpz_t a;
    mpz_init_set_str(a, n_string, 0);
    if (!mpz_fits_ulong_p(a)) {
	free((char*)returnstring);
	returnstring = strdup("0x0");
    } else {
	mpz_fib_ui(a, mpz_get_ui(a));
	make_returnstring_hex(a);
    }
    mpz_clear(a);
    return returnstring;
}

gmexport char const * gmp_min(char const* a_string, char const* b_string) {
    mpz_t a, b;
    mpz_init_set_str(a, a_string, 0);
    mpz_init_set_str(b, b_string, 0);
    if (mpz_cmp(a, b) < 0) {
	make_returnstring_hex(a);
    } else {
	make_returnstring_hex(b);
    }
    mpz_clear(a);
    mpz_clear(b);
    return returnstring;
}

gmexport char const * gmp_max(char const* a_string, char const* b_string) {
    mpz_t a, b;
    mpz_init_set_str(a, a_string, 0);
    mpz_init_set_str(b, b_string, 0);
    if (mpz_cmp(a, b) > 0) {
	make_returnstring_hex(a);
    } else {
	make_returnstring_hex(b);
    }
    mpz_clear(a);
    mpz_clear(b);
    return returnstring;
}


