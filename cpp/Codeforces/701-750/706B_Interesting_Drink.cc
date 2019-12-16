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

int main(int argc, char **argv) {
    string line = "";
    UInt n = 0;

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> n;
    }

    UInt intArr[ n ];
    if ( getline( cin, line ) ) {
        stringstream ss( line );
        for ( int i = 0; i < n; ++i ) {
            ss >> intArr[ i ];
        }
    }

    UInt q = 0;
    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> q;
    }

    UInt outArr[ q ];
    fill_n( outArr, q, 0 );
    UInt outArrIdx = 0;
    while ( getline( cin, line ) ) {
        stringstream ss( line );
        UInt curPrice = 0;
        ss >> curPrice;
        for ( int i = 0; i < n; ++i ) {
            if ( curPrice >= intArr[ i ] ) {
                ++outArr[ outArrIdx ];
            }
        }
        ++outArrIdx;

        if ( outArrIdx == q ) {
            break;
        }
    }

    for ( int i = 0; i < q; ++i ) {
        cout << outArr[ i ];
        if ( i < q - 1 ) {
            cout << endl;
        }
    }

    return 0;
}
