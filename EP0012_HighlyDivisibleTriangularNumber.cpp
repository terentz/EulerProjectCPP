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

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using EulerUtils::primeFactors;
using EulerUtils::printVector;

/* local defines */
// TODO DIVISORS should be 500, but it never seems to complete execution.
// Perhaps should just start it and let it run whenever I'm not using the machine.
#define DIVISORS 5

/* functions */
namespace HighlyDivisibleTriangularNumber{

void run () {

	cout << "Working with " << DIVISORS << " divisors." << endl;
	// locals
	//long long triangular = 0;
	long long additive, triangular ;
	//bool found = false;
	// do the work!
	for ( additive = 1, triangular = 1 ;
			//EulerUtils::integerDivisors( triangular ).size() >
			; triangular += ( ++additive ) ) {
		// test line
		cout << "triangular = " << triangular << endl
				<< "num factors = " << EulerUtils::integerDivisors( triangular ).size() << endl ;
		if ( EulerUtils::integerDivisors( triangular ).size() > DIVISORS ) {
			break;
		}
	}
	char tri_str [19];
	EulerUtils::printVector( ( "divisors of " + std::to_string(triangular) ) , EulerUtils::integerDivisors( triangular ) );

	// display results
	cout << "The smallest triangular number with more than " << DIVISORS << " different factors is " << triangular << endl;
} // end run


}


