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

    UInt x = 0;

    cin >> x;

    UInt minMoves = x / 5;

    if ( x % 5 > 0 ) {
        ++minMoves;
    }

    cout << minMoves;

    return 0;
}
