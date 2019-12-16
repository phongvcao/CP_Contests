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


int main(int argc, char **argv) {
    UInt n = 0;
    UInt t = 0;
    UInt c = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n >> t >> c;
    }

    UInt firstNum = 0;
    UInt intArrIdx = 0;
    vector<UInt> exceedIdxVector;
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (intArrIdx < n) {
            UInt num = 0;
            ss >> num;

            if (intArrIdx == 0) {
                firstNum = num;
            }

            if (num > t) {
                exceedIdxVector.push_back(intArrIdx);
            }

            ++intArrIdx;
        }
    }

    UInt waysCount = 0;
    if (firstNum <= t) {
        exceedIdxVector.insert(exceedIdxVector.begin(), -1);
    }
    exceedIdxVector.push_back(n);

    // Logic starts here
    for (UInt i = 0; i != exceedIdxVector.size() - 1; ++i) {
        UInt dist = exceedIdxVector[i + 1] - exceedIdxVector[i] - 1;
        if (dist >= c) {
            waysCount += dist - c + 1;
        }
    }


    cout << waysCount;

    return 0;
}
