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
    UInt intArr[3][3];
    UInt intArrRowIdx = 0;
    UInt intArrColIdx = 0;
    // Read the first three lines
    string line = "";
    while (getline(cin, line)) {
        stringstream ss(line);

        for (UInt i = 0; i != 3; ++i) {
            ss >> intArr[intArrRowIdx][intArrColIdx++];
            ss >> intArr[intArrRowIdx][intArrColIdx++];
            ss >> intArr[intArrRowIdx][intArrColIdx++];
        }

        ++intArrRowIdx;
        if (intArrRowIdx == 3) break;

        intArrColIdx = 0;
    }

    UInt lightsArr[3][3];
    for (UInt i = 0; i != 3; ++i) {
        for (UInt j = 0; j != 3; ++j) {
            lightsArr[i][j] = 1;
        }
    }

    // Logic starts here
    for (UInt i = 0; i != 3; ++i) {
        for (UInt j = 0; j != 3; ++j) {
            if (intArr[i][j] % 2 != 0) {
                // Toggle left
                if (j > 0) {
                    lightsArr[i][j - 1] = !lightsArr[i][j - 1];
                }

                // Toggle right
                if (j < 2) {
                    lightsArr[i][j + 1] = !lightsArr[i][j + 1];
                }

                // Toggle top
                if (i > 0) {
                    lightsArr[i - 1][j] = !lightsArr[i - 1][j];
                }

                // Toggle bottom
                if (i < 2) {
                    lightsArr[i + 1][j] = !lightsArr[i + 1][j];
                }

                // Toggle itself
                lightsArr[i][j] = !lightsArr[i][j];
            }
        }
    }

    // Write out
    for (UInt i = 0; i != 3; ++i) {
        for (UInt j = 0; j != 3; ++j) {
            cout << lightsArr[i][j];
        }

        if (i < 2) {
            cout << endl;
        }
    }

    return 0;
}
