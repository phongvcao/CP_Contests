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

    if ( n % 2 == 1 ) {
        cout << ( n - 1 ) / 2 << endl;
        for ( int i = 0; i < ( n - 1 ) / 2; ++i ) {
            if ( i == ( n - 1 ) / 2 - 1 ) {
                cout << 3;
            } else {
                cout << 2 << " ";
            }
        }
    } else {
        cout << n / 2 << endl;
        
        for ( int i = 0; i < n / 2; ++i ) {
            if ( i == n / 2 - 1 ) {
                cout << 2;
            } else {
                cout << 2 << " ";
            }
        }
    }

    return 0;
}
