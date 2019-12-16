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

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        UInt intArr[ n ];

        for ( int i = 0; i < n; ++i ) {
            ss >> intArr[ i ];
        }

        if ( n == 1 ) {
            if ( intArr[ 0 ] == 0 ) {
                cout << "UP";
            } else if ( intArr[ 0 ] == 15 ) {
                cout << "DOWN";
            } else {
                cout << -1;
            }
        } else {
            if ( intArr[ n - 1 ] == 0 ) {
                cout << "UP";
            } else if ( intArr[ n - 1 ] == 15 ) {
                cout << "DOWN";
            } else {
                if ( intArr[ n - 1 ] > intArr[ n - 2 ] ) {
                    cout << "UP";
                } else {
                    cout << "DOWN";
                }
            }
        }
    }

    return 0;
}
