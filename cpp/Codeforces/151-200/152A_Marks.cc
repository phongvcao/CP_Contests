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
    UInt m = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n >> m;
    }

    UInt intArr[n][m];
    UInt intArrRowIdx = 0;
    // Read the next n lines
    while (getline(cin, line)) {
        for (UInt i = 0; i != line.length(); ++i) {
            intArr[intArrRowIdx][i] = line[i] - '0';
        }

        ++intArrRowIdx;
        if (intArrRowIdx == n) break;
    }

    // Logic starts here
    bool sucStudentsArr[n];
    for (UInt i = 0; i != n; ++i) {
        sucStudentsArr[i] = false;
    }
    for (UInt i = 0; i != m; ++i) {
        UInt maxOfThisSubject = 0;
        for (UInt j = 0; j != n; ++j) {
            if (intArr[j][i] > maxOfThisSubject) {
                maxOfThisSubject = intArr[j][i];
            }
        }

        for (UInt j = 0; j != n; ++j) {
            if (intArr[j][i] == maxOfThisSubject) {
                sucStudentsArr[j] = true;
            }
        }
    }

    UInt sucStudentsCount = 0;
    for (UInt i = 0; i != n; ++i) {
        if (sucStudentsArr[i]) {
            ++sucStudentsCount;
        }
    }

    cout << sucStudentsCount;

    return 0;
}
