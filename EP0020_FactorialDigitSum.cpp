/*
 * EP0020_FactorialDigitSum.cpp
 *
 *  Created on: 23/02/2016
 *      Author: terentz
 */

#include "EP0020_FactorialDigitSum.hpp"
#include "EulerUtils.hpp"
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <gmp.h>
#include <stdio.h>
#include <assert.h>

using std::cout;
using std::endl;
//using boost::multiprecision::uint1024_t;
using EulerUtils::NumberTheory::Factorial::factorial;
using EulerUtils::NumberTheory::Special::addDigits;

/* NAMESPACE DEFINES */
#define START "100"

void FactorialDigitSum::run () {

	/* INIT'S */
    const char* input = START;
    mpz_t fact;
    int flag;
    mpz_init(fact);
    mpz_set_ui(fact, 0);
    flag = mpz_set_str(fact, input, 10);
    assert(flag == 0); // If flag not 0, operation failed

    /* DO THE WORK! */
    // Calculate factorial...
    mpz_fac_ui(fact, std::stoll(input));

    // Convert the factorial to a string....
    char* fact_cstr;
    fact_cstr = mpz_get_str (nullptr, 10, fact);
    string fact_str = string(fact_cstr);
    mpz_clear(fact);


	/* DISPLAY */
    cout << string(input) << "! = " << fact_str << endl;
    cout << "The sum of the digits is " << addDigits(fact_str) << endl << endl;

}


