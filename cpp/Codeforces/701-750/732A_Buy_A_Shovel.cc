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
    UInt k = 0;
    UInt r = 0;

    cin >> k;
    cin >> r;

    for ( int i = 1 ; i < 11; ++i ) {
        if ( ( ( i * k ) % 10 == 0 ) || ( ( i * k ) % 10 == r ) ) {
            cout << i;
            break;
        }
    }

    return 0;
}
