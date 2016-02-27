/*
 * EP0002_EvenFibonacci.cpp
 *
 *  Created on: 16/11/2013
 *      Author: terentz
 */

#include "EP0002_EvenFibonacci.hpp"
#include "EulerUtils.hpp"
#include <iostream>

using std::cout;
using std::endl;
using EulerUtils::NumberTheory::General::even;


#define LIM 4000000
#define PRINT_ON true



namespace EvenFibonacci {

void run(){

	// locals
	int first = 1, second = 2;
	int sum = 0, evenSum = 0;

	// calculate and print the sequence
	if(PRINT_ON) cout << "1 2 ";
	evenSum = fibSum(sum, evenSum, first, second);

	// print results
	cout << endl << "Sum of even Fibonacci numbers that don't exceed " << LIM << " is " << evenSum << endl;

 } /* run() */

int fibSum(int sum, int evenSum, int first, int second) {
	int next = first + second;
	// printing
	if (PRINT_ON)
		cout << next << " ";
	// increase sum
	sum += (first + second);
	// increase evenSum
	if ( even(first) ) {
		evenSum += first;
	}

	// test for limit
	if ( next > LIM )
		return even(second) ? evenSum + second : evenSum;
	else
		return fibSum(sum, evenSum, second, next);

}


} /* namespace EvenFibonacci */
