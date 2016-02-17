/*
 * EP0005_SmallestMultiple.hpp
 *
 *  Created on: 06/02/2016
 *      Author: terentz
 */

#ifndef EP0005_SMALLESTMULTIPLE_HPP_
#define EP0005_SMALLESTMULTIPLE_HPP_

#include <vector>
#include <map>
#include <set>

using std::vector;
using std::map;
using std::multiset;
using std::set;


namespace SmallestMultiple {

void run();

const set<long long> getPrimesUsed( const vector<long long> allFactors[], const int input );
//map<long long, int> extractCommonFactors(vector<long long> allFactors[]);



};

#endif /* EPXXXX_EULERTEMPLATE_HPP_ */
