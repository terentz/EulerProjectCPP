/*
 * EulerUtils.cpp
 *
 *  Created on: 13/12/2013
 *      Author: terentz
 */



#include "EulerUtils.hpp"
//#include "Prime.hpp"
#include <sys/time.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>
#include <fstream>
#include <istream>

//#include <array>

//using namespace std;
using std::endl;
using std::cout;
using boost::lexical_cast;
using boost::bad_lexical_cast;
using std::string;
using std::vector;
using std::ifstream;
using std::fstream;
//using Prime::isPrime;


/* divisor for timer conversion */
//#define SECS_DIVISOR 10000


/********************
** String Splitter **
********************/
EulerUtils::splitstring::splitstring( char *s ) : string( s ) { };
vector<string>& EulerUtils::splitstring::split(char delim, int rep) {
    if (!this->flds.empty()) this->flds.clear();  // empty vector if necessary
    string work = data();
    string buf = "";
    int i = 0;
    while (i < work.length()) {
        if (work[i] != delim)
            buf += work[i];
        else if (rep == 1) {
            flds.push_back(buf);
            buf = "";
        } else if (buf.length() > 0) {
            flds.push_back(buf);
            buf = "";
        }
        i++;
    }
    if (!buf.empty())
        flds.push_back(buf);
    return flds;
}

/********************
** String combiner **
********************/
// TODO create a function that takes a collection of strings and combines them

/******************
** String to Int **
******************/
int EulerUtils::strToInt ( string input ) {
	int output;
	try {
		output = boost::lexical_cast<int>( input );
		return output;
	} catch( boost::bad_lexical_cast const& ) {
	    cout << "Error: " << input << " was not converted to an int!" << endl;
	    return -1;
	}
}


/*********************
** Arrays & Vectors **
*********************/
// TODO can these first two be merged using more templating??
//template<typename T>	// for 1-D vector
void EulerUtils::printVector ( string itemName, const vector<long long>& input ) {
	cout << "in printVector" << endl;
	cout << "Printing " << itemName << "..." << endl;
	for ( auto i = input.begin(); i != input.end(); i++ ) {
        cout << ( i == input.begin() ? "" : ", " ) << *i ;
    }
    cout << endl;
}

template<class TYPE>	// for 1-D array
void EulerUtils::printArray ( string itemName, const TYPE data[] ) {
	int len = sizeof(data) / sizeof(data[0]) ;
	cout << "Printing " << itemName << endl;
	for ( int index=0 ; index<len ; index++ ) {
		cout << ( index == 0 ? "" : ", " ) << data[index] ;
	}
	cout << endl << endl;
}
// TODO can this be made into an extension of the first (1-D) functions
template<class TYPE>	// for 2-D array
void EulerUtils::printGrid ( string itemName, const TYPE data[][20] ) {
	int depth = sizeof(data) / sizeof(data[0]) ;
	int width = sizeof(data[0]) / sizeof(data[0][0]) ;
	cout << "Printing " << itemName << endl;
	for ( int y=0 ; y<depth ; y++ ) {
		for ( int x=0 ; x<width ; x++ ) {
			cout << ( x == 0 ? "" : ", " ) << data[y][x] ;
		}
		cout << endl;
	}
	cout << endl << endl;
}

bool EulerUtils::inVector( vector<long long>& haystack, long long needle ) {
	for ( vector<long long>::iterator iter = haystack.begin() ; iter != haystack.end() ; iter++ )
		if ( *iter == needle ) return true;
	return false;
}

int EulerUtils::countAppearance( vector<long long> haystack, long long needle ) {
    int count = 0;
    for ( auto i = haystack.begin() ; i < haystack.end() ; i++ ) {
        if ( *i == needle ) ++count;
    }
    return count;
}

long long EulerUtils::product( vector<long long> input ) {
    long long result = 1;
    for ( auto i = input.begin() ; i < input.end() ; i++ ) {
        result *= *i;
    }
    return result;
}


/******************
*** FACTORISING ***
******************/
vector<long long> EulerUtils::integerDivisors( long long input ) {
	vector<long long> output;
	for ( long long testFactor = 1 ; testFactor <= input/2 ; testFactor++ ) {
		if ( input % testFactor == 0.0 ) {
			output.push_back(testFactor);
		}
	}
	return output;
}
// TODO update this function (was allFactors()) to vector<long>& EulerUtils::primeFactors( long long input, bool unique )
vector<long long> EulerUtils::primeFactorsSet( long long input ) {
	vector<long long> output;
	for ( long long testFactor = 2 ; testFactor <= input/2 ; testFactor++ ) {
        cout << "input = " << input << " and testFactor = " << testFactor << endl;
		if ( input % testFactor == 0 && EulerUtils::isPrime( testFactor ) ) {
			output.push_back(testFactor);
			cout << testFactor << " added!" << endl;
		}
	}
	if ( isPrime(input) ) output.push_back(input);
	return output;
}

