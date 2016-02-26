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
#include <map>
#include <set>
#include <boost/lexical_cast.hpp>
#include <boost/multiprecision/cpp_int.hpp>
//#include <ctime>
#include <time.h>
#include <gmp.h>

//using namespace std;
using std::endl;
using std::cout;
using boost::lexical_cast;
using boost::bad_lexical_cast;
using boost::multiprecision::int256_t;
using boost::multiprecision::int512_t;
using boost::multiprecision::int1024_t;
using boost::multiprecision::uint256_t;
using boost::multiprecision::uint512_t;
using boost::multiprecision::uint1024_t;
using std::string;
using std::vector;
using std::map;
using std::set;


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
		printf("Processing took %ld\u00b5s\n", diffMicro);
	}
}


/********************
*** Miscellaneous ***
***    inlines    ***
********************/

//inline bool even( int num ) { return ( num % 2 == 0 ); };
template<typename I>
inline bool even( I num ) { return ( num % 2 == 0 ); };

template<typename I>
inline bool pstv( I num ) { return ( num > 0 ); };
template<typename I>
inline bool ngtv( I num ) { return ( num < 0 ); };
// TODO template the next three..
inline unsigned long long factorial( unsigned long long x ) {
    if ( x == 0 ) return 1;
    return ( x == 1 ? x : x * factorial( x - 1 ) );
};
inline int256_t factorial( int256_t x ) {
    if ( x == 0 ) return 1;
    return ( x == 1 ? x : x * factorial( x - 1 ) );
};
inline int512_t factorial( int512_t x ) {
    if ( x == 0 ) return 1;
    return ( x == 1 ? x : x * factorial( x - 1 ) );
};
inline int1024_t factorial( int1024_t x ) {
    if ( x == 0 ) return 1;
    return ( x == 1 ? x : x * factorial( x - 1 ) );
};
inline uint256_t factorial( uint256_t x ) {
    if ( x == 0 ) return 1;
    return ( x == 1 ? x : x * factorial( x - 1 ) );
};
inline uint512_t factorial( uint512_t x ) {
    if ( x == 0 ) return 1;
    return ( x == 1 ? x : x * factorial( x - 1 ) );
};
inline uint1024_t factorial( uint1024_t x ) {
    if ( x == 0 ) return 1;
    return ( x == 1 ? x : x * factorial( x - 1 ) );
};


/*
inline mpz_t& mpz_factorial( mpz_t n ) {
    // Define zero and one...
    char* zero_str = "0";
    char* one_str = "1";
    mpz_t zero, one;
    mpz_init(zero);
    mpz_init(one);
    mpz_set_ui(zero,0);
    mpz_set_ui(one,0);
    int f0 = mpz_set_str(zero,zero_str,10);
    int f1 = mpz_set_str(one,one_str,10);
    assert(f0 == 0);
    assert(f1 == 0);

    // If n is 0 or 1, return 1...
    if ( mpz_cmp(n,zero) == 0
            || mpz_cmp(n,one) == 0 )
//        return 1;
        return one;

    // Otherwise, recurse it...
    else {
        // Init result, lhs, rhs...
        mpz_t result, lhs, rhs;
        mpz_inits (result, lhs, rhs);
        mpz_set_ui(result,0);
        mpz_set_ui(lhs,0);
        mpz_set_ui(rhs,0);
        char* n_str;
        mpz_get_str(n_str, 10, n);
        int f_lhs = mpz_set_str(lhs, n_str, 10);
//        int f_rhs = mpz_set_str(rhs, n_str, 10);
        assert(f_lhs == 0);
//        assert(f_rhs == 0);

        // Make rhs one less than lhs...
        mpz_sub_ui(rhs,lhs,1);

        // Calculate the result...
        mpz_mul_ui(result,lhs,mpz_factorial(rhs));

        // Return it...
        return result;
    }
};
*/


