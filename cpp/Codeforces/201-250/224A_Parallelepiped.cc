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


Int gcd(Int a, Int b) {
    while (b > 0) {
        Int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}


int main(int argc, char **argv) {
    Int area1 = 0;
    Int area2 = 0;
    Int area3 = 0;
    // Read the first line
    cin >> area1 >> area2 >> area3;

    Int a = 0;
    Int b = 0;
    Int c = 0;

    if (area1 == area2) {
        a = gcd(area1, area3);
        b = area1 / a;
        c = area3 / a;
    }

    else if (area2 == area3) {
        a = gcd(area1, area2);
        b = area1 / a;
        c = area2 / a;
    }

    else if (area1 == area3) {
        a = gcd(area1, area2);
        b = area1 / a;
        c = area2 / a;
    }

    else {
        a = gcd(area1, area2);
        b = area1 / a;
        c = area2 / a;
    }

    cout << (a + b + c) * 4;

    return 0;
}
