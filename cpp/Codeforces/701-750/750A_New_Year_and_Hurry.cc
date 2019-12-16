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
    UInt k = 0;

    cin >> n;
    cin >> k;

    double sum = ( 240 - k ) / 5;

    double a1 = - ( 0.5 - ( (double)sqrt( 1 + 8 * sum ) ) / 2.0 );
    double a2 = - ( 0.5 + ( (double)sqrt( 1 + 8 * sum ) ) / 2.0 );

    Int a1Int = (Int)a1;
    Int a2Int = (Int)a2;

    if ( a1Int > a2Int ) {
        if ( a1Int > n ) {
            cout << n;
        } else {
            cout << a1Int;
        }
    } else {
        if ( a2Int > n ) {
            cout << n;
        } else {
            cout << a2Int;
        }
    }

    return 0;
}
