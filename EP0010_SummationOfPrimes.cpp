/*
 * EP0010_SummationOfPrimes.cpp
 *
 *  Created on: 13/12/2013
 *      Author: terentz
 */

#include "EP0010_SummationOfPrimes.hpp"
#include "EulerUtils.hpp"
#include <iostream>
//#include "Prime.hpp"

using std::cout;
using std::endl;
using EulerUtils::NumberTheory::Prime::isPrime;

#define LIMIT 2000000

void SummationOfPrimes::run () {
	// local declarations
	long long sum = 0, control;

	// do the work!
	for ( control = 2 ; control <= long(LIMIT) ; control++ ) {
		if ( isPrime(control) )
			sum += control;
	}

	// display results
	cout << "The sum of primes less than 2 million is " << endl <<
			sum << endl;

}
