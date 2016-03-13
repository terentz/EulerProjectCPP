//============================================================================
// Name         : EulerProject.cpp
// Author       : Tristan Rentz
// Version      :
// Copyright    : nada
// Description  : EulerProject in C++, Ansi-style
// TODO		    - Bitwise implementations.
//              - String numeric class.
//              - Refactor for C++11
//              - add default bool includeZero=false parameter to isPandigital()
//============================================================================


/***********  INCLUDES  ***********/
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
#include "EulerUtils.hpp"


/**********  EULER  MODULES  **********/
// TEMPLATE line
//#include "EPxxxx_Title.hpp"
//#include "EP0001_3and5.hpp" // DONE
//#include "EP0002_EvenFibonacci.hpp" // DONE
//#include "EP0003_LargestPrimeFactor.hpp" // DONE
//#include "EP0004_LargestPalindromeProduct.hpp" // DONE
//#include "EP0005_SmallestMultiple.hpp" // DONE
//#include "EP0006_SumSquareDifference.hpp" // DONE
//#include "EP0007_10001StPrime.hpp" // DONE
//#include "EP0008_LargestProductInASeries.hpp" // DONE
//#include "EP0009_SpecialPythagoreanTriad.hpp" // DONE
//#include "EP0010_SummationOfPrimes.hpp" // DONE
//#include "EP0011_LargestProductInAGrid.hpp" // DONE
//#include "EP0012_HighlyDivisibleTriangularNumber.hpp" // DONE
//#include "EP0013_SumOf50DigitNumbers.hpp" // DONE
//#include "EP0014_LongestCollatz.hpp" // DONE
//#include "EP0015_LatticePaths.hpp" // DONE
//#include "EP0016_PowerDigitSum.hpp" // DONE
//#include "EP0017_NumberLetterCounts.hpp"
//#include "EP0018_MaximumPathSumI.hpp" // DONE
//#include "EP0019_CountingSundays.hpp" // DONE
//#include "EP0020_FactorialDigitSum.hpp" // DONE
//#include "EP0021_SumOfAmicableNumbers.hpp" // DONE
//#include "EP0022_NamesScores.hpp" // DONE
//#include "EP0023_NonAbundantSums.hpp" // DONE
//#include "EP0024_LexicographicPermutations.hpp" // DONE
#include "EP0025_OneThousandDigitFibonacci.hpp"
//#include "EP0026_ReciprocalCycles.hpp" // DONE
#include "EP0027_QuadraticPrimes.hpp"
//#include "EP0028_NumberSpiralDiagonals.hpp" // DONE
#include "EP0029_DistinctPowers.hpp"
//#include "EP0030_DigitFifthPowers.hpp" // DONE
//#include "EP0031_CoinSums.hpp" // DONE
#include "EP0032_PandigitalProducts.hpp"
#include "EP0033_DigCanFrac.hpp"
#include "EP0034_DigitFactorials.hpp"
//#include "EP0035_CircularPrimes.hpp" // DONE
//#include "EP0036_DoubleBasePalindromes.hpp" // DONE
//#include "EP0037_TrsuncatablePrimes.hpp" // DONE
//#include "EP0038_PandigitalMultiples.hpp" // DONE
#include "EP0039_IntegerRightTriangles.hpp"
//#include "EP0040_Champerdowne.hpp" // DONE
//#include "EP0041_PandigitalPrime.hpp"
#include "EP0043_SubstringDivisibility.hpp"
//#include "EP0046_GoldbachsOther.hpp" // DONE
//#include "EP0049_PrimePermutations.hpp"
//#include "EP0050_ConsecutivePrimeSum.hpp"
//#include "EP0059_XORDecryption.hpp"
//#include "EP0061_CyclicalFigurateNumbers.hpp"
//#include "EP0064_OddPeriodSquareRoots.hpp"
//#include "EP9999_EndOfTheWorld.hpp"

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
using namespace EulerUtils::Timer;


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
#define EP0004_LARGESTPALINDROMEPRODUCT		    4
#define EP0005_SMALLESTMULTIPLE				    5
#define EP0006_SUMSQUAREDIFFERENCE			    6
#define EP0007_100001STPRIME					7
#define EP0008_LARGESTPRODUCTINASERIES			8
#define EP0009_SPECIALPYTHAGOREANTRIAD	        9
#define EP0010_SUMMATIONOFPRIMES		        10
#define EP0011_LARGESTPRODUCTINAGRID			11
#define EP0012_HIGHLYDIVISIBLETRIANGULARNUMBER  12
#define EP0013_SUMOF50DIGITNUMBERS              13
#define EP0014_LONGESTCOLLATZ                   14
#define EP0015_LATTICEPATHS                     15
#define EP0016_POWERSUMDIGIT                    16
#define EP0017_NUMBERLETTERCOUNTS               17
#define EP0018_MAXIMUMPATHSUMI                  18
#define EP0019_COUNTINGSUNDAYS                  19
#define EP0020_FACTORIALDIGITSUM                20
#define EP0021_SUMOFAMICABLENUMBERS             21
#define EP0022_NAMESSCORES                      22
#define EP0023_NONABUNDANTSUMS                  23
#define EP0024_LEXICOGRAPHICPERMUTATIONS        24
#define EP0025_ONETHOUSANDDIGITFIBONACCI        25
#define EP0026_RECIPROCALCYCLES                 26
#define EP0027_QUADRATICPRIMES                  27
#define EP0028_NUMBERSPIRALDIAGONALS            28
#define EP0029_DISTINCTPOWERS                   29
#define EP0030_DIGITFIFTHPOWERS                 30
#define EP0031_COINSUMS                         31
#define EP0032_PANDIGITALPRODUCTS               32
#define EP0033_DIGCANFRAC                       33
#define EP0034_DIGITFACTORIALS                  34
#define EP0035_CIRCULARPRIMES                   35
#define EP0036_DOUBLEBASEPALINDROMES            36
#define EP0037_TRUNCATABLEPRIMES                37
#define EP0038_PANDIGITALMULTIPLES              38
#define EP0039_INTEGERRIGHTTRIANGLES            39
#define EP0040_CHAMPERDOWNE				        40
#define EP0041_PANDIGITALPRIME                  41
#define EP0043_SUBSTRINGDIVISIBILITY            43
#define EP0046_GOLDBACHSOTHER                   46
#define EP0049_PRIMEPERMUTATIONS                49
#define EP0050_CONSECUTIVEPRIMESUM              50
#define EP0059_XORDECRYPTION                    59
#define EP0061_CYCLICALFIGURATENUMBERS          61
#define EP0064_ODDPERIODSQUAREROOTS             64
#define EP9999_ENDOFTHEWORLD                    9999



