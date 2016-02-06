/*
 * EP0044_Champerdowne.cpp
 *
 *  Created on: 11/12/2013
 *      Author: terentz
 */

#include "EP0040_Champerdowne.hpp"
#include "EulerUtils.hpp"
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <boost/lexical_cast.hpp>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::pow;
using boost::lexical_cast;

#define LOG_N 6

namespace Champerdowne {


void run() {
	// locals
	const int N = pow(10.0,LOG_N);
	const unsigned int MAX_LEN = (unsigned)N + (unsigned)LOG_N;
	string champ;
	int n = 0, ans = 1;

	// build the string
	unsigned int current;
	for ( current = 1 ; champ.length() <= MAX_LEN ; current++ ) {
		string temp = lexical_cast<std::string>(current);
		champ += temp;
	}

	// control loop
	for ( n = 1 ; n <= N ; n *= 10 ) {
		int expDigit = lexical_cast<int>(champ[n-1]);
		ans *= expDigit;
	}

	// print results
	cout << "The answer is " << ans << endl;

}

} /* namespace Champerdowne */
