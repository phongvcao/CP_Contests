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
    UInt a = 0;
    UInt b = 0;

    cin >> a;
    cin >> b;

    UInt years = 0;

    while ( a <= b ) {
        a *= 3;
        b *= 2;
        ++years;
    }

    cout << years;

    return 0;
}
