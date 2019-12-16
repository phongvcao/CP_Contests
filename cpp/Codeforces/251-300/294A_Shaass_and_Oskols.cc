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


int main(int argc, char **argv) {
    UInt n = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n;
    }

    UInt wireArr[n];
    UInt wireArrIdx = 0;
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (wireArrIdx < n) {
            ss >> wireArr[wireArrIdx++];
        }
    }

    UInt m = 0;
    // Read the third line
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> m;
    }

    UInt lineIdx = 0;
    UInt toUpperWire = 0;
    UInt toLowerWire = 0;
    // Read the next m linea
    while (getline(cin, line)) {
        stringstream ss(line);

        UInt wireIdx = 0;
        UInt birdIdx = 0;

        ss >> wireIdx >> birdIdx;
        --wireIdx;
        --birdIdx;

        // If this is the top wire
        // The birds on the right side move to wireIdx + 1
        if (wireIdx == 0) {
            // If this is the only wire
            if (n == 1) {
                wireArr[wireIdx] = 0;
            }

            // ElseIf this is not the only wire
            else {
                wireArr[wireIdx + 1] += wireArr[wireIdx] - birdIdx - 1;
                wireArr[wireIdx] = 0;
            }
        }

        // ElseIf this is the bottom wire
        else if (wireIdx == n - 1) {
            wireArr[wireIdx - 1] += birdIdx;
            wireArr[wireIdx] = 0;
        }

        // ElseIf this is an in-between wire
        else {
            wireArr[wireIdx - 1] += birdIdx;
            wireArr[wireIdx + 1] += wireArr[wireIdx] - birdIdx - 1;
            wireArr[wireIdx] = 0;
        }

        ++lineIdx;
        if (lineIdx == m) break;
    }

    for (Int i = 0; i != n; ++i) {
        cout << wireArr[i];

        if (i < n - 1) {
            cout << endl;
        }
    }

    return 0;
}
