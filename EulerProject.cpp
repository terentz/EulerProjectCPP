//============================================================================
// Name        : EulerProject.cpp
// Author      : Tristan Rentz
// Version     :
// Copyright   : nada
// Description : EulerProject in C++, Ansi-style
// TODO		   - Time int, long int, and long long int calculations - using
//				the same int32 value, and compare results.
//			   - Organise EulerUtils.cpp/.hpp into static classes etc..
//			   - Move Prime.cpp to EulerUtils.cpp
//			   - Create a generalised class for new problems
//============================================================================


/****************  STL  ****************/
#include <iostream>
#include <boost/assign/std/vector.hpp>
#include <boost/lexical_cast.hpp>
//#include <ncurses.h>
#include <string>
#include <stdio.h>
#include <map>
#include <limits>
#include <sys/time.h>
#include <time.h>



/**********  EULER  MODULES  **********/
// TEMPLATE line
// #include "EPxxxx_Title.hpp"
#include "EP0001_3and5.hpp"
#include "EP0002_EvenFibonacci.hpp"
#include "EP0003_LargestPrimeFactor.hpp"
#include "EP0004_LargestPalindromeProduct.hpp"
#include "EP0005_SmallestMultiple.hpp"
#include "EP0006_SumSquareDifference.hpp"
#include "EP0007_10001StPrime.hpp"
#include "EP0008_LargestProductInASeries.hpp"
#include "EP0009_SpecialPythagoreanTriad.hpp"
#include "EP0010_SummationOfPrimes.hpp"
#include "EP0011_LargestProductInAGrid.hpp"
#include "EP0012_HighlyDivisibleTriangularNumber.hpp"
#include "EP0013_SumOf50DigitNumbers.hpp"
#include "EP0014_LongestCollatz.hpp"
#include "EP0015_LatticePaths.hpp"
#include "EP0016_PowerDigitSum.hpp"
#include "EP0018_MaximumPathSumI.hpp"
#include "EP0019_CountingSundays.hpp"
#include "EP0020_FactorialDigitSum.hpp"
#include "EP0021_SumOfAmicableNumbers.hpp"
#include "EP0022_NamesScores.hpp"
#include "EP0024_LexicographicPermutations.hpp"
#include "EP0026_ReciprocalCycles.hpp"
#include "EP0028_NumberSpiralDiagonals.hpp"
#include "EP0040_Champerdowne.hpp"


// test lines
#include "EulerUtils.hpp"


/************************************
***********  MAIN USAGES  ***********
************************************/
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::streamsize;

using namespace boost::assign;
using namespace EulerUtils;


/************  DEFINES  ************/
// TODO use the template line below to define a new Euler module
// #define EPxxxx_TITLE	X
/* exceptional menu items */
#define SELECTION_INVALID_TYPE 	-1
#define SELECTION_OUT_OF_RANGE	-2
#define SELECTION_INACTIVE	    -3
#define SELECTION_TEST_CASE 	-5
#define QUIT_PROGRAM			0

#define EP0001_3AND5					        1
#define EP0002_EVENFIBONACCI					2
#define EP0003_LARGESTPRIMEFACTOR				3
#define EP0004_LARGESTPALINDROMEPRODUCT			4
#define EP0005_SMALLESTMULTIPLE				    5
#define EP0006_SUMSQUAREDIFFERENCE				6
#define EP0007_100001STPRIME					7
#define EP0008_LARGESTPRODUCTINASERIES			8
#define EP0009_SPECIALPYTHAGOREANTRIAD			9
#define EP0010_SUMMATIONOFPRIMES				10
#define EP0011_LARGESTPRODUCTINAGRID			11
#define EP0012_HIGHLYDIVISIBLETRIANGULARNUMBER	12
#define EP0013_SUMOF50DIGITNUMBERS              13
#define EP0014_LONGESTCOLLATZ                   14
#define EP0015_LATTICEPATHS                     15
#define EP0016_POWERSUMDIGIT                    16
#define EP0018_MAXIMUMPATHSUMI                  18
#define EP0019_COUNTINGSUNDAYS                  19
#define EP0020_FACTORIALDIGITSUM                20
#define EP0021_SUMOFAMICABLENUMBERS             21
#define EP0022_NAMESSCORES                      22
#define EP0024_LEXICOGRAPHICPERMUTATIONS        24
#define EP0026_RECIPROCALCYCLES                 26
#define EP0028_NUMBERSPIRALDIAGONALS            28
#define EP0040_CHAMPERDOWNE				        40


