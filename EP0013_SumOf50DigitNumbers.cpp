/*
 * EPxxxx_EulerTemplate.cpp
 *
 *  Created on: 13/12/2013
 *      Author: terentz
 */

#include "EP0013_SumOf50DigitNumbers.hpp"
#include "EulerUtils.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include "Prime.hpp"
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;

//using boost::multiprecision::int256_t;
using boost::lexical_cast;
//using EulerUtils::numToString;
//using boost::multiprecision::int128_t;

/* local defines */
#define FILENAME "0013_SumOf50DigitNumbers.txt"

/* functions */

void SumOf50DigitNumbers::run () {


    /* local declarations */
    ifstream f;
    string filename = FILENAME,
           line,
           part,
           sum_str,
           first_ten;
    long sum = 0,
         val = 0;

	/* do the work! */
    f.open( filename.c_str() );
    if ( f.good() ) {
        while ( getline( f, line ) ) {
            part = line.substr(0,12);
            val = boost::lexical_cast<long>(part);
            sum += val;
        }
        sum_str = boost::lexical_cast<string>(sum);
        first_ten = sum_str.substr(0, 10);
        cout << "The result is " << first_ten << endl;
    } else {
        cout << "The file " << filename << " was not found!" << endl;
    }
    f.close();

	/* display results */

	cout << endl;

}


