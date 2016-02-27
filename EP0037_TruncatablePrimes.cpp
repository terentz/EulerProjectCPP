/*
 * EP0037_TruncatablePrimes.cpp
 *
 *  Created on: 26/02/2016
 *      Author: terentz
 */

#include "EP0037_TruncatablePrimes.hpp"
#include "EulerUtils.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::stoi;
using std::to_string;
using EulerUtils::NumberTheory::Prime::isPrime;

/* NAMESPACE DEFINES */
#define START 13
#define LIMIT 11


/* FUNCTIONS */

void TruncatablePrimes::run () {

	/* LOCAL DECLARATIONS */
    unsigned long trunc_count = 0,
                  sum = 0;

	/* DO THE WORK! */
    for ( unsigned long current = START ; trunc_count < LIMIT ; ++current )
        if ( isPrime(current) )
            if ( isTruncatable(current) ) {
                sum += current;
                ++trunc_count;
                cout << current << " is truncatable" << endl;
                cout << "count: " << trunc_count << endl;
            }

	/* DISPLAY RESULTS */
	cout << "The number of truncatable primes is " << trunc_count << endl;
    cout << "The sum is " << sum << endl << endl;

}

bool TruncatablePrimes::isTruncatable( unsigned long input ) {
    if ( !isPrime(input) )
        return false;
    string src = std::to_string(input);
    if ( src.size() == 1 )
        return isPrime(input);

    return truncate(src.substr(0,(src.size()-1)), true) &&
            truncate(src.substr(1), false);
}
bool TruncatablePrimes::truncate( string input, bool left ) {
    long long num = (long long)stoi(input);
    int sz = input.size();
    if ( sz == 1 )
        return isPrime( num );
    if ( !isPrime(num) )
        return false;
    return ( left ?
            truncate( input.substr(0,sz-1), true ) :
            truncate( input.substr(1), false ) ) ;
}

