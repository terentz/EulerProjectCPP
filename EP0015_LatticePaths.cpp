/*
 * EPxxxx_EulerTemplate.cpp
 *
 *  Created on: 13/12/2013
 *      Author: terentz
 */

#include "EP0015_LatticePaths.hpp"
#include "EulerUtils.hpp"
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>
#include "Prime.hpp"
#include <cmath>

using std::cout;
using std::endl;
using EulerUtils::factorial;
using EulerUtils::nPr;
using std::pow;
using EulerUtils::even;
using boost::multiprecision::int256_t;

/* local defines */
#define SZ 20

/* functions */

void LatticePaths::run () {

    cout << "The grid is set to " << SZ << "x" << SZ
         << ", the paths run from top left to bottom right, with no returns." << endl;

	/* test */
	//cout << "factorial 5 = " << factorial(5) << endl;


	/* local declarations */
	unsigned long long sz = SZ,
              n = 2 * sz,
              d = (int)(sz / 2),
              num,
              den,
              res;

	/* do the work! */
    den = factorial(d);
    num = 1;
    for (  ; n > 0 ; --n ) {
        if ( even( (long long)n ) ) {
            num = num * 2;
        } else {
            num = num * n;
        }
    }
    res = num / den;



//	long long p = nPr(n,r);
//	int256_t res = p / factorial(r);
//    unsigned long long num;
//    unsigned long long den;
//    unsigned long long res;
//    unsigned long long sz = SZ;




//    num = factorial( sz * 2 );
//    cout << "num = " << num << endl;
//    cout << "fact(10) = " << factorial(10);
//    den = factorial( sz ) * factorial( sz );
//    cout << "den = " << den << endl;
//    res = num / den;

	/* display results */
	cout << "The result is " << res << endl;
	cout << endl;

}


