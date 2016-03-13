/*
 * EP0036_DoubleBasePalindromes.cpp
 *
 *  Created on: 13/03/2016
 *      Author: terentz
 */

#include "EP0036_DoubleBasePalindromes.hpp"
#include "EulerUtils.hpp"
#include <iostream>
#include <bitset>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::bitset;
using EulerUtils::NumberTheory::General::isPalindrome;
using EulerUtils::Strings::isPalindrome;
using EulerUtils::Strings::removePaddingZeros;

/* NAMESPACE DEFINES */
#define LIMIT   1000000


/* FUNCTIONS */

void DoubleBasePalindromes::run () {

	/* LOCAL DECLARATIONS */
    unsigned long int sum = 0;

	/* DO THE WORK! */
    for ( unsigned int test = 1 ; test < LIMIT ; ++test )
        if ( isPalindrome( test ) && isPalindrome( removePaddingZeros( bitset<20>( test ).to_string() ) ) )
            sum += test;

	/* DISPLAY RESULTS */
	cout << "The sum of dbl-base palindromes under " << LIMIT << " is " << sum << endl << endl;

}


