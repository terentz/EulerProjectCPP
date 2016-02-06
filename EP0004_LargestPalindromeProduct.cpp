/*
 * Euler0004_LargestPalindromeProduct.cpp
 *
 *  Created on: 16/11/2013
 *      Author: terentz
 */


#include "EP0004_LargestPalindromeProduct.hpp"
#include "EulerUtils.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>


using std::cout;
using std::endl;
using std::string;
using std::ostringstream;
using std::sqrt;


#define FACTOR_SIZE 3
#define VERSION "string"
//#define VERSION "number"

namespace LargestPalindromeProduct {

void run() {

	// locals
	const int requiredSize = FACTOR_SIZE,
			max = largestPossibleFactor(requiredSize), min = smallestPossibleFactor(requiredSize);

	int factors[2], ans = 0,
			*ptr_f1 = &factors[0], *ptr_f2 = &factors[1], *ptr_ans = &ans;

	// do the work
	for ( int testProd = max * max ; testProd >= min ; testProd-- ) {
		if ( isWinner(testProd, ptr_f1, ptr_f2, min, max ) ) {
			ans = testProd;
			break;
		}
	}

	// print results
	cout << "The answer is " << ans <<
			" which is the product of " << factors[0] << " and " << factors[1] << endl;
}



bool isWinner ( int testSubj, int *f1, int *f2, int min, int max ) {
	if ( isPalindromeViaString( testSubj )
			&& hasAptFactors( testSubj, f1, f2, min, max ) ) {
		return true;
	}
	return false;
}


// 1. version using string conversion
bool isPalindromeViaNumeric ( int testProd ) {
	// TODO finish this version
	int mag = log10(testProd);
	cout << "magnitude of current = " << mag << endl;


	return false;
}


// 2. version using powers of ten
bool isPalindromeViaString ( int testProd ) {

	string strSubj;
	ostringstream convert;
	convert << testProd;
	strSubj = convert.str();

	// loop thru and find out!
	for ( int i = 0, j = strSubj.length() - 1 ; i < j ; i++ , j-- ) {
		if ( strSubj[i] != strSubj [j] ) {
			return false;
		}
	}
	return true;
}


bool hasAptFactors( int testProd, int *f1, int *f2, int min, int max ) {
	int root = floor((float)sqrt(testProd)),
			factor1, factor2;
	if ( root < min || root > max ) return false;

	for ( factor1 = root ; factor1 > 1 ; factor1-- ) {
		if ( testProd % factor1 == 0 ) {		// check for zero modulus
			factor2 = testProd / factor1;			// get 2nd factor
			if ( factor1 * factor2 == testProd ) {	// test product
				if ( factor1 >= min && factor2 <= max ) { // now test against limits
					*f1 = factor1; *f2 = factor2;
					return true;
				}
			}
		}
	}
	return false;
}



/*
 * Programmatically determines the starting value.
 */

long largestPossibleFactor ( int requiredSize ) {
	return (long)(pow(10.0, requiredSize)-1);
}

long smallestPossibleFactor ( int requiredSize ) {
	return (long)(pow(10.0, requiredSize-1));
}


} /* namespace LargestPalindromeProduct */
