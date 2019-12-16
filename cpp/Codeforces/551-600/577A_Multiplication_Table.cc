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
    UInt n = 0, x = 0;
    cin >> n >> x;

    UInt xDivCount = 0;
    for ( UInt i = 1; i < (UInt)(sqrt( x ) + 1); ++i ) {
        if ( i > n ) break;

        if ( ( x % i == 0 ) && ( x / i <= n ) ) {
            xDivCount += 2;

            if ( i * i == x ) {
                --xDivCount;
            }
        }
    }
    cout << xDivCount;

    return 0;
}
