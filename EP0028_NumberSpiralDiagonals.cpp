/*
 * EP0028_NumberSpiralDiagonals.cpp
 *
 *  Created on: 25/02/2016
 *      Author: terentz
 */

#include "EP0028_NumberSpiralDiagonals.hpp"
#include "EulerUtils.hpp"
#include <iostream>

using std::cout;
using std::endl;

/* NAMESPACE DEFINES */
//#define DEG 5
#define DEG 1001

/* FUNCTIONS */

void NumberSpiralDiagonals::run () {

	/* LOCAL DECLARATIONS */
    int total = 1,
        adder = 1,
        degree = DEG;

	/* DO THE WORK! */
    for ( int inc = 2 ; inc < degree ; inc += 2 ) {
        for ( int times = 1 ; times < 5 ; ++times ) {
            adder += inc;
            total += adder;
        }
    }

	/* DISPLAY RESULTS */
	cout << "The sum of the diagonals for " << degree << " is " << total << endl << endl;
}


