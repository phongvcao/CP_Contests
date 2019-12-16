#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include <cstdlib>


using namespace std;
typedef int64_t Int;
typedef uint64_t UInt;


UInt gcd(UInt a, UInt b) {
    while ((a != 0) && (b != 0)) {
        UInt c = b;
        b = a % b;
        a = c;
    }

    return a + b;
}


UInt gcdRecursive(UInt a, UInt b) {
    if ((a == 0) || (b == 0)) return a + b;

    return gcdRecursive(b, a % b);
}


int main(int argc, char **argv) {
    UInt l = 0;
    UInt r = 0;

    cin >> l >> r;

    if (r - l >= 2) {
        for (UInt i = l; i < r - 1; ++i) {
            for (UInt j = l + 2; j < r + 1; ++j) {
                if (gcd(i,j) != 1) {
                    for (UInt k = i + 1; k < j; ++k) {
                        if ((gcd(k, i) == 1) && (gcd(k, j) == 1)) {
                            cout << i << " " << k << " " << j;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << -1;

    return 0;
}
