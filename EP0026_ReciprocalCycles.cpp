/*
 * EP0026_ReciprocalCycles.cpp
 *
 *  Created on: 24/02/2016
 *      Author: terentz
 */

#include "EP0026_ReciprocalCycles.hpp"
#include "EulerUtils.hpp"
#include <iostream>
#include <iomanip>
#include <gmp.h>

using std::cout;
using std::endl;
using EulerUtils::float_to_string;
using EulerUtils::isPrime;
using EulerUtils::even;

/* NAMESPACE DEFINES */
#define LIMIT   1000
#define PREC    65536
#define START   7
#define TESTS   3


/* FUNCTIONS */

void ReciprocalCycles::run () {

	/* LOCAL DECLARATIONS */

    int winner = 0,
        longest = 0,
        precision = PREC;

    mpf_t one;
    mpf_init2( one, precision );
    mpf_set_ui( one, (unsigned)1 );


	/* DO THE WORK! */

    for ( unsigned long int current = START ; current < LIMIT ; ++current ) {

        if ( isPrime( current ) ) {

            // Calculat the float..
            mpf_t divisor, fraction;
            mpf_init2( divisor, precision );
            mpf_init2( fraction, precision );
            mpf_init_set_ui( divisor, current );
            mpf_div( fraction, one, divisor );

            // Make a string of it..
            mp_exp_t exponent;
            string places;
            string fraction_str = string( mpf_get_str( NULL, &exponent, 10, precision, fraction ) );

            // Get the cycle...
            int period = getPeriod( fraction_str, TESTS );
            if ( period > longest ) {
                longest = period;
                winner = current;
            }
        }

    }

	/* DISPLAY RESULTS */

	cout << "The number with the greatest period is " << winner << endl << endl;

}

int ReciprocalCycles::getPeriod( string input, int num_tests ) {
    for ( int period = 1 ;  ; ++period ) {
        string temp = input.substr(0, period);
        if ( temp == compareBlocks(input.substr(period),period,num_tests) )
            return period;
    }
}
string ReciprocalCycles::compareBlocks( string input, int width, int level ) {
    string lhs = input.substr(0,width),
            rhs = input.substr(width,width);
    bool eq = ( lhs == rhs );
    if ( eq )
        return ( level == 0 ?
                rhs :
                compareBlocks( input.substr(width), width, (level-1) ) );
    return "";
}

