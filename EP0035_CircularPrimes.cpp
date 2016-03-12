/*
 * EP0035_CircularPrimes.cpp
 *
 *  Created on: 28/02/2016
 *      Author: terentz
 */

#include "EP0035_CircularPrimes.hpp"
#include "EulerUtils.hpp"
#include <iostream>
#include <primesieve.hpp>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::stoi;
using EulerUtils::NumberTheory::General::rotate_int;
using EulerUtils::NumberTheory::General::rotate_str;
using EulerUtils::NumberTheory::Prime::isPrime;

/* NAMESPACE DEFINES */
#define LIM 1000000

/* FUNCTIONS */

void CircularPrimes::run () {

	/* LOCAL DECLARATIONS */
    unsigned int tally = 4; // 2, 3, 5, 7

    /* DO THE WORK! */
	for ( unsigned int test = 10 ; test < LIM ; ++test )
        if ( isCircularPrime(test) ) {
            ++tally;
            cout << test << " is a circular prime" << endl;
        }

	/* DISPLAY RESULTS */
	cout << "The number of rotational primes up to " << LIM << " is " << tally << endl << endl;

}

bool CircularPrimes::isCircularPrime( unsigned int x ) {
    string x_str = to_string(x);
    unsigned short len = x_str.size();
    bool allPrime = true;
    for ( unsigned short r = 0 ; r < len ; ++r ) {
        if ( !isPrime(stoi(x_str)) ) return false;
//        cout << x << " is prime" << endl;
//        x = rotate_int(x);
        x_str = rotate_str(x_str);
    }
    return true;
}
