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

    Int n = 0;
    string line = "";
    if ( getline( cin, line ) ) {
        stringstream ss( line );

        ss >> n;

        if ( getline( cin, line ) ) {
            stringstream ss( line );
            Int intArr[ n ];

            for ( Int i = 0; i < n; ++i ) {
                ss >> intArr[ i ];
            }

            for ( Int i = 0; i < n; ++i ) {
                if ( i == 0 ) {
                    cout << intArr[ i + 1 ] - intArr[ i ] << " " 
                        << intArr[ n - 1 ] - intArr[ i ];
                }

                else if ( i == n - 1 ) {
                    cout << intArr[ i ] - intArr[ i - 1 ] << " "
                        << intArr[ i ] - intArr[ 0 ];
                }

                else {
                    Int oneLeft = intArr[ i ] - intArr[ i - 1 ];
                    Int oneRight = intArr[ i + 1 ] - intArr[ i ];

                    if ( oneLeft < oneRight ) {
                        cout << oneLeft;
                    }

                    else {
                        cout << oneRight;
                    }

                    cout << " ";
    
                    Int farLeft = intArr[ i ] - intArr[ 0 ];
                    Int farRight = intArr[ n - 1 ] - intArr[ i ];

                    if ( farLeft > farRight ) {
                        cout << farLeft;
                    }

                    else {
                        cout << farRight;
                    }
                }

                cout << endl;
            }
        }
    }


    return 0;
}
