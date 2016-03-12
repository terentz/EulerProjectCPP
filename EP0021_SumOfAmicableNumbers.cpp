/*
 * EPxxxx_EulerTemplate.cpp
 *
 *  Created on: 13/12/2013
 *      Author: terentz
 */

#include "EP0021_SumOfAmicableNumbers.hpp"
#include "EulerUtils.hpp"
#include <iostream>
#include "Prime.hpp"
#include <vector>
#include <set>
#include <tuple>

using std::cout;
using std::endl;
using std::vector;
using std::set;
using std::tuple;
using EulerUtils::NumberTheory::Prime::isPrime;
using EulerUtils::NumberTheory::Factorise::integerDivisors;
using EulerUtils::NumberTheory::Special::Amicable::isAmicable;

/* local defines */
#define LIMIT 10000

/* functions */

void SumOfAmicableNumbers::run () {

	/* local declarations */

	unsigned int sum = 0;

	/* TEST */
//	cout << "220 is " << ( isAmicable(220) ? "amicable" : "not" ) << endl;
//    cout << "284 is " << ( isAmicable(284) ? "amicable" : "not" ) << endl;
//    cout << "100 is " << ( isAmicable(100) ? "amicable" : "not" ) << endl;
//    cout << "45 is " << ( isAmicable(45) ? "amicable" : "not" ) << endl;
//    exit(1);

	/* do the work! */

	for ( unsigned int test = 1 ; test < LIMIT ; ++test )
        if ( isAmicable(test) )
            sum += test;


	/* display results */

	cout << "The sum of the amicable number pairs less than " << LIMIT << " is " << sum << "." << endl;

}

unsigned int SumOfAmicableNumbers::sumOfDivisors( const unsigned int n ) {

    unsigned int sum = 0;
    const vector<unsigned int> divisors = integerDivisors(n);
    for ( auto d = divisors.cbegin() ; d != divisors.cend() ; ++d )
        sum += *d;
    return sum;
}




