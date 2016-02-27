/*
 * EP0007_10001StPrime.cpp
 *
 *  Created on: 28/11/2013
 *      Author: terentz
 */

#include "EP0007_10001StPrime.hpp"
//#include "Prime.hpp"
#include "EulerUtils.hpp"
#include <iostream>

using EulerUtils::NumberTheory::Prime::nthPrime;
using EulerUtils::NumberTheory::Prime::isPrime;
using std::cout;
using std::endl;

#define LIMIT 10001

namespace TenThousandFirstPrime {

void run () {
	// locals
	long long result, lim = (long long)LIMIT;

	// work
	result = nthPrime( LIMIT );

	// print results
	cout << "The " << LIMIT << "th prime is " << result << endl;

}



} /* namespace TenThousandFirstPrime */
