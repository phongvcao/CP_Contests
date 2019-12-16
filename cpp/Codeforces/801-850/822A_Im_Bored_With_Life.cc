#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
typedef int64_t Int;
typedef uint64_t UInt;

UInt gcd( UInt a, UInt b ) {
    if ( b == 0 ) {
        return a;
    }

    return gcd( b, a % b );
}

UInt factorial( UInt n ) {
    UInt result = 1;

    for ( int i = 0; i < n; ++i ) {
        result *= ( i + 1 );
    }

    return result;
}

int main(int argc, char **argv) {
    UInt a = 0, b = 0;
    cin >> a >> b;

    if ( a < b ) {
        cout << factorial( a );
    } else {
        cout << factorial( b );
    }


    // // DEBUG
    // cout << "GCD 5, 10: " << gcd( 5, 10 ) << endl;
    // cout << "GCD 15, 10: " << gcd( 15, 10 ) << endl;
    // cout << "GCD 12, 6: " << gcd( 12, 6 ) << endl;
    // cout << "GCD 12, 16: " << gcd( 12, 16 ) << endl;
    // cout << "GCD 33, 22: " << gcd( 33, 22 ) << endl;
    // cout << "GCD 22, 33: " << gcd( 22, 33 ) << endl;
    // // END OF DEBUG

    return 0;
}
