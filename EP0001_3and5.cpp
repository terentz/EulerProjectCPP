/*
 * ThreeAndFive.cpp
 *
 *  Created on: 16/11/2013
 *      Author: terentz
 */

#include "EP0001_3and5.hpp"
#include "EulerUtils.hpp"
#include <iostream>

using std::cout;
using std::endl;

#define LIM 1000

namespace ThreeAndFive {

void run() {

	int current = 1, ans = 0;

	// do the work!
	for ( current = 1 ; current < 1000 ; current++ ) {
		if ( current%5 == 0 || current % 3 == 0 ) {
			ans += current;
		}
	}

	cout << "The answer is " << ans << endl;
} // run()

} // namespace


