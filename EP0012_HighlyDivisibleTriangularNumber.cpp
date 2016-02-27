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
//using EulerUtils::primeFactors;
using EulerUtils::Display::printVector;
using EulerUtils::NumberTheory::Special::nthTriangularNumber;
using EulerUtils::Display::printSet;
using EulerUtils::NumberTheory::Factorise::integerDivisors;
/* local defines */
#define DIVISORS 500

/* functions */
namespace HighlyDivisibleTriangularNumber{

void run () {

    /* LOCAL DECLARATIONS */

    int divisors = 0;
    long long term = 0;
    long long triangular = 0;

    /* TEST CODE */

//    long long termSeven = EulerUtils::nthTriangularNumber(7);
//    cout << "The 7th triangular number is " << std::to_string(termSeven) << endl;
//
//    set<long long> allFactors7th = EulerUtils::intFactors(termSeven);
//    EulerUtils::printSet("Int factors of "+std::to_string(termSeven)+"...", allFactors7th);
//    int sz7th = allFactors7th.size();
//    cout << "The size of " << std::to_string(termSeven) << "'s factor list is " << std::to_string(sz7th) << endl ;
//    return;


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


