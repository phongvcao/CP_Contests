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
    string numStr = "";

    cin >> numStr;
    Int lastDigit = numStr[numStr.length() - 1] - '0';

    Int minEvenDigitIdx = -1;
    for (Int i = 0; i != numStr.length() - 1; ++i) {
        if (numStr[i] % 2 == 0) {
            if (numStr[i] - '0' < lastDigit) {
                char temp = numStr[i];
                numStr[i] = lastDigit + '0';
                numStr[numStr.length() - 1] = temp;
                cout << numStr;
                return 0;
            }

            else {
                minEvenDigitIdx = i;
            }
        }
    }

    if (minEvenDigitIdx != -1) {
        char temp = numStr[minEvenDigitIdx];
        numStr[minEvenDigitIdx] = lastDigit + '0';
        numStr[numStr.length() - 1] = temp;
        cout << numStr;
    }

    else {
        cout << -1;
    }

    return 0;
}
