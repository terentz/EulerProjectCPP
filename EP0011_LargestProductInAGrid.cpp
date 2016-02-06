/*
 * EP0011_LargestProductInAGrid.cpp
 *
 *  Created on: 13/12/2013
 *      Author: terentz
 */

#include "EP0011_LargestProductInAGrid.hpp"
#include "EulerUtils.hpp"
#include <iostream>
#include <fstream>
#include <boost/lexical_cast.hpp>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::fstream;
using std::string;
using EulerUtils::GridArr;


/* CONSTANTS */
#define GRID_WIDTH 	20
#define GRID_DEPTH 20
#define FILENAME 	"0011_LargestProductInAGrid.txt"
#define RUN_SIZE 	5


/* functions */
// TODO review the need for this function
/*
void LargestProductInAGrid::run () {
	// init's
	cout << "In LargestProductInAGrid::run()..." << endl;
	string filename = FILENAME;
	cout << "File name read.." << endl;
	// create and populate grid
	//GridArr grid( filename, GRID_WIDTH, GRID_DEPTH );
	//cout << "Grid populated.." << endl;

	// start the timer
	double elapsed, finish, start = getMilliSecs();
	cout << "Timer started..." << endl;

	// test line
	//grid.print();


	// do the work!

	BlackBox box( filename , GRID_WIDTH , GRID_DEPTH , RUN_SIZE );
	//




	// stop the timer
	finish = getMilliSecs();
	elapsed = transSecs(start, finish);

	// clean up
	//grid.~GridArr();

	// display results
	cout << "Processing took " << elapsed << "secs" << endl;
	cout << endl;

}
*/

/*void LargestProductInAGrid::run() {
	BlackBox box( FILENAME, GRID_WIDTH, GRID_DEPTH, RUN_SIZE );

}*/
/*
LargestProductInAGrid::BlackBox::BlackBox ( string filename,
											int w,
											int h,
											int num_adjacent_blocks
											) : GridArr( filename, w, h ){
{
	this->range = num_adjacent_blocks - 1;
	this->champ = 0;
}
*/
/*
LargestProductInAGrid::BlackBox::BlackBox ( string filename = FILENAME,
											int w = GRID_WIDTH,
											int h = GRID_DEPTH,
											int num_adjacent_blocks = RUN_SIZE
											)
								: GridArr ( filename, w, h )
{
	this->range = num_adjacent_blocks - 1;
	this->champ = 0;
}*/

/*LargestProductInAGrid::BlackBox::BlackBox ( ) {
	GridArr ( FILENAME, GRID_WIDTH, GRID_DEPTH );
	this->range = RUN_SIZE - 1;
	this->champ = 0;
}*/

void LargestProductInAGrid::BlackBox::execute() {

	// iterate thru rows
	for ( int y = 0 ; y < GridArr::depth() ; y++ ) {
		// iterate thru cells
		for (  int x = 0 ; x < GridArr::width() ; x++ ) {
			// rock around the clock!
			checkThreeOClock 	( x , y );
			checkFourThirty 	( x , y );
			checkSixOClock 		( x , y );
			checkSevenThirty 	( x , y );
		}
	}
}


// protected methods
void LargestProductInAGrid::BlackBox::checkThreeOClock ( int x , int y ) {
	if ( ( x + (this->range) ) < GridArr::width() ) {
		// do the calc
		long long product = 1 ;
		// test line
		int count = 0;
		// iterate thru offsets
		for ( int xOff = 0 , yOff = 0 ; xOff <= this->range ; xOff++ ) {
			product *= GridArr::intCellContent( x + xOff , y );
			// test line
			count++;
		}
		// test lines
		cout << count << " iterations were performed in BlackBox::checkThreeOClock" << endl <<
						"The resulting product is " << product << endl ;
		// check the result
		if ( product > this->getChamp() )
			this->setChamp(product);
	}
}
void LargestProductInAGrid::BlackBox::checkFourThirty ( int x , int y ) {
	if ( ( x + (this->range) ) < GridArr::width() &&
			( y + (this->range) ) < GridArr::depth() ) {
		// do the calc
		long long product = 1 ;
		// test line
		int count = 0;
		// iterate thru offsets
		for ( int xOff = 0 , yOff = 0 ; xOff <= this->range && yOff <= this->range ; xOff++ , yOff++ ) {
			product *= GridArr::intCellContent( x + xOff , y + yOff );
			// test line
			count++;
		}
		// test lines
		cout << count << " iterations were performed in BlackBox::checkFourThirty" << endl <<
						"The resulting product is " << product << endl ;
		// check the result
		if ( product > this->getChamp() )
			this->setChamp(product);
	}
}
void LargestProductInAGrid::BlackBox::checkSixOClock ( int x , int y ) {
	if ( ( y + (this->range) ) < GridArr::depth() ) {
		// do the calc
		long long product = 1 ;
		// test line
		int count = 0;
		// iterate thru offsets
		for ( int xOff = 0 , yOff = 0 ; yOff <= this->range ; yOff++ ) {
			product *= GridArr::intCellContent( x , y + yOff );
			// test line
			count++;
		}
		// test lines
		cout << count << " iterations were performed in BlackBox::checkSixOClock" << endl <<
						"The resulting product is " << product << endl ;
		// check the result
		if ( product > this->getChamp() )
			this->setChamp(product);
	}
}
void LargestProductInAGrid::BlackBox::checkSevenThirty ( int x , int y ) {
	if ( ( x - (this->range) ) >= 0 &&
			( y + (this->range) ) < GridArr::depth() ) {
		// do the calc
		long long product = 1 ;
		// test line
		int count = 0;
		// iterate thru offsets
		for ( int xOff = 0 , yOff = 0 ; xOff <= this->range && yOff <= this->range ; xOff++ , yOff++ ) {
			product *= GridArr::intCellContent( x + xOff , y - yOff );
			// test line
			count++;
		}
		// test lines
		cout << count << " iterations were performed in BlackBox::checkFourThirty" << endl <<
						"The resulting product is " << product << endl ;
		// check the result
		if ( product > this->getChamp() )
			this->setChamp(product);
	}
}
void LargestProductInAGrid::BlackBox::updateChamp ( long long input ) {
	if ( input > this->champ )
		setChamp( input );
}


/* get, set utilities */
const long long LargestProductInAGrid::BlackBox::getChamp() {
	return this->champ;
}

void LargestProductInAGrid::BlackBox::setChamp( long long val ) {
	this->champ = val;
}


