/*
 * EP0022_NamesScores.cpp
 *
 *  Created on: 24/02/2016
 *      Author: terentz
 */

#include "EP0022_NamesScores.hpp"
#include "EulerUtils.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using EulerUtils::Strings::split;

/* NAMESPACE DEFINES */
#define FILENAME "0022_names.txt"

void NamesScores::run () {

    /* INIT'S */
    vector<string> names;
    ifstream fin;
    long total = 0;
    int pos = 0;

	/* DO THE WORK! */

    // Open the file and populate names...
    fin.open( FILENAME );
    string tmp_ln = "";
    if ( fin.good() ) {
        while ( std::getline(fin,tmp_ln) ) {
            names = split( tmp_ln, ',' );
            std::sort( names.begin(), names.end() );
            for ( auto name = names.cbegin() ; name < names.cend() ; ++name )
                total += nameSum( *name, ++pos );
            break;
        }
    } else {
        cout << "The file " << FILENAME << " was not found!" << endl;
    }
    fin.close();

	/* DISPLAY RESULTS */
    cout << "The sum of the name scores is " << total << endl << endl;

}

long NamesScores::nameSum( string name, int pos ) {
    long sum = 0;
    cout << "pos " << pos << endl;
    for ( int c = 0 ; c < name.size() ; ++c ) {
        char ch = name[c];
        if ( ch != '"' )  sum += (int)( ch - '@' );
    }
    return pos*sum;
}
