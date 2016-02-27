/*
 * EP0037_TruncatablePrimes.hpp
 *
 *  Created on: 26/02/2016
 *      Author: terentz
 */

#ifndef EP0037_TRUNCATABLEPRIMES_HPP_
#define EP0037_TRUNCATABLEPRIMES_HPP_

#include <string>

using std::string;

namespace TruncatablePrimes {

void run ();
bool isTruncatable( unsigned long input );
bool truncate( string input, bool left );
//bool truncRight(  unsigned long input );

};

#endif /* EP0037_TRUNCATABLEPRIMES_HPP_ */
