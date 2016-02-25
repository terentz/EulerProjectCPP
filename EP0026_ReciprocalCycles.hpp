/*
 * EP0026_ReciprocalCycles.hpp
 *
 *  Created on: 24/02/2016
 *      Author: terentz
 */

#ifndef EP0026_RECIPROCALCYCLES_HPP_
#define EP0026_RECIPROCALCYCLES_HPP_

#include <string>
using std::string;

namespace ReciprocalCycles {

void run ();
int getPeriod( string input, int num_tests );
string compareBlocks( string input, int width, int level );

};

#endif /* EP0026_RECIPROCALCYCLES_HPP_ */
