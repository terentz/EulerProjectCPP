/*
 * EP0030_DigitFifthPowers.cpp
 *
 *  Created on: 27/02/2016
 *      Author: terentz
 */

#include "EP0030_DigitFifthPowers.hpp"
#include "EulerUtils.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::stoi;
using std::to_string;

/* NAMESPACE DEFINES */using std::stoi;

#define _2POW5  32
#define _3POW5  243
#define _4POW5  1024
#define _5POW5  3125
#define _6POW5  7776
#define _7POW5  16807
#define _8POW5  32768
#define _9POW5  59049
#define START   10
#define SZ_LIM  6
#define NUM_LIM 354294

/* FUNCTIONS */

void DigitFifthPowers::run () {

	/* LOCAL DECLARATIONS */
    const map<unsigned short,unsigned int> i_pow_5 = {
            {0,0}, {1,1}, {2,32}, {3,243},
            {4,1024}, {5,3125}, {6,7776},
            {7,16807}, {8,32768}, {9,59049}
        };
    string temp;
    unsigned int sum = 0,
                temp_sum;

	/* DO THE WORK! */
    for ( unsigned long int current = START ; current <= NUM_LIM ; ++current ) {
        temp = to_string(current);
        temp_sum = 0;
        for ( unsigned short digit = 0 ; digit < temp.size() ; ++digit ) {
            temp_sum += i_pow_5.at((unsigned short)stoi(temp.substr(digit,1)));
        }
        if ( temp_sum == current ) {
            // Test..
            cout << current << " is the sum of the 5th powers of its digits!" << endl;
            sum += temp_sum;
        }
    }

	/* DISPLAY RESULTS */
    cout << "The sum of all the numbers that can be written as the sum of the 5th powers of their digits is " << sum << endl << endl;

}