inline unsigned long long nCr( unsigned long long n, unsigned long long r ) {
//    cout << (float)( factorial(n) / ( factorial(r) * factorial(n-r) ) ) << endl;
//    return 0;

    return ( factorial(n) / ( factorial(r) * factorial(n-r) ) );
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
const std::vector<int> splitToInt( const std::string &s, char delim );

/*********************
**** FACTORISING *****
*********************/
//vector<long long> integerDivisors( long long input );
set<long long> intFactors( long long input );
vector<long long> primeFactorsSet( long long input );
const vector<long long> primeFactorsAll( long long input );
long long gcd( long long a, long long b );


/********************
** String Splitter **
********************/
const std::vector<std::string> split( const std::string &s, char delim );
class splitstring : public string {
    vector<string> flds;
public:
    splitstring( char *s );
    //virtual ~splitstring();

    vector<string> getFlds() { return this->flds; }
    const string getFld( int index ) { return this->flds[index]; }

    vector<string>& split(char delim, int rep=0);

}; /* end splitstring class definition */


/**********************
***** COLLECTIONS *****
**********************/
// TODO can these first two be merged using more templating??
//template<typename T>	// for 1-D vector
//void printVector ( string itemName, const vector<T>& data );
void printVector ( string itemName, const vector<long long>& data, bool down = false );
void printVector ( string itemName, const vector<int> data, bool down = false );
void printVector ( string itemName, const vector<string> data, bool down = false );

template<class TYPE>	// for 1-D array
void printArray ( string itemName, const TYPE data[] );

// TODO can this be made into an extension of the first (1-D) functions
template<class TYPE>	// for 2-D array
void printGrid ( string itemName, const TYPE data[][20] ); //
template<class Container>
void printCollection ( string const& itemName, Container const& data );
template <typename K, typename V>
void printMap ( string itemName, const map<K,V>& data );
void printMap ( string itemName, const map<long long, int>& data );
void printMap ( string itemName, const map<string, int>& data );
void printSet ( string itemName, const set<long long>& data );
bool inVector( vector<long long>& haystack, long long needle );
int countAppearance( vector<long long> haystack, long long needle );
long long product( vector<long long> input );
const int countItem( const vector<long long> haystack, const long long needle );

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

vector<long long> gatherPrimesUpTo( long long n );


/******************************
***** OTHER NUMBER THEORY *****
******************************/

const long long nthTriangularNumber( const long long term );

/*****************
***** COUNTS *****
*****************/
map<long long, int> contentTally( vector<long long> collection );

/*******************************
***** STRING-BASED NUMBERS *****
*******************************/
//template <typename T>
//std::string float_to_string( const T val, const int n );
//std::string float_to_string( float T val, const int n );
//std::string float_to_string( double T val, const int n );
std::string float_to_string( long double val, const int n );
int addDigits( string input );
/*
class StrInt {
public:
    StrInt();
    StrInt(string input);
    virtual ~StrInt();

    string _get();
    bool _set( string input );
    bool _set( StrInt input );
    int col( int ten_pow );
    int len();
    int max();
    bool pstv();

    StrInt operator+( StrInt lhs, StrInt rhs );
    StrInt operator-( StrInt lhs, StrInt rhs );
    StrInt operator*( StrInt lhs, StrInt rhs );
    StrInt operator/( StrInt lhs, StrInt rhs );
    StrInt operator%( StrInt lhs, StrInt rhs );
    bool operator==( StrInt lhs, StrInt rhs );
    bool operator>=( StrInt lhs, StrInt rhs );
    bool operator<=( StrInt lhs, StrInt rhs );
    bool operator>( StrInt lhs, StrInt rhs );
    bool operator<( StrInt lhs, StrInt rhs );

    StrInt factorial();

protected:

private:
    const int BLOCK_MAX = 18;
    string val;
    int len;
};
*/


}; /* namespace EulerUtils */


#endif /* EULERUTILS_HPP_ */
