/*
 * EP0023_NonAbundantSums.cpp
 *
 *  Created on: 27/02/2016
 *      Author: terentz
 */

#include "EP0023_NonAbundantSums.hpp"
#include "EulerUtils.hpp"
#include <iostream>

using std::cout;
using std::endl;
using EulerUtils::Display::printVector;
using EulerUtils::NumberTheory::Special::perfection;


/* NAMESPACE DEFINES */
#define TEST    50
#define SKY     28123

/* FUNCTIONS */

void NonAbundantSums::run () {

	/* LOCAL DECLARATIONS */
    vector<unsigned int> abundant_nums ;
    unsigned long long sum = 0;


	/* DO THE WORK! */
	// Populate the abundant numbers set...
	for ( int p = 1 ; p < SKY ; ++p )
        if ( perfection(p) == 1 )
            abundant_nums.push_back(p);
    int set_size = abundant_nums.size();

    // Loop thru numbers from 1 to SKY to test them
    for ( unsigned long long n = 1 ; n <= SKY ; ++n ) {
        if ( n < 24 )
            sum += n;
        else{
            bool is_sum_of_abundants = false;
            for ( auto lhs = abundant_nums.cbegin() ; *lhs < n ; ++lhs ) {
                for ( auto rhs = abundant_nums.cbegin() ; *rhs < n ; ++rhs ) {
                    if ( (*lhs)+(*rhs) == n ) {
                        is_sum_of_abundants = true;
                        break;
                    }
                    if ( is_sum_of_abundants )  break;
                }
                if ( !is_sum_of_abundants )  sum += n;
            }
        }
    }


    /* TEST */
	printVector(string("abundant numbers"), abundant_nums);

	/* DISPLAY RESULTS */
    cout << "The sum is " << sum << endl;
    cout << endl;
}


