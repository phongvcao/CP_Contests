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
    string s = "";
    vector<UInt> cCountVector;
    cCountVector.push_back(0);
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        s = line;

        for (UInt i = 1; i != s.length(); ++i) {
            if (s[i] == s[i - 1]) {
                cCountVector.push_back(cCountVector[i - 1] + 1);
            }

            else {
                cCountVector.push_back(cCountVector[i - 1]);
            }
        }
    }

    UInt m = 0;
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> m;
    }

    UInt resultArr[m];
    UInt lineIdx = 0;
    // Read the next m lines
    while (getline(cin, line)) {
        UInt l = 0;
        UInt r = 0;
        stringstream ss(line);
        ss >> l >> r;

        resultArr[lineIdx] = cCountVector[r - 1] - cCountVector[l - 1];

        ++lineIdx;
        if (lineIdx == m) break;
    }

    for (UInt i = 0; i != m; ++i) {
        cout << resultArr[i];

        if (i < m - 1) {
            cout << endl;
        }
    }


    return 0;
}
