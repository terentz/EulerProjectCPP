/*
 * EPxxxx_EulerTemplate.cpp
 *
 *  Created on: 13/12/2013
 *      Author: terentz
 */

#include "EPxxxx_EulerTemplate.hpp"
#include "EulerUtils.hpp"
#include <iostream>
#include <string>
#include "Prime.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <set>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::set;
using EulerUtils::NumberTheory::Special::nthTriangularNumber;
using EulerUtils::NumberTheory::Factorise::integerDivisors;

#define DIVISORS 500

namespace HighlyDivisibleTriangularNumber{

void run () {

    /* LOCAL DECLARATIONS */

    int divisors = 0;
    long long term = 0;
    long long triangular = 0;


    /* DO THE WORK! */

    do {
        // Increment the term
        ++term;
        // Calculate triangular number...
        triangular = nthTriangularNumber(term);
        // Extract all integer factors...
        set<unsigned long long> factors = integerDivisors(triangular);
        // Count the factors...
        divisors = factors.size();

    } while ( divisors <= DIVISORS );


    /* DISPLAY RESULTS */

    cout << "The first triangular number to have more than 500 factors is " << std::to_string(triangular) << endl;
    return;

} // end run


}


