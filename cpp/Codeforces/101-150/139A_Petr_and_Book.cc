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
    Int n = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n;
    }

    Int intArr[7];
    Int intArrIdx = 0;
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (intArrIdx < 7) {
            ss >> intArr[intArrIdx++];
        }
    }

    // Logic starts here
    Int curArrIdx = 0;
    while (n > 0) {
        n -= intArr[curArrIdx % 7];
        ++curArrIdx;
    }

    cout << (curArrIdx - 1) % 7 + 1;

    return 0;
}
