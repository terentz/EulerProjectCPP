/*
 * EP0046_GoldbachsOther.cpp
 *
 *  Created on: 12/03/2016
 *      Author: terentz
 */

#include "EP0046_GoldbachsOther.hpp"
#include "EulerUtils.hpp"
#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::pow;
using std::sqrt;
using std::floor;
using std::string;
using std::to_string;
using EulerUtils::NumberTheory::Prime::isPrime;
using EulerUtils::NumberTheory::General::even;
/* NAMESPACE DEFINES */
//#define CONST val


/* FUNCTIONS */

void GoldbachsOther::run () {

	/* LOCAL DECLARATIONS */
	vector<unsigned int> primes;
    unsigned int ans = 0;


	/* DO THE WORK! */
    for ( unsigned int test = 3 ;  ; test+=2 ) {
        if ( isPrime(test) )
            primes.push_back(test);
        else {
            if ( !fitsGoldbachs(test, primes) ) {
                ans = test;
                break;
            }
        }
    }


	/* DISPLAY RESULTS */
	cout << "The smallest composite odd natural number that does not fit Goldbach's conjecture is "
         << ans << endl << endl;

}

bool GoldbachsOther::fitsGoldbachs( unsigned int x, const vector<unsigned int> &primes ) {
    for ( auto a = primes.cbegin() ; a != primes.cend() ; ++a )
        if ( isTwiceASquare( x - *a ) )
            return true;
    return false;
}

bool GoldbachsOther::isTwiceASquare( unsigned int x ) {
    return even(x) &&
        ( 2 * pow( floor( sqrt( x/2 ) ), 2 ) == x );
}
