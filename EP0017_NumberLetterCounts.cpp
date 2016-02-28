/*
 * EP0017_NumberLetterCounts.cpp
 *
 *  Created on: 28/02/2016
 *      Author: terentz
 */

#include "EP0017_NumberLetterCounts.hpp"
#include "EulerUtils.hpp"
#include <iostream>
#include <map>


using std::cout;
using std::endl;
using std::map;

/* NAMESPACE DEFINES */
#define LIMIT       10
#define TWENTY      6
#define THIRTY      6
#define FORTY       5
#define FIFTY       5
#define SIXTY       5
#define SEVENTY     7
#define EIGHTY      6
#define NINETY      6
#define HUNDRED     7


/* FUNCTIONS */

void NumberLetterCounts::run () {

	/* LOCAL DECLARATIONS */
    unsigned int sum = 0;
    const map<unsigned short,unsigned short> digit_str_lens = {
            {0,0}, {1,3}, {2,3}, {3,5}, {4,4},
            {5,4}, {6,3}, {7,5}, {8,5}, {9,4}
        };
    const map<unsigned short,unsigned short> teen_str_lens = {
            {0,3}, {1,6}, {2,6}, {3,8}, {4,8},
            {5,7}, {6,7}, {7,9}, {8,8}, {9,8}
        };
    const map<unsigned short,unsigned short> tens_str_lens = {
            {2,6}, {3,6}, {4,5}, {5,5},
            {6,5}, {7,7}, {8,6}, {9,6}
        };


	/* DO THE WORK! */

	for ( unsigned short col_hun = 0 ; col_hun < 10 ; ++col_hun ) {
        for ( unsigned short col_ten = 0 ; col_ten < 10 ; ++col_ten ) {
            for ( unsigned short col_dig = 0 ; col_dig < 10 ; ++col_dig ) {
                unsigned short word_length=0;
                if ( col_hun > 0 ) word_length += digit_str_lens.at(col_hun) + HUNDRED + ( ( col_ten==0 && col_dig==0 ) ? 0 : 3 );
                switch ( col_ten ) {
                    case 0:
                        word_length += digit_str_lens.at(col_dig);
                        break;
                    case 1:
                        word_length += teen_str_lens.at(col_dig);
                        break;
                    default:
                        word_length += tens_str_lens.at(col_ten) + digit_str_lens.at(col_dig);
                        break;
                }
                sum += word_length;
            }
        }
	}

//    str = drillForColumn( string(""), current, 2, sum_ref );

    sum += string("onethousand").size();

	/* DISPLAY RESULTS */
    cout << "The sum of the letters used to print out one to one thousand is "
         << sum << endl << endl;

}

//string NumberLetterCounts::drillForColumn( string so_far, unsigned short digit, unsigned short magnitude, unsigned int &sum ) {
//
//    for ( unsigned short digit = 0 ; digit < 10 ; ++digit ) {
//        string temp;
//        if ( so_far.size) {
//
//        }
//        else {
//            switch ( magnitude ) {
//                case 2: // 100's
//                    switch ( digit ) {
//                        case 0: // nothing
//                            break;
//                        case 1:
//                        case 2:
//                        case 3:
//                        case 4:
//                    }
//                    break;
//                case 1: // double digits
//                    switch ( digit )
//                case 0: // singles
//
//            }
//        }
//
//
//    }
//
//}
//
//}

