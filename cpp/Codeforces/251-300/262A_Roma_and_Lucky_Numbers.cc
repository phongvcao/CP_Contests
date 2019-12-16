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


bool isNotMoreLuckyDigits(string numStr, UInt n) {
    UInt luckyDigitsCount = 0;

    for (UInt i = 0; i != numStr.length(); ++i) {
        if ((numStr[i] == '4') || (numStr[i] == '7')) {
            ++luckyDigitsCount;

            if (luckyDigitsCount > n) {
                return false;
            }
        }

    }

    return true;
}


int main(int argc, char **argv) {
    UInt n = 0;
    UInt k = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n >> k;
    }

    // vector<string> numVector;
    UInt numVectorIdx = 0;
    UInt notMoreLuckyCount = 0;
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (numVectorIdx < n) {
            UInt curNum = 0;
            ss >> curNum;

            string curNumStr = "";
            stringstream newSS;
            newSS << curNum;

            if (isNotMoreLuckyDigits(newSS.str(), k)) {
                ++notMoreLuckyCount;
            }

            ++numVectorIdx;
        }
    }

    cout << notMoreLuckyCount;


    return 0;
}
