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

    UInt n = 0, m = 1;
    cin >> n;

    UInt intArr[ n ][ n ];
    intArr[ 0 ][ 0 ] = 1;

    for ( UInt i = 0; i < n; ++i ) {
        for ( UInt j = 0; j < n; ++j ) {
            if ( ( i == 0 ) || ( j == 0 ) ) {
                intArr[ i ][ j ] = 1;
            }

            else {
                intArr[ i ][ j ] = 0;
            }

        }
    }

    for ( UInt i = 1; i < n; ++i ) {
        for ( UInt j = 1; j < n; ++j ) {
            intArr[ i ][ j ] = intArr[ i ][ j - 1 ] + intArr[ i - 1 ][ j ];

            if ( intArr[ i ][ j ] > m ) {
                m = intArr[ i ][ j ];
            }
        }
    }

    cout << m;

    return 0;
}
