/*
 * EP0038_PandigitalMultiples.cpp
 *
 *  Created on: 28/02/2016
 *      Author: terentz
 */

#include "EP0038_PandigitalMultiples.hpp"
#include "EulerUtils.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::to_string;
using std::stoi;
using EulerUtils::NumberTheory::Special::Pandigital::isPandigital;

/* NAMESPACE DEFINES */
//#define CONST val


/* FUNCTIONS */

void PandigitalMultiples::run () {

    vector<unsigned int> pandigitals;

	// Iterate thru digits 1 to the largest possible factor with four digits..
    for ( unsigned short test = 1 ; test < 9877 ; ++test ) {

        string pan_test = "";

        for ( unsigned short digit_multiple = 1 ; pan_test.size() < 10 ; ++digit_multiple ) {
            pan_test += to_string( (unsigned int)digit_multiple * (unsigned int)test );
            if ( pan_test.size() < 10 && isPandigital( pan_test ) ) {
                cout << "pantest = " << pan_test << endl;
                unsigned int temp = stoi(pan_test);
                pandigitals.push_back( (unsigned int)stoi(pan_test) );
                break;
            }
        }

    }

    // Iterate thru the pandigitals to find the largest
    unsigned int largest = 0;
    for ( auto i = pandigitals.cbegin() ; i != pandigitals.cend() ; ++i )
        if ( *i > largest )
            largest = *i;

	/* DISPLAY RESULTS */

	cout << "The largest 'pandigital multiple' is " << largest << endl << endl;

}


