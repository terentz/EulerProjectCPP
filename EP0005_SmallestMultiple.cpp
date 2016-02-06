/*
 * EP0005_SmallestMultiple.cpp
 *
 *  Created on: 06/02/2016
 *      Author: terentz
 */

#include "EP0005_SmallestMultiple.hpp"
#include "EulerUtils.hpp"
#include <iostream>
#include "Prime.hpp"
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using EulerUtils::primesFactorial;
using EulerUtils::gcd;
using EulerUtils::primeFactorsAll;
using EulerUtils::printVector;


/* local defines */
#define INPUT 20

/* functions */

void SmallestMultiple::run () {
	/* test */
    long long test = INPUT;
    long long result1 = primesFactorial(test);
    cout << "test results of primesFactorial(" << test << ") is " << result1 << endl;

    long long a = 16;
    long long b = 12;
    long long result2 = gcd(a,b);
    cout << "gcd(" << a << "," << b << ") is " << result2 << endl;

    long long f = 20;
    vector<long long> factors = primeFactorsAll(f);
    cout << "done" << endl;
    printVector("factors of 20", factors);

    long long product = EulerUtils::product(factors);
    cout << "product = " << product << endl;



    vector<long long> allFactors[INPUT];

    for ( int i = 0 ; i < INPUT ; ++i ) {
        allFactors[i] = EulerUtils::primeFactorsAll(i+1);
    }

    for ( int i = 0 ; i < INPUT ; ++i ) {
        EulerUtils::printVector("", allFactors[i]);
    }





	/* local declarations */

	/* do the work! */

	/* display results */

	cout << endl;

}


