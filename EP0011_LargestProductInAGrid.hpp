/*
 * EPxxxx_EulerTemplate.hpp
 *
 *  Created on: 13/12/2013
 *      Author: terentz
 */

#ifndef EP0011_LARGESTPRODUCTINAGRID_HPP_
#define EP0011_LARGESTPRODUCTINAGRID_HPP_

#include "EulerUtils.hpp"

using EulerUtils::GridArr;


namespace LargestProductInAGrid {

void run();

class BlackBox : GridArr {
protected:
// attributes
	short range;
	long long champ;

// utility for checking and calculating each direction
	void checkThreeOClock ( int x , int y );
	void checkFourThirty ( int x , int y );
	void checkSixOClock ( int x , int y );
	void checkSevenThirty ( int x , int y );

// update the record for the largest product
	void updateChamp ( long long input );

public:
// constructors
	BlackBox ( );
	BlackBox ( string filename, int w, int h, int num_adjacent_blocks );
	virtual ~BlackBox ( );

// main loop
	void execute( );

// public worker method
	void processCellSurrounds ( int x , int y );

// get & set largest
	void setChamp( long long val );
	const long long getChamp();

};





};

#endif /* EP0011_LARGESTPRODUCTINAGRID_HPP_ */
