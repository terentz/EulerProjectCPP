/*
 * EP0019_CountingSundays.cpp
 *
 *  Created on: 23/02/2016
 *      Author: terentz
 */

#include "EP0019_CountingSundays.hpp"
#include "EulerUtils.hpp"
#include <iostream>

using std::cout;
using std::endl;

/* NAMESPACE DEFINES */
#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEP 9
#define OCT 10
#define NOV 11
#define DEC 12

/* FUNCTIONS */

void CountingSundays::run () {

	/* LOCAL DECLARATIONS */
	int sundays = 0;
    int today = 366;

	/* TEST */
    for ( int year = 1901 ; year < 2001 ; year++ ) {
        for ( int month = 1 ; month < 13 ; ++month ) {
            // Check today...
            if ( today % 7 == 0 ) {
                ++sundays;
            }

            // Set the next day...
            int days_in_month;
            switch ( month ) {
                case JAN:
                case MAR:
                case MAY:
                case JUL:
                case AUG:
                case OCT:
                case DEC:
                    today += 31;
                    break;

                case APR:
                case JUN:
                case SEP:
                case NOV:
                    today += 30;
                    break;

                case FEB:
                    if ( year % 4 == 0 && year % 400 != 0 ) today += 29;
                    else today += 28;
                    break;

                default:
                    cout << "Unreachable code!" << endl;
                    break;
            }
        }
    }



	/* DO THE WORK! */


	/* DISPLAY RESULTS */

	cout << "The number of Sundays during the 20th century was " << sundays << endl << endl;

}


