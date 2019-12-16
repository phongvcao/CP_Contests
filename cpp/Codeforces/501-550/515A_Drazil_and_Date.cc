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
    Int a = 0, b = 0, s = 0;

    cin >> a >> b >> s;

    if ( absValue( a ) + absValue( b ) > s ) {
        cout << "No";
    } else {
        if ( ( s - absValue( a ) - absValue( b ) ) % 2 == 0 ) {
            cout << "Yes";
        } else {
            cout << "No";
        }
    }

    return 0;
}
