/*
 * EP0008_LargestProductInASeries.cpp
 *
 *  Created on: 29/11/2013
 *      Author: terentz
 */

#include "EP0008_LargestProductInASeries.hpp"
#include "EulerUtils.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <boost/lexical_cast.hpp>

using std::endl;
using std::cout;
using std::ifstream;
using std::string;

#define FILENAME "0008_LargestProductInASeries.txt"
#define NUM_FACTORS 5
#define SIZE_OF_CONTROL 1000

namespace LargestProductInASeries {

void run () {

	// get the control number from the file in the resources (res) folder
	string control_str, filename;
	filename = FILENAME;
	ifstream f;
	f.open(filename.c_str());
	if ( f.good() ) {
		f >> control_str;
	} else {
		cout << "Filename defined in EP0008_LargestProductInASeries.cpp is invalid!" << endl;
		return;
	}

	// loop thru the sets of consecutive five...
	long largest = 0;
	for ( int fst_fact = 0 ; fst_fact < ( control_str.size() - NUM_FACTORS ) ; fst_fact++ ) {

		// check for zeroes
		if ( control_str[fst_fact] == '0' ||
				control_str[fst_fact+1] == '0' ||
				control_str[fst_fact+2] == '0' ||
				control_str[fst_fact+3] == '0' ||
				control_str[fst_fact+4] == '0' ) {
			continue;
		}

		// get the digits
		short digits[5];
		for ( int dig = 0 ; dig < NUM_FACTORS ; dig++ ) {
			try {
				digits[dig] = boost::lexical_cast<int>( control_str[fst_fact+dig] );
			} catch( boost::bad_lexical_cast const& ) {
			    cout << "Error: input string was not valid" << std::endl;
			}
		}

		// get sum and product
		int product, current;
		for ( product=1, current=0 ; current < NUM_FACTORS ; current++ ) {
			product *= digits[current];
			if ( product > largest ) {
				largest = product;
			}
		}
	}

	// print results
	cout << "The greatest product of any 5 consecutive digits in the number " << endl <<
			control_str << endl << " is " << largest << endl;
}

} /* namespace LargestProductInASeries */

