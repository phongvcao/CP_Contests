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

    UInt intArr[n];
    UInt intArrIdx = 0;
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (intArrIdx < n) {
            ss >> intArr[intArrIdx++];
        }
    }

    // Logic starts here
    Int orgMaxDist = -1;
    for (UInt i = 0; i < n - 1; ++i) {
        if (orgMaxDist == -1) {
            orgMaxDist = intArr[i + 1] - intArr[i];
        }

        else if (intArr[i + 1] - intArr[i] > orgMaxDist) {
            orgMaxDist = intArr[i + 1] - intArr[i];
        }
    }

    Int minDist = -1;
    for (UInt i = 0; i < n - 2; ++i) {
        if (minDist == -1) {
            minDist = intArr[i + 2] - intArr[i];
        }

        else if (intArr[i + 2] - intArr[i] < minDist) {
            minDist = intArr[i + 2] - intArr[i];
        }
    }

    cout << ((minDist > orgMaxDist) ? minDist : orgMaxDist);


    return 0;
}
