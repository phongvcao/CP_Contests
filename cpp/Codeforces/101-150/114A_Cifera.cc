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


Int getPow(UInt base, UInt value) {
    Int pow = 0;

    while (value > 1) {
        if (value % base == 0) {
            ++pow;
            value /= base;
        }

        else {
            pow = -1;
            break;
        }
    }

    return pow;
}


int main(int argc, char **argv) {
    UInt k = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> k;
    }

    UInt l = 0;
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> l;
    }

    Int pow = getPow(k, l);

    if (pow != -1) {
        cout << "YES" << endl;
        cout << pow - 1;
    }

    else {
        cout << "NO";
    }

    return 0;
}
