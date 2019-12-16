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
    UInt n = 0;
    string line = "";

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> n;

        Int intArr[ n ];
        fill_n( intArr, n, 0 );

        if ( getline( cin, line ) ) {
            UInt intArrIdx = 0;
            bool stillInBlack = false;
            for ( int i = 0; i < n; ++i ) {
                if ( line[ i ] == 'B' ) {
                    stillInBlack = true;
                } else if ( line[ i ] == 'W' ) {
                    stillInBlack = false;
                }

                if ( stillInBlack ) {
                    if ( ( i >= 1 ) && ( line[ i - 1 ] == 'W' ) ) {
                        ++intArrIdx;
                    }
                    ++intArr[ intArrIdx ];
                }
            }
    
            if ( intArr[ 0 ] == 0 ) {
                cout << intArrIdx << endl;
            } else {
                cout << intArrIdx + 1 << endl;
            }

            for ( int i = 0; i < intArrIdx + 1; ++i ) {
                if ( ( i == 0 ) && ( intArr[ i ] == 0 ) ) {
                    continue;
                }
                cout << intArr[ i ];
                
                if ( i < intArrIdx ) {
                    cout << " ";
                }
            }

            // // DEBUG
            // cout << endl;
            // for ( int i = 0; i < 100; ++i ) {
            //     cout << intArr[ i ] << " ";
            // }
            // cout << endl;
            // // END OF DEBUG
        }
    }

    return 0;
}
