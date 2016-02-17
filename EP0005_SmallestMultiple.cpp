/*
 * EP0005_SmallestMultiple.cpp
 *
 *  Created on: 06/02/2016
 *      Author: terentz
 */

#include <ostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include "EP0005_SmallestMultiple.hpp"
#include "EulerUtils.hpp"
#include <cmath>

using std::cout;
using std::endl;
using std::map;
using std::vector;
using std::string;
using std::pow;
using EulerUtils::primeFactorsAll;
using EulerUtils::countItem;

/* local defines */
#define INPUT_CTRL  10
#define INPUT_PROB  20
#define COMMON 0
#define LONELY 1

/* functions */

void SmallestMultiple::run () {

	/* LOCAL DECLARATIONS */

    const int input = INPUT_PROB;
//    const int input = INPUT_CTRL;
    vector<long long> allFactors[input];


    /* DO THE WORK */

    // Extract all factors from 1 to input...
    for ( size_t i = 0 ; i < input ; ++i ) {
        const int ctrl = (int)i + 1;
        allFactors[i] = primeFactorsAll( ctrl );
    }

    // List the primes used in allFactors...
    set<long long> primeSet = getPrimesUsed( allFactors, input );

    // Use the set to init a map
    map<long long, int> primesMap;
    for ( auto i : primeSet ) primesMap[i] = 0;

    // Tally the primes usage, ie populate the map...
    for ( std::map<long long,int>::iterator it=primesMap.begin(); it!=primesMap.end(); ++it ) {
        const long long currentPrime = it->first;
        for ( int test = 0 ; test < input ; ++test ) {
            const int oldCount = it->second;
            const int newCount = EulerUtils::countItem( allFactors[test], currentPrime );
            if ( newCount > oldCount ) {
                primesMap[currentPrime] = newCount;
            }
        }
    }

    // Get the final product...
    long long product = 1;
    for ( std::pair<const long long, int>& prime: primesMap ) {
//        cout << "for " << std::to_string(prime.first) << " factor = " << std::to_string(prime.second) << endl;
        product *= std::pow(prime.first, prime.second);
    }


    /* PRINT RESULTS */

    cout << "Result = " << std::to_string(product) << endl;
    return;
}



const set<long long> SmallestMultiple::getPrimesUsed( const vector<long long> allFactors[], const int input ) {
    set<long long> primeSet;
    // Loop thru each product, ie factor list
    for ( size_t product = 0 ; product < uint32_t(input) ; product++ ) {
        for ( auto i : allFactors[product] ) {
            primeSet.insert(i);
        }
    }
    return primeSet;
}



/*
map<long long, int> SmallestMultiple::extractIntersection(vector<long long> allFactors[]) {
    // Declarations
    vector<long long> primesAmongst = EulerUtils::gatherPrimesUpTo(INPUT);
    vector<long long> factors[2];
    map<long long, int> primeTally;

    // Populate primeTally with the factor tally of allFactors[0]
    int factor_index = 0;
    for ( int i = 0 ; i < allFactors[0].size ; i++ ) {
        long long factor = allFactors[0][factor_index]
    }



    // Loop thru the available primes...
    for ( auto i = primesAmongst.begin() ; i < primesAmongst.end() ; i++ ) {


        // Start by
        {
            start:


            break;
        }

        // Loop thru the factor sets to identify the primes in each
    }


    return primesAmongst;
}
*/
