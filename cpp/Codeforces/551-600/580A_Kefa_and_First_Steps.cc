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

    string line = "";
    UInt n = 0;
    if (getline(cin, line)) {
        stringstream ss(line);
        ss >> n;
    }

    if (getline(cin, line)) {
        stringstream ss(line);

        UInt maxLength = 1;
        UInt curLength = 1;
        UInt prevNum = 0;
        UInt curNum = 0;

        ss >> prevNum;

        for (UInt i = 1; i < n; ++i) {
            if (i > 1) {
                prevNum = curNum;
            }
            ss >> curNum;
            if (curNum >= prevNum) {
                ++curLength;

                if (curLength > maxLength) {
                    maxLength = curLength;
                }
            }

            else {
                curLength = 1;
            }
        }

        cout << maxLength;
    }

    return 0;
}
