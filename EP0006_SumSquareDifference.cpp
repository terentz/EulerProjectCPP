/*
 * EP0005_SumSquareDifference.cpp
 *
 *  Created on: 28/11/2013
 *      Author: terentz
 */

#include "EP0006_SumSquareDifference.hpp"
#include "EulerUtils.hpp"
#include <cmath>
#include <iostream>

using std::pow;
using std::abs;
using std::cout;
using std::endl;

#define LIMIT 100

namespace SumSquareDifference {

void run () {

	long long diff = std::abs( sumOfSquares() - squareOfSum() );

	// print results
	cout << "The difference between the sum of the squares of the first hundred integers and " <<
			"the square of the sum of the first hundred integers is " << diff << endl;

}

long long sumOfSquares () {
	long result = 0;
	//int current;
	for ( int current = 1 ; current <= LIMIT ; current++ ) {
		result += std::pow(current, 2.0);
	}
	return result;
}

long long squareOfSum () {
	long result = 0;
	//int current;
	for ( int current = 1 ; current <= LIMIT ; current++ ) {
		result += current;
	}
	return pow( result, 2.0 );
}

} /* namespace SumSquareDifference */
