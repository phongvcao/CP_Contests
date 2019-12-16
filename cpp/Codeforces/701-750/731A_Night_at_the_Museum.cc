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

Int absValue( Int n ) {
    if ( n < 0 ) {
        return 0 - n;
    }
    return n;
}

int main(int argc, char **argv) {
    string line = "";
    UInt totalRotations = 0;

    if ( getline( cin, line ) ) {
        for ( int i = 0; i < line.size(); ++i ) {
            if ( i == 0 ) {
                if ( 26 - absValue( line[ i ] - 'a' ) < absValue( line[ i ] - 'a' ) ) {
                    totalRotations += 26 - absValue( line[ i ] - 'a' );
                } else {
                    totalRotations += absValue( line[ i ] - 'a' );
                }
            
            } else {
                if ( 26 - absValue( line[ i ] - line[ i - 1 ] ) < absValue( line[ i ] - line[ i - 1 ] ) ) {
                    totalRotations += 26 - absValue( line[ i ] - line[ i - 1 ] );
                } else {
                    totalRotations += absValue( line[ i ] - line[ i - 1 ] );
                }
            }

            // cout << "DEBUG: totalRotations: " << totalRotations << endl;
        }

        cout << totalRotations;
    }

    return 0;
}
