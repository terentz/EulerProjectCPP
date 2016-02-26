/*
 * EP0049_PrimePermutations.hpp
 *
 *  Created on: 26/02/2016
 *      Author: terentz
 */

#ifndef EP0049_PRIMEPERMUTATIONS_HPP_
#define EP0049_PRIMEPERMUTATIONS_HPP_
#include <string>
#include <vector>
#include <map>
#include <set>

using std::string;
using std::vector;
using std::map;
using std::set;

namespace PrimePermutations {

void run();
void drillForPerms( string so_far, string remain, vector<string> &perms );
void generateAllPrimes( string so_far, string remain, map<string,int> &primes );
void generateLocalPrimes( string so_far, string remain, vector<string> &primes );
void zeroSingleAdjacencies( const map<int,int> diff_tally, map<string,map<string,int>> &diff_table );
string getDigit( string input, unsigned short idx );
string getDigit( string input, string digit );
string removeDigit( string input, unsigned short idx );
string removeDigit( string input, string digit );
string orderDigits( string input );

};

#endif /* EP0049_PRIMEPERMUTATIONS_HPP_ */
