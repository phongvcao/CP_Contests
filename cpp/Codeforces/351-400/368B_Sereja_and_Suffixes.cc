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
    bool isAppeared[100001];
    for (UInt i = 0; i != 100001; ++i) {
        isAppeared[i] = false;
    }

    UInt n = 0;
    UInt m = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n >> m;
    }

    UInt aArr[n];
    UInt aCountArr[n];
    UInt aArrIdx = 0;
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (aArrIdx < n) {
            ss >> aArr[aArrIdx];
            aCountArr[aArrIdx] = 0;
            ++aArrIdx;
        }
    }

    UInt lArr[m];
    UInt lArrIdx = 0;
    // Read the third line
    while (getline(cin, line)) {
        stringstream ss(line);

        ss >> lArr[lArrIdx++];

        if (lArrIdx == m) break;
    }

    // Logic starts here
    isAppeared[aArr[n - 1]] = true;
    aCountArr[n - 1] = 1;

    if (n > 1) {
        for (Int i = n - 2; i >= 0; --i) {
            if (!isAppeared[aArr[i]]) {
                isAppeared[aArr[i]] = true;
                aCountArr[i] = aCountArr[i + 1] + 1;
            }

            else {
                aCountArr[i] = aCountArr[i + 1];
            }
        }
    }

    for (Int i = 0; i != m; ++i) {
        cout << aCountArr[lArr[i] - 1];

        if (i < m - 1) {
            cout << endl;
        }
    }

    return 0;
}
