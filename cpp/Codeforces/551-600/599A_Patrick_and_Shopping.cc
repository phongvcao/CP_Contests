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
    UInt d1 = 0, d2 = 0, d3 = 0;

    cin >> d1 >> d2 >> d3;

    UInt intArr[ 4 ] = { 2 * ( d1 + d2 ), d1 + d2 + d3, 2 * ( d1 + d3 ), 2 * ( d2 + d3 ) };
    UInt min = intArr[ 0 ];

    for ( int i = 0; i < 4; ++i ) {
        if ( min > intArr[ i ] ) {
            min = intArr[ i ];
        }
    }

    cout << min;

    return 0;
}
