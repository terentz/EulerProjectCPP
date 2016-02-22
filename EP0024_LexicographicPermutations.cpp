/*
 * EP0024_LexicographicPermutations.cpp
 *
 *  Created on: 22/02/2016
 *      Author: terentz
 */

#include "EP0024_LexicographicPermutations.hpp"
#include "EulerUtils.hpp"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;


void LexicographicPermutations::run () {

	/* LOCAL DECLARATIONS */
    const vector<string> digits = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
    int counter = 0;
    int& counterRef = counter;
    string m = "";
    string& millionth = m;


	/* DO THE WORK! */
    buildPerms( digits, std::string(""), counterRef, millionth );


	/* DISPLAY RESULTS */
    cout << "Result: " << millionth << endl;
	cout << endl;

}

void LexicographicPermutations::buildPerms( vector<string> digits, string acc, int& counter, string& millionth ) {
    size_t remain = digits.size();
    if ( remain == 1 ) {
        acc += digits[0];
        ++counter;
        cout << acc << endl;
        if ( counter == 1000000 ) millionth = acc;
    } else {
        for ( size_t idx = 0 ; idx < remain ; ++idx ) {
            // Get the next digit, and remove if from the vector
            string temp = digits[idx];
            digits.erase( digits.begin()+idx );
            // Call yourself!
            buildPerms( digits, acc+temp, counter, millionth );
            // Reset the vector
            digits.emplace( digits.begin()+idx, temp );
        }
    }
}

void LexicographicPermutations::printVec(vector<string> vec) {
    cout << "Printing vector..." << endl;
    cout << "{ " ;
    for ( auto i = vec.cbegin() ; i != vec.cend() ; ++i ) {
        cout << *i;
        if ( i == vec.cend()-1 ) {} else cout << ", ";
    }
    cout << " }" << endl;
}


