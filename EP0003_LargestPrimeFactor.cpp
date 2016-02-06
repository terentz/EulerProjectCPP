/*
 * EP0003_LargestPrimeFactor.cpp
 *
 *  Created on: 16/11/2013
 *      Author: terentz
 */

#include "EP0003_LargestPrimeFactor.hpp"
#include "EulerUtils.hpp"
#include "Prime.hpp"
#include <iostream>
#include <vector>
#include <cmath>

using std::cout;
using std::endl;
using std::vector;
using std::floor;
using std::sqrt;
using Prime::isPrime;

#define CONTROL 600851475143


namespace LargestPrimeFactor {

	void run() {

		// locals
		long long largest = 0, input = CONTROL;
		vector<long long> prime_factors;
		long long index = 0;

		// DO THE WORK!!
		findFactors( input, index, largest, prime_factors, 1 );

		// print results
		cout << "The largest prime factor of " << CONTROL << " is " << largest << endl;

	}




	void findFactors( long long input,
						long long & index,
						long long & largest,
						vector<long long> & allPrimeFactors,
						int depth) {

		long long out1, out2, test;
		bool inHasFactors = false;

		// get the square root, if mod = 0, recurse with sqrt and other factor
		// TODO kill the floor() here if poss - waste of processing
		for( test = floor(sqrt(input)) ; test > 1 ; --test ){

			// is test a factor?
			if ( input % test == 0 ) {
				out1 = test;
				out2 = input/test;
				inHasFactors = true;
				break;
			}
		}

		// non-prime case ...
		if ( inHasFactors ) {
			++depth;
			findFactors( out1, index, largest, allPrimeFactors, depth );
			findFactors( out2, index, largest, allPrimeFactors, depth );
		}
		// prime case ...
		else {  	// is prime factor, so add it to vector, test against largest, and if successful, reassign largest
			// TODO debug & fix this segmentation issue..
			//allPrimeFactors[index++] = input;
			//cout << allPrimeFactors[index-1] << " is a prime factor" << endl;
			//return;
			if(input > largest)
				largest = input;
		}
	}

} /* namespace LargestPrimeFactor */