vector<long long> EulerUtils::primeFactorsAll( long long input ) {
    vector<long long> output;
    long long remain = input;
    for ( long long testFactor = 2 ; testFactor <= input/2 ; testFactor++ ) {
        if ( isPrime( testFactor ) ) {
            // If testFactor is a factor, add it to output, calculate remain
            while ( remain % testFactor == 0 ) {
                output.push_back(testFactor);
                remain /= testFactor;
            }
        }
    }
    if ( isPrime(input) ) output.push_back(input);
    return output;
}


long long EulerUtils::gcd( long long a, long long b ) {
    if ( b == 0 )
        return a;
    else
        return gcd(b, a%b);
}


/*****************
** Grid classes **
*****************/

/* class GridArr - a grid made of arrays */
EulerUtils::GridArr::GridArr ( ) {}
EulerUtils::GridArr::GridArr ( string filename ) {
	cout << ( this->populate( filename ) ? "File read successful :)" : "File read failed!" ) << endl;
}
EulerUtils::GridArr::GridArr ( int w , int d ) {
	this->wd = w;
	this->dp = d;
}
EulerUtils::GridArr::GridArr ( string filename, int w, int d ) {
// set depth and width
	this->wd = w;
	this->dp = d;

// init the grids
	initGrids(w,d);

// read the file and populate 'em!
	cout << ( this->populate( filename ) ? "File read successful :)" : "File read failed!" ) << endl;
}
EulerUtils::GridArr::~GridArr() {
	// tidy up inner arrays
	for ( int y = 0 ; y < this->dp ; ++y ) {
		delete [] str_grid[y];
		delete [] int_grid[y];
		str_grid[y] = NULL;
		int_grid[y] = NULL;
	}
	// tidy up outer arrays
	delete [] str_grid;
	delete [] int_grid;
	str_grid = NULL;
	int_grid = NULL;
}
bool EulerUtils::GridArr::populate ( string filename ) {
	// init's
	ifstream file;
	//unsigned int y=0, x=0;
	int y=0, x;
	// open the target file
	file.open(filename.c_str());
	if ( file.good() ) {
		// test line
		cout << "File open success :)" << endl;
		// iterate thru the lines in the file
		while ( ! file.eof() ) {
			// get a line
			string raw_line;
			getline( file , raw_line );
			// test lines
			cout << "Line read" << endl;
			splitstring job( const_cast<char*>(raw_line.c_str()) );
			cout << "splitstring created" << endl;
			// split it
			const vector<string> line_items = job.split(' ');
			cout << "splitstring split" << endl;
			// iterate thru the words
			for ( x=0 ; x<(signed)line_items.size() ; ++x ) {
				// test
				cout << "(x,y) = (" << x << "," << y << ")" << endl;
				str_grid[y][x] = line_items[x];
				int_grid[y][x] = strToInt(str_grid[y][x]);
			}
			y++;
		}
		file.close();
		return true;
	}
	return false;
}
void EulerUtils::GridArr::print ( string name ) {
	cout << "Printing " << name << endl;
	// iterate thru the rows
	for ( int y = 0 ; y < ((signed)sizeof(str_grid) / (signed)sizeof(str_grid[0])) ; ++y )
	{
		cout << endl;
		// iterate thru the cells
		for ( int x = 0 ; x < ((signed)sizeof(str_grid[0]) / (signed)sizeof(str_grid[0][0])) ; ++x )
		{
			// print it out!!
			cout << ( x == 0 ? "" : " ") << str_grid[y][x];
		}
	}
	cout << endl;
}
// init grids
void EulerUtils::GridArr::initGrids( int w , int d ) {
	this->initIntGrid(w,d);
	this->initStrGrid(w,d);
}
void EulerUtils::GridArr::initIntGrid( int w , int d ) {
	this->int_grid = new int* [d];
	for ( int y=0; y<d ; y++ ) {
		int_grid[y] = new int[w];
	}
}
void EulerUtils::GridArr::initStrGrid( int w , int d ) {
	this->str_grid = new string* [d];
	for ( int y=0; y<d ; y++ ) {
		str_grid[y] = new string[w];
	}
}
// get grids
/*  FIRST ATTEMPTS
const string ** EulerUtils::GridArr::getStrGrid() {
	return const_cast<string**>(this->str_grid);
}
const int ** EulerUtils::GridArr::getIntGrid() {
	// TODO check this after next build
	const int ** out = const_cast<int**>(this->int_grid);
	return out;
//return const_cast<int**>(this->int_grid);
}
*/
string ** EulerUtils::GridArr::getStrGrid() {
	return this->str_grid;
}
int ** EulerUtils::GridArr::getIntGrid() {
	// TODO check this after next build
	return this->int_grid;
//	return out;
//return const_cast<int**>(this->int_grid);
}


