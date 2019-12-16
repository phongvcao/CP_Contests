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
    Int m = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n >> m;
    }

    Int buttonsArr[n];
    Int buttonsArrIdx = 0;
    for (Int i = 0; i != n; ++i) {
        buttonsArr[i] = 0;
    }
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (buttonsArrIdx < n) {
            Int curNum = 0;

            ss >> curNum;

            for (Int i = curNum - 1; i != n; ++i) {
                if (buttonsArr[i] == 0) {
                    buttonsArr[i] = curNum;
                }
            }

            ++buttonsArrIdx;
        }
    }

    for (Int i = 0; i != n; ++i) {
        cout << buttonsArr[i];

        if (i < n - 1) {
            cout << " ";
        }
    }


    return 0;
}
