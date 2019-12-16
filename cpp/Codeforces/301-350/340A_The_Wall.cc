#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include <cmath>


using namespace std;
typedef int64_t Int;
typedef uint64_t UInt;


UInt gcd(UInt a, UInt b) {
    if (b == 0) return a;

    return gcd(b, a % b);
}


UInt gcd2(UInt a, UInt b) {
    while (b != 0) {
        UInt oldB = b;
        b = a % b;
        a = oldB;
    }

    return a;
}


void testGCDs() {
    cout << gcd(12, 16) << endl;
    cout << gcd2(12, 16) << endl;
    cout << gcd(15, 27) << endl;
    cout << gcd2(15, 27) << endl;
}


int main(int argc, char **argv) {
    // testGCDs();

    UInt x = 0;
    UInt y = 0;
    UInt a = 0;
    UInt b = 0;
    cin >> x >> y >> a >> b;

    UInt divisor = x * y / gcd2(x, y);
    UInt start = a / divisor;
    UInt end = b / divisor;

    if (a % divisor != 0) {
        ++start;
    }

    cout << end - start + 1;

    // UInt redBrickFirst = a / x;
    // UInt redBrickLast = b / x;
    // UInt pinkBrickFirst = a / y;
    // UInt pinkBrickLast = b / y;
    //
    // if (redBrickFirst * x < a) {
    //     redBrickFirst += 1;
    // }
    //
    // if (pinkBrickFirst * y < a) {
    //     pinkBrickFirst += 1;
    // }
    //
    // unordered_map<Int, bool> redMap;
    //
    // while (redBrickFirst <= redBrickLast) {
    //     redMap.insert(make_pair(redBrickFirst * x, true));
    //     redBrickFirst += 1;
    // }
    //
    // UInt commonCount = 0;
    // while (pinkBrickFirst <= pinkBrickLast) {
    //     unordered_map<Int, bool>::iterator iter = redMap.find(pinkBrickFirst * y);
    //
    //     if (iter != redMap.end()) {
    //         ++commonCount;
    //     }
    //
    //     pinkBrickFirst += 1;
    // }
    //
    // cout << commonCount;
    //

    return 0;
}
