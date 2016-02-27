/*
 * EPxxxx_EulerTemplate.cpp
 *
 *  Created on: 13/12/2013
 *      Author: terentz
 */

#include "EP0014_LongestCollatz.hpp"
#include "EulerUtils.hpp"
#include <iostream>
#include "Prime.hpp"

using std::cout;
using std::endl;
using EulerUtils::NumberTheory::General::even;

/* local defines */
#define MAGNITUDE 6

/* functions */

void LongestCollatz::run () {

	/* test */

    cout << "in Longest Collatz Sequence" << endl;


	/* LOCAL DECLARATIONS */

    //const int limit = LIMIT_TEST;
    const int LIMITS[6] = { 10, 100, 1000, 10000, 100000, 1000000 };
    const int limit = LIMITS[MAGNITUDE-1];
    const int start = 1;

    int leadChLen = 0;
    int leadStVal = 0;


    /* TEST CODE */
//    const int len13 = buildChain(13,0);
//    cout << "The length of the chain starting at 13 is " << std::to_string(len13) << endl;
//    return;


	/* DO THE WORK! */

    for ( int currStVal = start ; currStVal < limit ; ++currStVal ) {
        // Generate the next chain...
        const int currChLen = buildChain( long(currStVal), 0 );
        // Test it, and save if it's the longest so far...
        if ( currChLen > leadChLen ) {
            leadChLen = currChLen;
            leadStVal = currStVal;
        }
    }


	/* DISPLAY RESULTS */

    cout << "The longest chain length is " << std::to_string(leadChLen)
         << " which starts at " << std::to_string(leadStVal) << endl ;
	cout << endl;

}

const int LongestCollatz::buildChain( const long currVal, int depth ) {
    if ( currVal == 1 ) return ++depth;
    if ( even(currVal) ) return buildChain( currVal/2, ++depth );
    else return buildChain( currVal*3+1, ++depth );
}

