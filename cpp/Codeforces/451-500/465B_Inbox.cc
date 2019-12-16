#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>


using namespace std;
typedef int64_t Int;


int main(int argc, char **argv) {
    Int n = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n;
    }

    Int intArr[n];
    Int intArrIdx = 0;
    Int oneIdxArr[n];
    Int oneIdxArrIdx = 0;

    for (int i = 0; i != n; ++i) {
        oneIdxArr[i] = -1;
    }
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (intArrIdx < n) {
            ss >> intArr[intArrIdx];

            if (intArr[intArrIdx] == 1) {
                oneIdxArr[oneIdxArrIdx++] = intArrIdx;
            }

            ++intArrIdx;
        }
    }

    // Logic starts here
    Int noZeroBetween = 1;
    Int oneZeroBetween = 2;
    Int twoZeroBetween = 2;
    Int stepsCount = 0;

    if (oneIdxArrIdx > 0) {
        ++stepsCount;
    }

    for (Int i = 0; i != n - 1; ++i) {
        if (oneIdxArr[i + 1] == -1) {
            break;
        }

        else {
            if (oneIdxArr[i + 1] - oneIdxArr[i] == 1) {
                stepsCount += noZeroBetween;
            }

            else if (oneIdxArr[i + 1] - oneIdxArr[i] == 2) {
                stepsCount += oneZeroBetween;
            }

            else {
                stepsCount += twoZeroBetween;
            }
        }
    }

    std::cout << stepsCount;

    return 0;
}
