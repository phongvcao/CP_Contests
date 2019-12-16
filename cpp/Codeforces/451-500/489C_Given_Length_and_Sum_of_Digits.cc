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
    UInt m = 0;
    UInt s = 0;

    cin >> m;
    cin >> s;

    if ( s == 0 ) {
        if ( m == 1 ) {
            cout << 0 << " " << 0;
        } else {
            cout << -1 << " " << -1;
        }
    } else {

        UInt minNumArr[ m ];
        UInt maxNumArr[ m ];
        fill_n( minNumArr, m, 0 );
        fill_n( maxNumArr, m, 0 );
        minNumArr[ 0 ] = 1;
        maxNumArr[ 0 ] = 1;
        UInt s1 = s;
        UInt s2 = s;
        --s1;
        --s2;

        // Find min
        for ( int i = m - 1; i >= 0; --i ) {
            if ( s1 <= 0 ) {
                break;
            }

            while ( ( s1 > 0 ) && ( minNumArr[ i ] < 9 ) ) {
                ++minNumArr[ i ];
                --s1;
            }
        }

        // Find max
        for ( int i = 0; i < m; ++i ) {
            if ( s2 <= 0 ) {
                break;
            }

            while ( ( s2 > 0 ) && ( maxNumArr[ i ] < 9 ) ) {
                ++maxNumArr[ i ];
                --s2;
            }
        }

        // Print out
        if ( s1 == 0 ) {
            for ( int i = 0; i < m; ++i ) {
                cout << minNumArr[ i ];
            }
        } else {
            cout << -1;
        }

        cout << " ";

        if ( s2 == 0 ) {
            for ( int i = 0; i < m; ++i ) {
                cout << maxNumArr[ i ];
            }
        } else {
            cout << -1;
        }
    }
}
