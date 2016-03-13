/*
 * EP0031_CoinSums.cpp
 *
 *  Created on: 13/03/2016
 *      Author: terentz
 */

#include "EP0031_CoinSums.hpp"
#include "EulerUtils.hpp"
#include <iostream>
//#include <utf8>

using std::cout;
using std::endl;

/* NAMESPACE DEFINES */
#define GOAL    200
#define COINS   10

const unsigned short coins[] = {1,2,5,10,20,50,100,200};

/* FUNCTIONS */

void CoinSums::run () {

	/* LOCAL DECLARATIONS */
    unsigned long int ways = 0;

	/* DO THE WORK! */
	drill( 0, ways, 0, 0 );

	/* DISPLAY RESULTS */
	cout << "The number of ways of making up \u00A32 is " << ways<< endl;
}

void CoinSums::drill( unsigned short total, unsigned long int &tally, unsigned short start_idx, unsigned short depth ) {
    if ( total > GOAL )
        return;
    if ( total == GOAL ) {
        ++tally;
        return;
    }
    for ( auto c = start_idx ; c < COINS ; ++c )
        drill( total+coins[c], tally, c ,depth+1 );
}

