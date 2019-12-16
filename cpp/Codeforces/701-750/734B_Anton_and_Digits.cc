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
    UInt k2 = 0, k3 = 0, k5 = 0, k6 = 0;

    cin  >> k2 >> k3 >> k5 >> k6;

    UInt min = k2;

    if ( min > k2 ) {
        min = k2;
    }

    if ( min > k5 ) {
        min = k5;
    }

    if ( min > k6 ) {
        min = k6;
    }

    k2 -= min;
    k5 -= min;
    k6 -= min;

    UInt count256 = min;
    UInt count32 = k2 < k3 ? k2 : k3;

    cout << ( 256 * count256 + 32 * count32 );

    return 0;
}
