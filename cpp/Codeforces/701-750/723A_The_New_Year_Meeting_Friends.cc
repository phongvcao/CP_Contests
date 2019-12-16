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

int main(int argc, char **argv) {
    vector< UInt > xVector;

    for ( int i = 0; i < 3; ++i ) {
        UInt x = 0;
        cin >> x;
        xVector.push_back( x );
    }

    UInt min = xVector[ 0 ];
    UInt max = xVector[ 0 ];
    for ( int i = 0; i < xVector.size(); ++i ) {
        if ( xVector[ i ] < min ) {
            min = xVector[ i ];
        }

        if ( xVector[ i ] > max ) {
            max = xVector[ i ];
        }
    }

    cout << max - min;

    return 0;
}
