/*
 * EP0018_MaximumPathSumI.hpp
 *
 *  Created on: 23/02/2016
 *      Author: terentz
 */

#ifndef EP0018_MAXIMUMPATHSUMI_HPP_
#define EP0018_MAXIMUMPATHSUMI_HPP_

#define DEPTH 15

#include <vector>
#include <stdlib.h>
#include <string>

using std::vector;

namespace MaximumPathSumI {

void run ();

void bruteForceVersion();
void dataTreeVersion();
//void descend( vector<int> (&tri)[], size_t level, int sum, int& largest );

class Triangle {
public:
    Triangle();
    virtual ~Triangle();

    int _largest();

    void buildTree();
    void printTree();
    void traverse();

protected:
    void descend( size_t row, size_t node, int sum );

private:
    vector<vector<int>> tree;
    int largest;

};
};

#endif /* EP0018_MAXIMUMPATHSUMI_HPP_ */
