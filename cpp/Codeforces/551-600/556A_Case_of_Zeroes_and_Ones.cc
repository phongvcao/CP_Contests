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
    UInt n = 0;
    Int x1 = 0, x2 = 0;
    string line = "";

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> n;
    }

    if ( getline( cin, line ) ) {
        stringstream ss( line );

        UInt zeroCount = 0;
        UInt oneCount = 0;

        for ( int i = 0; i < n; ++i ) {
            if ( line[ i ] == '0' ) {
                ++zeroCount;
            } else {
                ++oneCount;
            }
        }

        if ( zeroCount > oneCount ) {
            cout << zeroCount - oneCount;
        } else  {
            cout << oneCount - zeroCount;
        }
    }

    return 0;
}
