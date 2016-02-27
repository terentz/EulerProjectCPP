/*
 * EPxxxx_EulerTemplate.hpp
 *
 *  Created on: 13/12/2013
 *      Author: terentz
 */

#ifndef EP0011_LARGESTPRODUCTINAGRID_HPP_
#define EP0011_LARGESTPRODUCTINAGRID_HPP_

#include "EulerUtils.hpp"



namespace LargestProductInAGrid {

void run();
void arrayVersion();
int tl_to_br( const int grid[20][20], const int side, const int run );
int tr_to_bl( const int grid[20][20], const int side, const int run );
int horizontal( const int grid[20][20], const int side, const int run );
int vertical( const int grid[20][20], const int side, const int run );

//void pointerVersion();
//class BlackBox : GridArr {
//protected:
//// attributes
//	short range;
//	long long champ;
//
//// utility for checking and calculating each direction
//	void checkThreeOClock ( int x , int y );
//	void checkFourThirty ( int x , int y );
//	void checkSixOClock ( int x , int y );
//	void checkSevenThirty ( int x , int y );
//
//// update the record for the largest product
//	void updateChamp ( long long input );
//
//public:
//// constructors
//	BlackBox ( );
//	BlackBox ( string filename, int w, int h, int num_adjacent_blocks );
//	virtual ~BlackBox ( );
//
//// main loop
//	void execute( );
//
//// public worker method
//	void processCellSurrounds ( int x , int y );
//
//// get & set largest
//	void setChamp( long long val );
//	const long long getChamp();
//
//};





};

#endif /* EP0011_LARGESTPRODUCTINAGRID_HPP_ */
