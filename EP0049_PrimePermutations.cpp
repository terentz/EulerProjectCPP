/*
 * EP0049_PrimePermutations.cpp
 *
 *  Created on: 26/02/2016
 *      Author: terentz
 */



#include "EP0049_PrimePermutations.hpp"
#include "EulerUtils.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>

using std::cout;
using std::endl;
using std::abs;
using std::stoi;
using EulerUtils::Display::printVector;
using EulerUtils::Display::printMap;
using EulerUtils::Display::printSet;
using EulerUtils::NumberTheory::Prime::isPrime;

#define SIZE    4

void PrimePermutations::run () {

	/* LOCAL DECLARATIONS */
    string digits = "123456789";
    map<string,int>  prime_digit_set_tally;
    map<string,map<int,vector<string>>> equal_interval_prime_sequences; // int is the distance


	/* DO THE WORK! */
    // Get Sets with Primes
    generateAllPrimes( string(""), digits, prime_digit_set_tally );
    // Remove those with only 1 or 2 primes..
    for ( auto pdst_it = prime_digit_set_tally.begin() ; pdst_it != prime_digit_set_tally.end() ;  ) {
        if ( pdst_it->second < 3 ) {
            pdst_it = prime_digit_set_tally.erase(pdst_it);
        } else {
            // Isolate the prime versions...
            vector<string> prime_set;
            generateLocalPrimes( string(""), pdst_it->first, prime_set );
            // Graph their differences...
            map<string,map<string,int>> diff_table;
            map<int,int> diff_tally;
            for ( auto y = prime_set.cbegin() ; y != prime_set.cend() ; ++y )
                for ( auto x = prime_set.cbegin() ; x != prime_set.cend() ; ++x ) {
                    int diff = abs( stoi(*x) - stoi(*y) );
                    diff_table[*x][*y] = diff;
                    diff_tally[diff] += 1;
                }
            // Remove 0, 1, and 2 from the tally...
            diff_tally[0] = 0;
            for ( auto d = diff_tally.begin() ; d != diff_tally.end() ;  ) {
                diff_tally[d->first] = d->second / 2 ;
                if ( d->second < 2 ) {
                    d = diff_tally.erase(d);
                    zeroSingleAdjacencies( diff_tally, diff_table  );
                } else ++d;
            }
            // If no twin tallies, jump ahead to the next set...
            if ( diff_tally.size() == 0 ) {
                pdst_it = prime_digit_set_tally.erase(pdst_it);
                continue;
            }
            // Locate the sequences
            for ( auto y = diff_table.cbegin() ; y != diff_table.cend() ; ++y ) {
                map<int,set<string>> row;
                for ( auto x = y->second.cbegin() ; x != y->second.cend() ; ++x ) {
                    int diff = diff_table[x->first][y->first];
                    if ( diff != 0 ) {
                        row[diff].insert(x->first);
                        row[diff].insert(y->first);
                    }
                }
                // Analyse the row...
                for ( auto str_set = row.begin() ; str_set != row.end() ;  ) {
                    int sz = str_set->second.size();
                    if ( sz < 3 )
                        str_set = row.erase(str_set);
                    else {
                        // Test - printing set
                        cout << "printing set..." << endl;
                        for ( auto i = str_set->second.cbegin() ; i != str_set->second.cend() ; ++i )
                            cout << *i << endl;
                        ++str_set;
                    }
                }
            }
            // Test the weighted graph..
            /*
            cout << endl;
            for ( auto x = prime_set.cbegin() ; x != prime_set.cend() ; ++x ) cout << "\t" << *x ;
            cout << endl << endl;
            for ( auto y = prime_set.cbegin() ; y != prime_set.cend() ; ++y ) {
                cout << *y << "\t" ;
                for ( auto x = prime_set.cbegin() ; x != prime_set.cend() ; ++x ) {
                    cout << diff_table[*x][*y] << "\t";
                }
                cout << endl;
            }
            cout << endl;
            */
            // Print the diff tally...
            /*
            cout << "diff tally..." << endl;
            cout << "count: " << diff_tally.size() << endl;
            for ( auto d = diff_tally.cbegin() ; d != diff_tally.cend() ; ++d ) {
                cout << d->first << "\t" << d->second << endl;
            }
            */

            ++pdst_it;
        }
    }

	/* DISPLAY RESULTS */
    cout << "AAAAARRRRGGH, can only get the sample data!?!" << endl;
	cout << endl;
}

void PrimePermutations::zeroSingleAdjacencies( const map<int,int> diff_tally, map<string,map<string,int>> &diff_table ) {
    // Loop thru table...
    for ( auto y = diff_table.begin() ; y != diff_table.end() ; ++y )
        for ( auto x = y->second.begin() ; x != y->second.end() ; ++x ) {
            bool in = false;
            // Loop thru differences....
            for ( auto diff = diff_tally.cbegin() ; diff != diff_tally.cend() ; ++diff )
                if ( diff->first == x->second )
                    in = true;
            if ( !in )
                diff_table[x->first][y->first] = 0;
        }
}

void PrimePermutations::generateLocalPrimes( string so_far, string remain, vector<string> &primes ) {
    // If so_far is long enough, test for prime, and return
    if ( so_far.size() == SIZE ) {
        if ( isPrime(std::stoi(so_far)) )
            primes.push_back(so_far);
        return;
    } else
        for ( unsigned short idx = 0 ; idx < remain.size() ; ++idx )
            generateLocalPrimes( so_far+remain.substr(idx,1), removeDigit(remain,idx), primes );
}
void PrimePermutations::generateAllPrimes( string so_far, string remain, map<string,int> &primes ) {
    // If so_far is long enough, test for prime, and return
    if ( so_far.size() == SIZE ) {
        if ( isPrime(std::stoi(so_far)) )
            ++primes[orderDigits(so_far)];
        return;
    }
    else
        for ( unsigned short idx = 0 ; idx < remain.size() ; ++idx )
            generateAllPrimes( so_far+remain.substr(idx,1), removeDigit(remain,idx), primes );
}
void PrimePermutations::drillForPerms( string so_far, string remain, vector<string> &perms ) {
}

string PrimePermutations::getDigit( string input, unsigned short idx ) {
    if ( idx >= input.size() ) return "";
    return input.substr(idx,1);
}
string PrimePermutations::getDigit( string input, string digit ) {
    if ( std::stoi(digit) < 1 || std::stoi(digit) > 9 ) return "";
    for ( short idx = 0 ; idx < input.size() ; ++idx )
        if ( input.substr(idx,1) == digit )
            return input.substr(idx,1);
    return "";
}
string PrimePermutations::removeDigit( string input, unsigned short idx ) {
    if ( idx >= input.size() ) return "";
    return input.substr(0,idx)+input.substr(idx+1);
}
string PrimePermutations::removeDigit( string input, string digit ) {
    if ( std::stoi(digit) < 1 || std::stoi(digit) > 9 ) return "";
    for ( short idx = 0 ; idx < input.size() ; ++idx )
        if ( input.substr(idx,1) == digit )
            return input.substr(0,idx)+input.substr(idx+1);
    return "";
}
string PrimePermutations::orderDigits( string input ) {
    vector<string> vec;
    string output = "";
    for ( char c = 0 ; c < input.size() ; ++c )
        vec.push_back(input.substr(c,1));
    sort(vec.begin(),vec.end());
    for ( auto i = vec.cbegin() ; i != vec.cend() ; ++i )
        output += *i;
    return output;
}