/***********  STRUCTS  ************/

/**********  PROTOTYPES  **********/

int printMenu( map<int, string>items, int last_key );

/**********  MAIN METHOD  **********/

int main() {

	std::map<int, string> menu_items;

	/* full list of items */
	menu_items[QUIT_PROGRAM]                            = "Quit program";
	menu_items[EP0001_3AND5] 		                    = "Multiples of 3 and 5";
	menu_items[EP0002_EVENFIBONACCI] 				    = "Even Fibonacci numbers";
	menu_items[EP0003_LARGESTPRIMEFACTOR]			    = "Largest Prime Factor";
	menu_items[EP0004_LARGESTPALINDROMEPRODUCT] 	    = "Largest Palindrome Product";
	menu_items[EP0005_SMALLESTMULTIPLE] 			    = "Smallest multiple";
	menu_items[EP0006_SUMSQUAREDIFFERENCE] 		        = "Sum Square Difference";
	menu_items[EP0007_100001STPRIME] 				    = "10001st Prime";
	menu_items[EP0008_LARGESTPRODUCTINASERIES] 	        = "Largest Product in a Series";
	menu_items[EP0009_SPECIALPYTHAGOREANTRIAD]      	= "Special Pythagorean Triad";
	menu_items[EP0010_SUMMATIONOFPRIMES] 			    = "Summation of Primes";
	menu_items[EP0011_LARGESTPRODUCTINAGRID] 	        = "Largest Product In A Grid";
	menu_items[EP0012_HIGHLYDIVISIBLETRIANGULARNUMBER]  = "Highly Divisible Triangular Number";
	menu_items[EP0013_SUMOF50DIGITNUMBERS]              = "Sum of One Hundred 50-digit Numbers";
	menu_items[EP0014_LONGESTCOLLATZ]                   = "Longest Collatz Sequence";
	menu_items[EP0015_LATTICEPATHS]                     = "The Number of Lattice Paths Through a Grid";
	menu_items[EP0016_POWERSUMDIGIT]                    = "The sum of the digits of 2^1000";
	menu_items[EP0018_MAXIMUMPATHSUMI]                  = "The Maximum Path Sum through a Trianglular grid I";
	menu_items[EP0019_COUNTINGSUNDAYS]                  = "Counting Sundays";
	menu_items[EP0020_FACTORIALDIGITSUM]                = "Factorial Digit Sum";
	menu_items[EP0021_SUMOFAMICABLENUMBERS]             = "The Sum of Amicable Numbers";
	menu_items[EP0022_NAMESSCORES]                      = "Names Scores";
	menu_items[EP0024_LEXICOGRAPHICPERMUTATIONS]        = "The Millionth Lexicographic Permutation of 0-9";
	menu_items[EP0026_RECIPROCALCYCLES]                 = "Reciprocal Cycles";
	menu_items[EP0028_NUMBERSPIRALDIAGONALS]            = "NumberSpiralDiagonals";
	menu_items[EP0040_CHAMPERDOWNE] 		            = "Champerdowne's Constant";

	// TODO add a new menu item on the line above, using the line below
	//menu_items[EPxxxx_XXXXXXXXXXXXXXXXX] 			= "";


	// count the menu items and get the last
//	const int number_of_items = menu_items.size();
	const int last_key = (--menu_items.end())->first;

	// run the program
	bool go = true;
	cout << "Welcome to Tristan's Euler Project" << endl ;

	/* main run loop */
	while ( go ) {

		// display menu and get user selection
		int sel = printMenu( menu_items, last_key );
		//int sel = EP0012_HIGHLYDIVISIBLETRIANGULARNUMBER;


        // IGNORE WARNINGS! DO NOT COMMENT THE FOLLOWING LINE!!!
        bool valid_selection = false;


		// start timer
		struct timeval start, end;
		long diffMicro;
//		start = getTime();
//		cout << "Timer started..." << endl ;

		// check selection
		switch ( sel ) {

            // TODO code for test cases
            case SELECTION_TEST_CASE:
                cout << "'SELECTION_TEST_CASE' not yet implemented!" << endl;
                break;

            /* exceptional cases */

            case SELECTION_INVALID_TYPE:
                cout << "You must select an integer, from 1 to " << last_key << "." << endl;
                break;
            case SELECTION_OUT_OF_RANGE:
                cout << "Your selection is out of range. Please choose from 1 to " << last_key << "." << endl;
                break;
            case SELECTION_INACTIVE:
                cout << "The module you selected is currently out of order. Please try again." << endl;
                break;

            /* quit program */
            case QUIT_PROGRAM:
            //case 0:
                cout << "Thank. Bye now..." << endl;
                go = false;
                return 0;

            /* valid menu selections */
            default:
                valid_selection = true;
                cout << "You have selected " << menu_items[sel] << endl;
                start = getTime();
                cout << "Timer started..." << endl;
        }

        // module executions...
        switch ( sel ) {

            case EP0001_3AND5:
                using ThreeAndFive::run;
                ThreeAndFive::run();
                break;

            case EP0002_EVENFIBONACCI:
                using EvenFibonacci::run;
                EvenFibonacci::run();
                break;

            case EP0003_LARGESTPRIMEFACTOR:
                using LargestPrimeFactor::run;
                LargestPrimeFactor::run();
                break;

            case EP0004_LARGESTPALINDROMEPRODUCT:
                using LargestPalindromeProduct::run;
                LargestPalindromeProduct::run();
                break;

            case EP0005_SMALLESTMULTIPLE:
                using SmallestMultiple::run;
                SmallestMultiple::run();
                break;

            case EP0006_SUMSQUAREDIFFERENCE:
                using SumSquareDifference::run;
                SumSquareDifference::run();
                break;

            case EP0007_100001STPRIME:
                using TenThousandFirstPrime::run;
                TenThousandFirstPrime::run();
                break;

            case EP0008_LARGESTPRODUCTINASERIES:
                using LargestProductInASeries::run;
                LargestProductInASeries::run();
                break;

            case EP0009_SPECIALPYTHAGOREANTRIAD:
                using SpecialPythagoreanTriad::run;
                SpecialPythagoreanTriad::run();
                break;

            case EP0010_SUMMATIONOFPRIMES:
                using SummationOfPrimes::run;
                SummationOfPrimes::run();
                break;

    		case EP0011_LARGESTPRODUCTINAGRID:
//                using LargestProductInAGrid::BlackBox;
                using LargestProductInAGrid::run;
                LargestProductInAGrid::run();
                //BlackBox box;
                //box.execute();
                //box.run();
                break;

            case EP0012_HIGHLYDIVISIBLETRIANGULARNUMBER:
                using HighlyDivisibleTriangularNumber::run;
                HighlyDivisibleTriangularNumber::run();
                break;

            case EP0013_SUMOF50DIGITNUMBERS:
                using SumOf50DigitNumbers::run;
                SumOf50DigitNumbers::run();
                break;

            case EP0014_LONGESTCOLLATZ:
                using LongestCollatz::run;
                LongestCollatz::run();
                break;

            case EP0015_LATTICEPATHS:
                using LatticePaths::run;
                LatticePaths::run();
                break;

            case EP0016_POWERSUMDIGIT:
                using PowerDigitSum::run;
                PowerDigitSum::run();
                break;

            case EP0018_MAXIMUMPATHSUMI:
                using MaximumPathSumI::run;
                MaximumPathSumI::run();
                break;

            case EP0019_COUNTINGSUNDAYS:
                using CountingSundays::run;
                CountingSundays::run();
                break;

            case EP0020_FACTORIALDIGITSUM:
                using FactorialDigitSum::run;
                FactorialDigitSum::run();
                break;

            case EP0021_SUMOFAMICABLENUMBERS:
                using SumOfAmicableNumbers::run;
                SumOfAmicableNumbers::run();
                break;

            case EP0022_NAMESSCORES:
                using NamesScores::run;
                NamesScores::run();
                break;

            case EP0024_LEXICOGRAPHICPERMUTATIONS:
                using LexicographicPermutations::run;
                LexicographicPermutations::run();
                break;

            case EP0026_RECIPROCALCYCLES:
                using ReciprocalCycles::run;
                ReciprocalCycles::run();
                break;

            case EP0028_NUMBERSPIRALDIAGONALS:
                using NumberSpiralDiagonals::run;
                NumberSpiralDiagonals::run();
                break;

            case EP0040_CHAMPERDOWNE:
                using Champerdowne::run;
                Champerdowne::run();
                break;

            // TODO use the template below to add a new module above this line
            /*
            case :
                using ::run;
                ::run();
                break;
            */


            /* exceptional cases */

            case SELECTION_TEST_CASE:
                break;

            case SELECTION_INVALID_TYPE:
            case SELECTION_OUT_OF_RANGE:
            case SELECTION_INACTIVE:
            case QUIT_PROGRAM:
                break;

            /* unreachable */
            default:
                cout << "Tristan, this code's meant to be unreachable!!" << endl <<
                        "You might have a menu entry without an accompanying module.." << endl;
                break;
		} /* END switch ( sel ) {} */


		// finalise selection execution
		switch ( sel ) {

            // TODO code for test cases
            case SELECTION_TEST_CASE:
                break;

            // non-executing 'sel' values
            case SELECTION_INVALID_TYPE:
            case SELECTION_OUT_OF_RANGE:
            case SELECTION_INACTIVE:
                break;

            // valid... end timer!
            default:
                end = getTime();
                diffMicro = ( ( end.tv_sec - start.tv_sec ) * 1000000L + end.tv_usec - start.tv_usec );
                printDiff(diffMicro);
        }



		// continue loop
		if ( sel != SELECTION_INVALID_TYPE &&
				sel != SELECTION_OUT_OF_RANGE &&
				sel != SELECTION_INACTIVE ) {
			cout << "Hit Enter to continue..." << endl;

			cin.ignore();
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

		}
	} /* END main program loop */








	return 0;
}


