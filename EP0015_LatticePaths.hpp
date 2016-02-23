/*
 * EP0015_LatticePaths.hpp
 *
 *  Created on: 23/02/2016
 *      Author: terentz
 */

#ifndef EP0015_LATTICEPATHS_HPP_
#define EP0015_LATTICEPATHS_HPP_

namespace LatticePaths {

void run ();

void recursiveVersion();

void factorialVersion();
void move_one( short curr_x, short curr_y, short man_d, const short limit, long& paths );

void directVersion();

};

#endif /* EP0015_LATTICEPATHS_HPP_ */
