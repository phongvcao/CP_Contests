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

bool isBlackWhite( char c ) {
    if ( ( c == 'W' ) || ( c == 'G' ) || ( c == 'B' ) ) {
        return true;
    }
    return false;
}

int main(int argc, char **argv) {
    UInt n = 0;
    UInt m = 0;
    string line = "";

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> n >> m;
    }

    bool isColor = false;
    for ( int i = 0; i < n; ++i ) {
        if ( getline( cin, line ) ) {
            stringstream ss( line );

            for ( int j = 0; j < m; ++j ) {
                char c;
                ss >> c;
                if ( ! isBlackWhite( c ) ) {
                    isColor = true;
                    break;
                }
            }
            
        }
    }

    if ( isColor ) {
        cout << "#Color";
    } else {
        cout << "#Black&White";
    }

    return 0;
}
