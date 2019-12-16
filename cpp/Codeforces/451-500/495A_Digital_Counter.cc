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

    UInt goodDigits[10] = { 2, 7, 2, 3, 3, 4, 2, 5, 1, 2 };

    UInt goodNumCount = 1;
    for (UInt i = 0; i != numStr.length(); ++i) {
        goodNumCount *= goodDigits[numStr[i] - '0'];
    }

    cout << goodNumCount;

    return 0;
}
