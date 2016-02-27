/*
 * EPxxxx_EulerTemplate.cpp
 *
 *  Created on: 13/12/2013
 *      Author: terentz
 */

#include "EP0021_SumOfAmicableNumbers.hpp"
#include "EulerUtils.hpp"
#include <iostream>
#include "Prime.hpp"
#include <vector>
#include <set>
#include <tuple>

using std::cout;
using std::endl;
using std::vector;
using std::set;
using std::tuple;
using EulerUtils::NumberTheory::Prime::isPrime;

/* local defines */
#define LIMIT 10000

/* functions */

void SumOfAmicableNumbers::run () {

	/* local declarations */

	int sum = 0;
    vector<NonPrime> nonPrimes;
    set<tuple<int,int>> amicables;

	/* do the work! */

    // collect the non-primes
    for ( int n = 1 ; n <= LIMIT ; ++n ) {
        int d = sumOfFactors(n);
        // if non-prime, make an obj and add it
        if ( d > 1 ) {
            NonPrime np = {n,d};
            nonPrimes.push_back(np);
        }
    }

    // loop thru nonPrimes to find amicable matches
    for ( vector<NonPrime>::iterator outer = nonPrimes.begin() ; outer != nonPrimes.end() ; ++outer ) {
        for ( vector<NonPrime>::iterator inner = nonPrimes.begin() ; inner != nonPrimes.end() ; ++inner ) {
            // if amicable, add them and break the inner loop
            if ( (*outer).d == (*inner).n && (*outer).n == (*inner).d ) {

                tuple<int,int> amicable1((*inner).n,(*inner).d);
                tuple<int,int> amicable2((*outer).n,(*outer).d);

                amicables.insert(amicable1);
                amicables.insert(amicable2);

                break;

            }
        }
    }

    // loop thru amicables to sum the values
    for ( set<tuple<int,int>>::iterator it = amicables.begin() ; it != amicables.end() ; ++it ) {
        sum += std::get<0>(*it);
    }


	/* display results */

	cout << "The sum of the amicable number pairs less than " << LIMIT << " is " << sum << "." << endl;

}

int SumOfAmicableNumbers::sumOfFactors( const int in ) {

    int sum = 0;
    vector<int> factors;

    factors.push_back(1);
    for ( int current = 2 ; current <= (int)( in / 2 ) ; ++current ) {
        if ( in % current == 0 ) {
            factors.push_back(current);
        }
    }
    //factors.push_back(in);

    for ( vector<int>::iterator iter = factors.begin() ; iter != factors.end() ; ++iter ) {
        sum += (*iter);
    }

    return sum;
}




