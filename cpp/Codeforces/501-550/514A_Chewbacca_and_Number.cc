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

    if ( getline( cin, line ) ) {
        int intArr[ line.size() ];
        for ( int i = 0; i < line.size(); ++i ) {
            if ( line[ i ] - '0' > 4 ) {
                if ( ( i == 0 ) && ( '9' - line[ i ] == 0 ) ) {
                    intArr[ i ] = line[ i ] - '0';
                } else {
                    intArr[ i ] = '9' - line[ i ];
                }
            } else {
                intArr[ i ] = line[ i ] - '0';
            }
        }

        for ( int i = 0; i < line.size(); ++i ) {
            cout << intArr[ i ];
        }
    }

    return 0;
}
