/*
 * Prime.cpp
 *
 *  Created on: 16/11/2013
 *      Author: terentz
 */

#include "Prime.hpp"
#include <cmath>
// test
#include <iostream>

using std::cout;
using std::endl;
using std::floor;
using std::sqrt;
/*
bool isPrime( long input ) {
	for( long test = floor(sqrt(input)) ; test > 1 ; --test ) {
		if( input % test == 0 && test != 1 )
			return false;
	}
	return true;
}
*/

bool isPrime( long long input ) {
	for( long long test = floor(sqrt(input)) ; test > 1 ; --test ) {
		if( input % test == 0 && test != 1 )
			return false;
	}
	return true;
}

/*
long nextPrime( long input ) {
	long current = input;
	while (true) {
		if (isPrime(++current)) {
			return current;
		}
	}
	return 0;
}
*/



long long nextPrime( long long input ){
	long long current = input;
	while (true) {
		if (isPrime(++current)) {
			return current;
		}
	}
	return 0;
}
/*
long nthPrime( long n ) {
	long current, count;
	for ( current = 2, count = 0 ; count <= n ; current++ ) {
		if ( isPrime( current ) ) {
			count++;
			break;
		}
	}
	return current;
}
*/
long long nthPrime( long long n ) {
	long long current, count;
	for ( current = 2, count = 0 ; count < n ; current++ ) {
		if ( isPrime( current ) ) {
			// test
			//cout << current << " is prime!" << endl;
			count ++;
			// test
			//cout << " number " << count << endl;
		}
	}
	return --current;

}
