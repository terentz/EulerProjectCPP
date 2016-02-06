/*
 * EP0004_LargestPalindromeProduct.hpp
 *
 *  Created on: 16/11/2013
 *      Author: terentz
 */

#ifndef EP0004_LARGESTPALINDROMEPRODUCT_HPP_
#define EP0004_LARGESTPALINDROMEPRODUCT_HPP_


namespace LargestPalindromeProduct {

	void run();

	long largestPossibleFactor ( int requiredSize );
	long smallestPossibleFactor ( int requiredSize );
	bool isWinner ( int testProd, int *f1, int *f2, int min, int max );
	bool hasAptFactors ( int testProd, int *f1, int *f2, int min, int max );

	// 1. version using string conversion
	bool isPalindromeViaNumeric ( int testProd );
	// 2. version using powers of ten
	bool isPalindromeViaString ( int testProd );

} /* namespace LargestPalindromeProduct */
#endif /* EULER0004_LARGESTPALINDROMEPRODUCT_H_ */
