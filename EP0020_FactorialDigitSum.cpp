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
using EulerUtils::factorial;

/* NAMESPACE DEFINES */
#define START "100"

void FactorialDigitSum::run () {

	/* LOCAL DECLARATIONS */

    // Create the variable...
    string input = START;
    mpz_t fact;
    int flag;
    // Initialise it...
    mpz_init(fact);
    mpz_set_ui(fact, 0);
    int flag = mpz_set_str(fact, input, 10);
    assert(flag == 0); // If flag not 0, operation failed

	/* DO THE WORK! */


	/* DISPLAY RESULTS */
    // Output it as a string
    cout << ""
    mpz_out_str(stdout,10,var);
    mpz_clear(var);


    cout << "Factorial 100 = " << fact << endl;
	cout << endl;

}


