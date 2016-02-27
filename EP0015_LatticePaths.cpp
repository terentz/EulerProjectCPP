/*
 * EP0015_LatticePaths.cpp
 *
 *  Created on: 23/02/2016
 *      Author: terentz
 */

#include "EP0015_LatticePaths.hpp"
#include "EulerUtils.hpp"
#include <iostream>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using std::cout;
using std::endl;
using std::pow;
using EulerUtils::NumberTheory::Factorial::factorial;
using EulerUtils::NumberTheory::Factorial::nCr;
using EulerUtils::NumberTheory::General::even;
using boost::multiprecision::int256_t;

/* NAMESPACE DEFINES */
#define SIDE_MAG 20


/* FUNCTIONS */

void LatticePaths::run () {
//    recursiveVersion();
//    factorialVersion(); // This is the fastest! My personal concoction...
//    directVersion();
    bestVersion();
}

void LatticePaths::bestVersion() {
    unsigned long long p;
    unsigned n;

    for (p = 1, n = 21; n <= 40; n++) {
        p *= n;
        p /= (n - 20);
    }
    cout << "The number of paths through the lattice is " << p << endl << endl;
}

void LatticePaths::directVersion() {
//    routes= [(2n)!]/[n!*n!]
    int256_t n = SIDE_MAG;
    cout << "n = " << n << endl;
    int256_t numer = factorial(2*n);
    cout << "numer " << numer << endl;
    int256_t denom = factorial(n) * factorial(n);
    int256_t result = numer/denom;
    cout << "The number of paths through the lattice is " << result << endl << endl;
}

void LatticePaths::factorialVersion() {

    const unsigned long long n = SIDE_MAG;
    unsigned long long n_fact = factorial(n);

    unsigned long long tally = 0,
                        r_fact = 0,
                        d_fact = 0,
                        ncr = 0,
                        res = 0;

    for ( unsigned long long r = 0 ; r < (n/2+1) ; ++r ) {
        r_fact = factorial(r);
        d_fact = factorial(n-r);
        ncr = n_fact / ( r_fact * d_fact );
        res = std::pow(ncr,2);
        if ( !( even((long long)n) && r == n/2 ) )
            res *= 2;
        tally += res;
    }

    /* DISPLAY RESULTS */
    cout << "The number of paths through the lattice is " << tally << endl << endl;
}

void LatticePaths::recursiveVersion () {

	/* LOCAL DECLARATIONS */
	long counter = 0;
    long& paths = counter;
	short x_pos = 0,
          y_pos = 0,
          man_d = 0;


	/* DO THE WORK! */
    move_one( x_pos, y_pos, man_d, (short)(SIDE_MAG*2), paths );


	/* DISPLAY RESULTS */
    cout << "The number of possible paths is " << paths << endl << endl;

}
void LatticePaths::move_one( short curr_x, short curr_y, short man_d, const short limit, long& paths ) {
    if ( man_d == limit ) ++paths;
    else {
        if ( curr_x < SIDE_MAG ) move_one( (curr_x+1), curr_y, (man_d+1), limit, paths );
        if ( curr_y < SIDE_MAG ) move_one( curr_x, (curr_y+1), (man_d+1), limit, paths );
    }
}
