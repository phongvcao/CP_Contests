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
    Int n = 0;
    Int m = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n >> m;
    }

    Int maxCorrect = 0;
    Int minCorrect = 0;
    Int correctNumIdx = 0;
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (correctNumIdx < n) {
            Int curNum = 0;
            ss >> curNum;

            if ((maxCorrect < curNum) || (maxCorrect == 0)) {
                maxCorrect = curNum;
            }

            if ((minCorrect > curNum) || (minCorrect == 0)) {
                minCorrect = curNum;
            }

            ++correctNumIdx;
        }
    }

    Int minIncorrect = 0;
    Int incorrectNumIdx = 0;
    // Read the third line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (incorrectNumIdx < m) {
            Int curNum = 0;
            ss >> curNum;

            if ((minIncorrect > curNum) || (minIncorrect == 0)) {
                minIncorrect = curNum;
            }

            ++incorrectNumIdx;
        }
    }

    // Logic starts here
    Int finalAnswer = 0;
    minCorrect *= 2;

    if (minCorrect < maxCorrect) {
        finalAnswer = maxCorrect;
    }

    else if (minCorrect > maxCorrect) {
        finalAnswer = minCorrect;
    }

    else {
        finalAnswer = minCorrect;
    }

    if (finalAnswer >= minIncorrect) {
        finalAnswer = -1;
    }

    cout << finalAnswer;

    return 0;
}