/***********  UTILITIES  ***********/

int printMenu( map<int, string>items, int last_key ) {
	map<int, string>::iterator iter;
	cout << "Select from the menu.. " << endl << endl;
	for ( iter = items.begin() ; iter != items.end() ; iter++ ) {
        if ( (*iter).first >= 0 )
            cout << "\t" << (*iter).first  << ". " << (*iter).second << "." << endl;
	}
	//cout << "\t" << QUIT_PROGRAM << ". Quit program." << endl << endl;
	cout << ">> ";
	string _sel;
	cin >> _sel;
	// debug
	//cout << "debug- sel: " << _sel << endl;

	try {
		const int sel = boost::lexical_cast<int>(_sel);
		// selection is an integer
		// test line
		//cout << "selection = " << sel << endl;

		// is a test case being run?
		if ( sel == SELECTION_TEST_CASE ) {
			return SELECTION_TEST_CASE;
		}
		// is it in range?
		else if ( sel < 0 || sel > last_key ) {
			return SELECTION_OUT_OF_RANGE;
		}
		// it's in range, but is it active?
		//else if ( items.find(sel) == items.end() && sel!=0 ) {
		//else if ( items.count(const_cast<int>(sel)) == 0 )
		else if ( items.count(sel) == 0 ) {
			return SELECTION_INACTIVE;
		}
		// return the valid selection
		else {
			return sel;
		}
	// it's not an integer
	} catch ( boost::bad_lexical_cast const& err ) {
		cout << "error: " << err.what() << endl;
		return SELECTION_INVALID_TYPE;
	}

}
