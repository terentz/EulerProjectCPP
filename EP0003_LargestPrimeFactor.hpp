/*
 * EP0003_LargestPrimeFactor.h
 *
 *  Created on: 16/11/2013
 *      Author: terentz
 */

#ifndef EP0003_LARGESTPRIMEFACTOR_HPP_
#define EP0003_LARGESTPRIMEFACTOR_HPP_

#include <vector>
using std::vector;

namespace LargestPrimeFactor {

	void run();

	bool isPrime( long long num );
	void findFactors( long long input,
						long long & index,
						long long & largest,
						vector<long long> & allPrimeFactors );

	/*
	 * Overloaded debug version
	 */
	void findFactors( long long input,
						long long & index,
						long long & largest,
						vector<long long> & allPrimeFactors,
						int depth);



} /* namespace LargestPrimeFactor */
#endif /* EP0003_LARGESTPRIMEFACTOR_H_ */