int printMenu( map<int, string>items, int last_key );

int main() {

	std::map<int, string> menu_items;

/* full list of items */
menu_items[QUIT_PROGRAM]                            = "Quit program";
//menu_items[EP0001_3AND5] 		                    = "Multiples of 3 and 5";
//menu_items[EP0002_EVENFIBONACCI] 				    = "Even Fibonacci numbers";
//menu_items[EP0003_LARGESTPRIMEFACTOR]			    = "Largest Prime Factor";
//menu_items[EP0004_LARGESTPALINDROMEPRODUCT] 	    = "Largest Palindrome Product";
//menu_items[EP0005_SMALLESTMULTIPLE] 			    = "Smallest multiple";
//menu_items[EP0006_SUMSQUAREDIFFERENCE] 		        = "Sum Square Difference";
//menu_items[EP0007_100001STPRIME] 				    = "10001st Prime";
//menu_items[EP0008_LARGESTPRODUCTINASERIES] 	        = "Largest Product in a Series";
//menu_items[EP0009_SPECIALPYTHAGOREANTRIAD]      	= "Special Pythagorean Triad";
//menu_items[EP0010_SUMMATIONOFPRIMES] 			    = "Summation of Primes";
//menu_items[EP0011_LARGESTPRODUCTINAGRID] 	        = "Largest Product In A Grid";
//menu_items[EP0012_HIGHLYDIVISIBLETRIANGULARNUMBER]  = "Highly Divisible Triangular Number";
//menu_items[EP0013_SUMOF50DIGITNUMBERS]              = "Sum of One Hundred 50-digit Numbers";
//menu_items[EP0014_LONGESTCOLLATZ]                   = "Longest Collatz Sequence";
//menu_items[EP0015_LATTICEPATHS]                     = "The Number of Lattice Paths Through a Grid";
//menu_items[EP0016_POWERSUMDIGIT]                    = "The sum of the digits of 2^1000";
//menu_items[EP0017_NUMBERLETTERCOUNTS]               = "Number Letter Counts";
//menu_items[EP0018_MAXIMUMPATHSUMI]                  = "The Maximum Path Sum through a Trianglular grid I";
//menu_items[EP0019_COUNTINGSUNDAYS]                  = "Counting Sundays";
//menu_items[EP0020_FACTORIALDIGITSUM]                = "Factorial Digit Sum";
//menu_items[EP0021_SUMOFAMICABLENUMBERS]             = "The Sum of Amicable Numbers";
//menu_items[EP0022_NAMESSCORES]                      = "Names Scores";
//menu_items[EP0023_NONABUNDANTSUMS]                  = "Non-abundant Sums";
//menu_items[EP0024_LEXICOGRAPHICPERMUTATIONS]        = "The Millionth Lexicographic Permutation of 0-9";
menu_items[EP0025_ONETHOUSANDDIGITFIBONACCI]        = "1000-digit Fibonacci";
//menu_items[EP0026_RECIPROCALCYCLES]                 = "Reciprocal Cycles";
menu_items[EP0027_QUADRATICPRIMES]                  = "Quadratic Primes";
//menu_items[EP0028_NUMBERSPIRALDIAGONALS]            = "NumberSpiralDiagonals";
menu_items[EP0029_DISTINCTPOWERS]                   = "Distinct Powers";
//menu_items[EP0030_DIGITFIFTHPOWERS]                 = "Digit Fifth Powers";
//menu_items[EP0031_COINSUMS]                         = "CoinSums";
menu_items[EP0032_PANDIGITALPRODUCTS]               = "Pandigital Products";
menu_items[EP0033_DIGCANFRAC]                       = "Digital Cancelled Fractions";
menu_items[EP0034_DIGITFACTORIALS]                  = "Digit Factorials";
//menu_items[EP0035_CIRCULARPRIMES]                   = "Circular Primes";
//menu_items[EP0036_DOUBLEBASEPALINDROMES]            = "Double-base palindromes";
//menu_items[EP0037_TRUNCATABLEPRIMES]                = "Truncatable Primes";
//menu_items[EP0038_PANDIGITALMULTIPLES]              = "Pandigital Primes";
menu_items[EP0039_INTEGERRIGHTTRIANGLES]            = "Integer Right Triangles";
//menu_items[EP0040_CHAMPERDOWNE] 		            = "Champerdowne's Constant";
//menu_items[EP0041_PANDIGITALPRIME]                  = "Pandigital Prime";
menu_items[EP0043_SUBSTRINGDIVISIBILITY]            = "Sub-string divisibility";
//menu_items[EP0046_GOLDBACHSOTHER]                   = "GoldbachsOther";
//menu_items[EP0049_PRIMEPERMUTATIONS]                = "Prime Permutations";
//menu_items[EP0050_CONSECUTIVEPRIMESUM]              = "Consecutive Prime Sum";
//menu_items[EP0059_XORDECRYPTION]                    = "XOR Decryption";
//menu_items[EP0061_CYCLICALFIGURATENUMBERS]          = "Cyclical Figurate Numbers";
//menu_items[EP0064_ODDPERIODSQUAREROOTS]             = "Odd Periodic Square Roots";
//menu_items[EP9999_ENDOFTHEWORLD]                    = "End of the world!";
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

//            case EP0001_3AND5:
//                using ThreeAndFive::run;
//                ThreeAndFive::run();
//                break;

//            case EP0002_EVENFIBONACCI:
//                using EvenFibonacci::run;
//                EvenFibonacci::run();
//                break;

//            case EP0003_LARGESTPRIMEFACTOR:
//                using LargestPrimeFactor::run;
//                LargestPrimeFactor::run();
//                break;

//            case EP0004_LARGESTPALINDROMEPRODUCT:
//                using LargestPalindromeProduct::run;
//                LargestPalindromeProduct::run();
//                break;

//            case EP0005_SMALLESTMULTIPLE:
//                using SmallestMultiple::run;
//                SmallestMultiple::run();
//                break;

//            case EP0006_SUMSQUAREDIFFERENCE:
//                using SumSquareDifference::run;
//                SumSquareDifference::run();
//                break;

//            case EP0007_100001STPRIME:
//                using TenThousandFirstPrime::run;
//                TenThousandFirstPrime::run();
//                break;

//            case EP0008_LARGESTPRODUCTINASERIES:
//                using LargestProductInASeries::run;
//                LargestProductInASeries::run();
//                break;

//            case EP0009_SPECIALPYTHAGOREANTRIAD:
//                using SpecialPythagoreanTriad::run;
//                SpecialPythagoreanTriad::run();
//                break;

//            case EP0010_SUMMATIONOFPRIMES:
//                using SummationOfPrimes::run;
//                SummationOfPrimes::run();
//                break;

//    		case EP0011_LARGESTPRODUCTINAGRID:
//                using LargestProductInAGrid::run;
//                LargestProductInAGrid::run();
//                break;

//            case EP0012_HIGHLYDIVISIBLETRIANGULARNUMBER:
//                using HighlyDivisibleTriangularNumber::run;
//                HighlyDivisibleTriangularNumber::run();
//                break;

//            case EP0013_SUMOF50DIGITNUMBERS:
//                using SumOf50DigitNumbers::run;
//                SumOf50DigitNumbers::run();
//                break;

//            case EP0014_LONGESTCOLLATZ:
//                using LongestCollatz::run;
//                LongestCollatz::run();
//                break;

//            case EP0015_LATTICEPATHS:
//                using LatticePaths::run;
//                LatticePaths::run();
//                break;

//            case EP0016_POWERSUMDIGIT:
//                using PowerDigitSum::run;
//                PowerDigitSum::run();
//                break;

//            case EP0017_NUMBERLETTERCOUNTS:
//                using NumberLetterCounts::run;
//                NumberLetterCounts::run();
//                break;

//            case EP0018_MAXIMUMPATHSUMI:
//                using MaximumPathSumI::run;
//                MaximumPathSumI::run();
//                break;

//            case EP0019_COUNTINGSUNDAYS:
//                using CountingSundays::run;
//                CountingSundays::run();
//                break;

//            case EP0020_FACTORIALDIGITSUM:
//                using FactorialDigitSum::run;
//                FactorialDigitSum::run();
//                break;

//            case EP0021_SUMOFAMICABLENUMBERS:
//                using SumOfAmicableNumbers::run;
//                SumOfAmicableNumbers::run();
//                break;

//            case EP0022_NAMESSCORES:
//                using NamesScores::run;
//                NamesScores::run();
//                break;

//            case EP0023_NONABUNDANTSUMS:
//                using NonAbundantSums::run;
//                NonAbundantSums::run();
//                break;

//            case EP0024_LEXICOGRAPHICPERMUTATIONS:
//                using LexicographicPermutations::run;
//                LexicographicPermutations::run();
//                break;

            case EP0025_ONETHOUSANDDIGITFIBONACCI:
                using OneThousandDigitFibonacci::run;
                OneThousandDigitFibonacci::run();
                break;

//            case EP0026_RECIPROCALCYCLES:
//                using ReciprocalCycles::run;
//                ReciprocalCycles::run();
//                break;

            case EP0027_QUADRATICPRIMES:
                using QuadraticPrimes::run;
                QuadraticPrimes::run();
                break;

//            case EP0028_NUMBERSPIRALDIAGONALS:
//                using NumberSpiralDiagonals::run;
//                NumberSpiralDiagonals::run();
//                break;

            case EP0029_DISTINCTPOWERS:
                using DistinctPowers::run;
                DistinctPowers::run();
                break;

//            case EP0030_DIGITFIFTHPOWERS:
//                using DigitFifthPowers::run;
//                DigitFifthPowers::run();
//                break;

//            case EP0031_COINSUMS:
//                using CoinSums::run;
//                CoinSums::run();
//                break;

            case EP0032_PANDIGITALPRODUCTS:
                using PandigitalProducts::run;
                PandigitalProducts::run();
                break;

            case EP0033_DIGCANFRAC:
                using DigCanFrac::run;
                DigCanFrac::run();
                break;

            case EP0034_DIGITFACTORIALS:
                using DigitFactorials::run;
                DigitFactorials::run();
                break;

//            case EP0035_CIRCULARPRIMES:
//                using CircularPrimes::run;
//                CircularPrimes::run();
//                break;

//            case EP0036_DOUBLEBASEPALINDROMES:
//                using DoubleBasePalindromes::run;
//                DoubleBasePalindromes::run();
//                break;

//            case EP0037_TRUNCATABLEPRIMES:
//                using TruncatablePrimes::run;
//                TruncatablePrimes::run();
//                break;

//            case EP0038_PANDIGITALMULTIPLES:
//                using PandigitalMultiples::run;
//                PandigitalMultiples::run();
//                break;

            case EP0039_INTEGERRIGHTTRIANGLES:
                using IntegerRightTriangles::run;
                IntegerRightTriangles::run();
                break;

//            case EP0040_CHAMPERDOWNE:
//                using Champerdowne::run;
//                Champerdowne::run();
//                break;

//            case EP0041_PANDIGITALPRIME:
//                using PandigitalPrime::run;
//                PandigitalPrime::run();
//                break;

case EP0043_SUBSTRINGDIVISIBILITY:
using SubstringDivisibility::run;
SubstringDivisibility::run();
break;

//            case EP0046_GOLDBACHSOTHER:
//                using GoldbachsOther::run;
//                GoldbachsOther::run();
//                break;

//            case EP0049_PRIMEPERMUTATIONS:
//                using PrimePermutations::run;
//                PrimePermutations::run();
//                break;

//            case EP0050_CONSECUTIVEPRIMESUM:
//                using ConsecutivePrimeSum::run;
//                ConsecutivePrimeSum::run();
//                break;

//            case EP0059_XORDECRYPTION:
//                using XORDecryption::run;
//                XORDecryption::run();
//                break;

//            case EP0061_CYCLICALFIGURATENUMBERS:
//                using CyclicalFigurateNumbers::run;
//                CyclicalFigurateNumbers::run();
//                break;

//            case EP0064_ODDPERIODSQUAREROOTS:
//                using OddPeriodSquareRoots::run;
//                OddPeriodSquareRoots::run();
//                break;

//            case EP9999_ENDOFTHEWORLD:

            // TODO use the template below to add a new module above this line
            /*
            case EP:
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
                cout << "This module is not included in the current build," << endl
                     << "check EulerProject.cpp and your makefile..." << endl;
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
