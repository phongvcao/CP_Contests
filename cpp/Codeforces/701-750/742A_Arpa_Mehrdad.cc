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
    UInt n = 0;
    cin >> n;

    if ( n == 0 ) {
        cout << 1;
    } else {
        if ( n % 4 == 1 ) {
            cout << 8;
        } else if ( n % 4 == 2 ) {
            cout << 4;
        } else if ( n % 4 == 3 ) {
            cout << 2;
        } else if ( n % 4 == 0 ) {
            cout << 6;
        }
    }

    return 0;
}
