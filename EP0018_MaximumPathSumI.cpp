/*
 * EP0018_MaximumPathSumI.cpp
 *
 *  Created on: 23/02/2016
 *      Author: terentz
 */

#include "EP0018_MaximumPathSumI.hpp"
#include "EulerUtils.hpp"
#include <iostream>
#include <fstream>
#include <typeinfo>

using std::cout;
using std::endl;
using std::ifstream;
using EulerUtils::splitToInt;
using EulerUtils::printVector;

/* NAMESPACE DEFINES */
#define FILENAME "0018_MaximumPathSumI.txt"

/* FUNCTIONS */

void MaximumPathSumI::run () {
//    bruteForceVersion();
    dataTreeVersion();
}

void bruteForceVersion(){}

void MaximumPathSumI::dataTreeVersion() {

    /* LOCAL DECLARATIONS */
    Triangle* triangle = new Triangle();
    triangle->printTree();


	/* DO THE WORK! */
    triangle->traverse();

	/* DISPLAY RESULTS */
    cout << "The maximum path sum is " << triangle->_largest() << endl << endl;
}

MaximumPathSumI::Triangle::Triangle() {
    this->largest = 0;
    this->buildTree();
}
MaximumPathSumI::Triangle::~Triangle() {
    delete &tree;
}
int MaximumPathSumI::Triangle::_largest() {
    return this->largest;
}

void MaximumPathSumI::Triangle::buildTree() {
    size_t level = 0, node = 0;
    string temp_line = "";
    ifstream fin;
    fin.open( FILENAME );
    if ( fin.good() ) {
        while ( std::getline(fin,temp_line) ) {
            const vector<int> row = splitToInt(temp_line, ' ');
            if ( row.size() == 0 ) break;
            this->tree.push_back(row);
        }
    } else {
        cout << "The file " << FILENAME << " was not found!" << endl;
    }
    fin.close();
}
void MaximumPathSumI::Triangle::printTree() {
    for ( size_t level = 0 ; level < DEPTH ; ++level ) {
        EulerUtils::printVector(std::to_string((int)level+1), this->tree[level]);
        cout << endl;
    }
}
void MaximumPathSumI::Triangle::traverse() {
    this->descend((size_t)1, (size_t)0, 0);
}

void MaximumPathSumI::Triangle::descend( size_t row, size_t node, int sum ) {
    int value = this->tree[row-1][node];
    sum += value;
    if ( row == DEPTH ) {
        if ( sum > this->largest ) this->largest = sum;
        return;
    }
    // Loop thru the two available nodes beneath...
    for ( size_t child = node ; child < (node+2) ; ++child ) {
        descend(row+1, child, sum);
    }
}


