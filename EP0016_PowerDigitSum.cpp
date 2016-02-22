/*
 * EP0016_PowerSumDigit.cpp
 *
 *  Created on: 18/02/2016
 *      Author: terentz
 */

#include "EP0016_PowerDigitSum.hpp"
#include "EulerUtils.hpp"
#include <iostream>
#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>


using std::cout;
using std::endl;
using std::to_string;
using std::printf;
//using mpz::mpz_t;
//using gmp::mpz_init;
//using gmp::mpz_pow_ui;

/* local defines */
//#define EXPONENT 15
#define EXPONENT 1000

/* functions */

void PowerDigitSum::run () {
    gmpVersion();
//    strVersion();
}

void PowerDigitSum::gmpVersion(){

	/* LOCAL DECLARATIONS */

    mpz_t base, result;
    unsigned int exponent = EXPONENT;
    int sum = 0;
    mpz_inits(base, result);
    mpz_set_str(base, "2", 10);


    /* DO THE WORK! */

    mpz_pow_ui(result, base, exponent);
    string result_str( mpz_get_str ( NULL, 10, result ) );
    int len = result_str.size();
    cout << "first loop..." << endl;
    for ( char &c : result_str ) sum += c-'0';


	/* DISPLAY RESULTS */

	cout << "The sum of the digits in 2^1000 is " << sum << endl << endl;
    return;
}

void PowerDigitSum::strVersion() {

}

