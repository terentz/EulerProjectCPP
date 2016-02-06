/*
 * EP0009_SpecialPythagoreanTriad.cpp
 *
 *  Created on: 13/12/2013
 *      Author: terentz
 */

#include "EP0009_SpecialPythagoreanTriad.hpp"
#include "EulerUtils.hpp"
#include <cmath>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::pow;
using std::sqrt;
using std::vector;

#define TARGET 1000



void SpecialPythagoreanTriad::run () {
	// locals
	int a, b, c;
	long long aSq, bSq, cSq;
	long ans;
	bool found = false;

	// work!
	for ( a = 1 ; !found && a < 1000 ; a++ ) {
		// for a=x
		for ( b = a ; !found && b < 1000 ; b++ ) {
			c = 1000 - ( a + b );
			if ( isTarget(a,b,c) && isTriad(a,b,c) ) {
				//found == true;
				ans = product(a,b,c);
				// test lines
				cout << "a = " << a << ",  b = " << b << ",  c = " << c << endl;
				cout << "a + b + c = " << (a+b+c) << endl;
				cout << "a x b x c = " << (a*b*c) << endl;

			}
		}
	}

	// print results
	cout << "The product of the Pythagorean Triad whose sum is 1000 is " << endl << ans << endl;
}

bool SpecialPythagoreanTriad::isTarget ( int a , int b , int c ) {
	return ( ( a + b + c ) == TARGET );
}

long SpecialPythagoreanTriad::product ( int a , int b , int c ) {
	return ( a * b * c );
}

bool SpecialPythagoreanTriad::isTriad ( int a , int b , int c ) {
	return (( pow(c,2.0) - ( pow(a,2.0) + pow(b,2.0) )) == 0.0 ) ;
}
