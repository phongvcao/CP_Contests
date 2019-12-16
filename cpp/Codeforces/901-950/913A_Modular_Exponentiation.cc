#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include <cmath>
#include <algorithm>


using namespace std;
typedef int64_t Int;
typedef uint64_t UInt;


Int largestExp( Int n ) {
    double x = (double)n;
    Int expo = 0;

    while ( x > 1 ) {
        x = x / 2;
        ++expo;
    }

    return expo;
}


int main(int argc, char **argv) {
    string line = "";
    Int n = 0;
    Int m = 0;

    if ( getline( cin, line ) ) {
        stringstream ss( line );

        ss >> n;
    }

    if ( getline( cin, line ) ) {
        stringstream ss( line );

        ss >> m;
    }

    Int expo = largestExp( m );

    // // DEBUG
    // cout << "DEBUG: expo: " << expo << endl;
    // cout << "DEBUG: expo - 1: " << expo - 1 << endl;
    // cout << "DEBUG: n: " << n << endl;
    // // END OF DEBUG

    if ( n >= expo - 1 ) {
        // // DEBUG
        // cout << "DEBUG: FIRST IF" << endl;
        // // END OF DEBUG
        cout << m % (Int)( pow( 2, n ) );
    } else {
        // // DEBUG
        // cout << "DEBUG: FIRST ELSE" << endl;
        // // END OF DEBUG
        cout << (Int)( m - pow( 2, expo - 1 ) ) % (Int)( pow( 2, n ) );
        // cout << (Int)( m - pow( 2, 5 ) ) % (Int)( pow( 2, n ) );
    }

    // // DEBUG
    // cout << "DEBUG: largestExpo of 5: " << largestExp( 5 ) << endl;
    // cout << "DEBUG: largestExpo of 17: " << largestExp( 17 ) << endl;
    // cout << "DEBUG: pow() of base 2, exp 5: " << pow( 2, 5 ) << endl;
    // cout << "DEBUG: pow() of base 2, exp 3: " << pow( 2, 3 ) << endl;
    // // END OF DEBUG

    return 0;
}
