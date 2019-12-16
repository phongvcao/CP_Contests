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


Int intPow(Int a, Int b) {
    Int result = 1;

    for (Int i = 0; i != b; ++i) {
        result *= a;
    }

    return result;
}


int main(int argc, char **argv) {
    Int r = 0;
    Int x0 = 0;
    Int y0 = 0;
    Int x1 = 0;
    Int y1 = 0;

    cin >> r >> x0 >> y0 >> x1 >> y1;

    Int d = 2 * r;
    double dist = sqrt(intPow(y1 - y0, 2) + intPow(x1 - x0, 2));
    Int intDist = (Int)dist;

    if (dist > (Int)dist) {
        intDist += 1;
    }

    Int answer = intDist / d;
    if (intDist % d != 0) {
        ++answer;
    }

    cout << answer;


    return 0;
}
