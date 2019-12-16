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
    UInt n = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n;
    }

    UInt upperArr[n];
    UInt lowerArr[n];
    UInt upperSum = 0;
    UInt lowerSum = 0;
    UInt upperLowerArrIdx = 0;
    // Read the next n lines
    while (getline(cin, line)) {
        stringstream ss(line);

        ss >> upperArr[upperLowerArrIdx] >> lowerArr[upperLowerArrIdx];
        upperSum += upperArr[upperLowerArrIdx];
        lowerSum += lowerArr[upperLowerArrIdx];
        ++upperLowerArrIdx;

        if (upperLowerArrIdx == n) break;
    }

    // Logic starts here
    if (((upperSum % 2) + (lowerSum % 2)) % 2 != 0) {
        cout << -1;
    }

    else {
        if (upperSum % 2 != 0) {
            // If both upperSum and lowerSum are odds
            // Swap an even and an odd between these 2
            // If there is no pairs of odd and even simply output -1
            for (UInt i = 0; i != n; ++i) {
                if (((upperArr[i] % 2) + (lowerArr[i] % 2)) % 2 != 0) {
                    cout << 1;
                    return 0;
                }
            }

            cout << -1;
        }

        else {
            cout << 0;
        }
    }


    return 0;
}
