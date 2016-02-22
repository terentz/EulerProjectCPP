/*
 * EP0024_LexicographicPermutations.hpp
 *
 *  Created on: 22/02/2016
 *      Author: terentz
 */

#ifndef EP0024_LEXICOGRAPHICPERMUTATIONS_HPP_
#define EP0024_LEXICOGRAPHICPERMUTATIONS_HPP_

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace LexicographicPermutations {

void run ();
void buildPerms( vector<string> digits, string acc, int& counter, string& millionth );
void printVec(vector<string> vec);

};

#endif /* EP0024_LEXICOGRAPHICPERMUTATIONS_HPP_ */
