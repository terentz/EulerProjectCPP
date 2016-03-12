/*
 * EP0046_GoldbachsOther.hpp
 *
 *  Created on: 12/03/2016
 *      Author: terentz
 */

#ifndef EP0046_GOLDBACHSOTHER_HPP_
#define EP0046_GOLDBACHSOTHER_HPP_

#include <vector>

using std::vector;

namespace GoldbachsOther {

void run ();
bool fitsGoldbachs(  unsigned int, const vector<unsigned int>& );
bool isTwiceASquare( unsigned int );

};

#endif /* EP0046_GOLDBACHSOTHER_HPP_ */
