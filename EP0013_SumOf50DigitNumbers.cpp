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


    /* LOCAL DECLARATIONS */
    string nums[100];
    ifstream fin;
    string filename = FILENAME,
           line,
           part,
           sum_str,
           first_ten;
    int subsum_curr = 0,
        subsum_next = 0;
    string sum = "";


	/* DO THE WORK! */

    /* Read the file & populate array */
    fin.open( filename );
    string temp;
    if ( fin.good() ) {
        for ( size_t cell = 0 ; cell < 100 ; ++cell ) {
            std::getline(fin,temp);
            nums[cell] = temp;
        }
    } else {
        cout << "The file " << filename << " was not found!" << endl;
    }
    fin.close();

    /* Build the sum */
    int carry = 0;
    int test = 0;
    cout << "out: " << nums[2] << endl;
    for ( size_t idx = 49; idx>=0 ; --idx ) {
        int sub_sum = carry;
//        cout << "digit column " << idx << ": " ;
        for ( const string &num_str : nums ) {
            int num = num_str[idx]-'0';
//            cout << num;
            test += num;
            sub_sum += (int)(num_str[idx]-'0');
        }
//        cout << endl;
        if ( idx != 0 ) {
            int rh_digit = sub_sum%10;
            sum = std::to_string(rh_digit) + sum;
            carry = sub_sum/10;
        } else {
            sum = std::to_string(sub_sum) + sum;
            break;
        }
    }

//    cout << "sum: " << sum << endl;
//    cout << "test: " << test << endl;
//    for ( auto s : nums ) {
//        cout << s << endl;
//    }



	/* DISPLAY RESULTS */

    string result = sum.substr(0,10);
    cout << "result: " << result << endl;
	cout << endl;

}