// get dimensions
const int EulerUtils::GridArr::width() {
	//	return const_cast<int>(this->wd);
	const int out = this->wd;
	return out;
}
const int EulerUtils::GridArr::depth() {
	//	return const_cast<int>(this->dp);
	const int out = this->dp;
	return out;
}
// get cell content
const int EulerUtils::GridArr::intCellContent( int x , int y ) {
	//	return const_cast<int>(this->int_grid[y][x]);
	const int out = this->int_grid[y][x];
	return out;
}




/* class GridVec - a grid made of vectors */
EulerUtils::GridVec::GridVec ( ) {}
EulerUtils::GridVec::GridVec ( string filename ) {
	cout << ( this->populate( filename ) ? "File read successful :)" : "File read failed!" ) << endl;
}
EulerUtils::GridVec::GridVec ( string filename, int w, int d )
								: GridVec( filename ) {
	this->wd = w;
	this->dp = d;
	//GridVec( filename );
}
bool EulerUtils::GridVec::populate ( string filename ) {
	// init's
	ifstream file;
	int y=0, x=0;
	// open the target file
	file.open(filename.c_str());
	if ( file.good() ) {
		// iterate thru the lines in the file
		while ( ! file.eof() ) {
			// get a line
			string raw_line;
			getline( file , raw_line );
			// split it
			splitstring job( const_cast<char*>(raw_line.c_str()) );
			const vector<string> lineItems = job.split(' ');
			// iterate thru the words
			for ( x=0 ; x<lineItems.size() ; ++x ) {
				str_grid[y][x] = lineItems[x];
				int_grid[y][x] = strToInt(str_grid[y][x]);
			}
			y++;
		}
		file.close();
		return true;
	}
	return false;
}
void EulerUtils::GridVec::print ( string name ) {
	cout << "Printing " << name << endl;
	// iterate thru the rows
	for ( int y = 0 ; y < str_grid.size() ; ++y )
	{
		cout << endl;
		// iterate thru the cells
		for ( int x = 0 ; x < str_grid[0].size() ; ++x )
		{
			// print it out!!
			cout << ( x == 0 ? "" : " ") << str_grid[y][x];
		}
	}
	cout << endl;
}


/*************************
*** Numbers to strings ***
*************************/

template <class N>
string EulerUtils::numToString( N num ){
    string out = boost::lexical_cast<string>(num);
    return out;
}




/*****************
***** PRIMES *****
*****************/
bool EulerUtils::isPrime( long long input ) {
	for( long long test = floor(sqrt(input)) ; test > 1 ; --test ) {
		if( input % test == 0 && test != 1 )
			return false;
	}
	return true;
}

long long EulerUtils::nextPrime( long long input ){
	long long current = input;
	while (true) {
		if (EulerUtils::isPrime(++current)) {
			return current;
		}
	}
	return 0;
}

long long EulerUtils::nthPrime( long long n ) {
	long long current, count;
	for ( current = 2, count = 0 ; count < n ; current++ ) {
		if ( EulerUtils::isPrime( current ) ) {
			// test
			//cout << current << " is prime!" << endl;
			count ++;
			// test
			//cout << " number " << count << endl;
		}
	}
	return --current;

}

inline unsigned long long factorial( unsigned long long x ) {
  return ( x == 1 ? x : x * factorial( x - 1 ) );
};

long long EulerUtils::primesFactorial( long long n ) {
    if ( n == 2 ) return n;
    else {
        if ( EulerUtils::isPrime( n ) )
            return primesFactorial( n-1 ) * n;
        else
            return primesFactorial( n-1 );
    }
}








