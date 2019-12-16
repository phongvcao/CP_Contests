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
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n;
    }

    vector<Int> firstSet;
    vector<Int> secondSet;
    vector<Int> thirdSet;
    Int intVectorIdx = 0;
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (intVectorIdx < n) {
            Int curNum = 0;
            bool isExcluded = false;

            ss >> curNum;

            if ((curNum < 0) && (firstSet.empty())) {
                firstSet.push_back(curNum);
                isExcluded = true;
            }

            if ((curNum > 0) && (secondSet.empty())) {
                secondSet.push_back(curNum);
                isExcluded = true;
            }

            if (!isExcluded) {
                thirdSet.push_back(curNum);
            }

            ++intVectorIdx;
            if (intVectorIdx == n) break;
        }
    }

    if (secondSet.empty()) {
        for (Int i = 0; i < thirdSet.size(); ++i) {
            if (thirdSet[i] < 0) {
                secondSet.push_back(thirdSet[i]);
                thirdSet.erase(thirdSet.begin() + i);
                --i;
            }

            if (secondSet.size() == 2) break;
        }
    }

    cout << firstSet.size() << " " << firstSet[0] << endl;

    cout << secondSet.size() << " ";
    for (Int i = 0; i != secondSet.size(); ++i) {
        cout << secondSet[i];

        if (i < secondSet.size() - 1) {
            cout << " ";
        }

        else {
            cout << endl;
        }
    }

    cout << thirdSet.size() << " ";
    for (Int i = 0; i != thirdSet.size(); ++i) {
        cout << thirdSet[i];

        if (i < thirdSet.size() - 1) {
            cout << " ";
        }
    }


    return 0;
}
