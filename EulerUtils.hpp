/*
 * EulerUtils.hpp
 *
 *  Created on: 16/11/2013
 *      Author: terentz
 */

#ifndef EULERUTILS_HPP_
#define EULERUTILS_HPP_


#include <sys/time.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>
#include <boost/multiprecision/cpp_int.hpp>
//#include <ctime>
#include <time.h>

using namespace std;
using std::endl;
using std::cout;
using boost::lexical_cast;
using boost::bad_lexical_cast;
using boost::multiprecision::int256_t;
using std::string;
using std::vector;


namespace EulerUtils {

/********************
*** Timer methods ***
********************/
inline struct timeval getTime() {
	struct timeval t;
	gettimeofday(&t, NULL);
	return t;
}

inline void printDiff( const long diffMicro) {
	if ( diffMicro > 999999 ) {
		// print seconds
		printf("Processing took %0.3fsecs\n", ((float)diffMicro / 1000000.0f) );
	} else if ( diffMicro > 999 ) {
		// print milliseconds
		printf("Processing took %0.3fms\n", ((float)diffMicro / 1000.0f) );
	} else {
		// print microseconds
		printf("Processing took %1d\u00b5s\n", diffMicro);
	}
}


/********************
*** Miscellaneous ***
***    inlines    ***
********************/

inline bool even( int num ) { return ( num % 2 == 0 ); };

// TODO template the next three..
inline unsigned long long factorial( unsigned long long x ) {
  return ( x == 1 ? x : x * factorial( x - 1 ) );
};

inline int256_t factorial( int256_t x ) {
    return ( x == 1 ? x : x * factorial( x - 1 ) );
};

inline unsigned long long nPr( unsigned long long n, unsigned long long r ) {
    return ( n == ( n - r ) ? 1 : n * nPr( n - 1, r ) );
};

inline int256_t nPr( int256_t n, int256_t r ) {
    return ( n == ( n - r ) ? 1 : n * nPr( n - 1, r ) );
};

inline bool even(long long n) {
    return ( n % 2 == 0 );
};

int strToInt ( string input );


/*********************
**** FACTORISING *****
*********************/
vector<long long>& integerDivisors( long long input );
vector<long long>& primeFactors( long long input );


/********************
** String Splitter **
********************/
class splitstring : public string {
    vector<string> flds;
public:
    splitstring( char *s );
    //virtual ~splitstring();

    vector<string> getFlds() { return this->flds; }
    const string getFld( int index ) { return this->flds[index]; }

    vector<string>& split(char delim, int rep=0);

}; /* end splitstring class definition */


/******************************
** Arrays & Vectors **
******************************/
// TODO can these first two be merged using more templating??
//template<typename T>	// for 1-D vector
void printVector ( string itemName, const vector<long long> input );

template<class TYPE>	// for 1-D array
void printArray ( string itemName, const TYPE data[] );

// TODO can this be made into an extension of the first (1-D) functions
template<class TYPE>	// for 2-D array
void printGrid ( string itemName, const TYPE data[][20] ); //
bool inVector( vector<long long>& haystack, long long needle );


/***********************************
** Class for 2-D Arrays / Vectors **
***********************************/

class GridArr {
protected:
	int wd, dp;
	string ** str_grid;
	int ** int_grid;
public:
// constructors and destructor
	GridArr();
	GridArr( string filename );
	GridArr( int w, int d );
	GridArr( string filename, int w, int d );
	virtual ~GridArr();

// main methods
	bool populate( string filename );
	void print( string name="unnamed" );

// init grids
	void initGrids( int w , int d );
	void initIntGrid( int w , int d );
	void initStrGrid( int w , int d );

// get grids
//	const string ** getStrGrid();
//	const int ** getIntGrid();
	string ** getStrGrid();
	int ** getIntGrid();

// get dimensions
	const int width();
	const int depth();

// cell content
	const int intCellContent( int x , int y );

};

class GridVec {
private:
	int wd, dp;
	vector<vector<string> > str_grid;
	vector<vector<int> > int_grid;
public:
	GridVec();
	GridVec( string filename );
	GridVec( string filename , int w, int d );
	GridVec( int w, int d );
	//virtual ~GridVec();

	bool populate( string filename );
	void print( string name="unnamed" );
};


/*************************
*** Numbers to strings ***
*************************/

template <class N>
string numToString( N num );


/*****************
***** PRIMES *****
*****************/
bool isPrime( long long input );

	//long nextPrime( long input );
long long nextPrime( long long input );

//	long nthPrime( long n );
long long nthPrime( long long n );

long long primesFactorial( long long n );
// TODO finish this generalised problem class
/*
class Problem {
private:
	struct timeval startTime;
	struct timeval endTime;
	long time;

public:
	void startTimer();
	void stopTimer();
	void resetTimer();

	long getTime();
	void setTime(long);
};
*/



}; /* namespace EulerUtils */


#endif /* EULERUTILS_HPP_ */
