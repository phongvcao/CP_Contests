#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>


using namespace std;
typedef int64_t Int;


int main(int argc, char **argv) {
    string numStr = "";
    cin >> numStr;

    Int firstZeroIdx = -1;
    for (Int i = 0; i != numStr.length(); ++i) {
        if (numStr[i] == '0') {
            firstZeroIdx = i;
            break;
        }
    }

    if (firstZeroIdx != -1) {
        cout << numStr.substr(0, firstZeroIdx) << numStr.substr(firstZeroIdx + 1, numStr.length());
    }

    else {
        cout << numStr.substr(1, numStr.length());
    }

    return 0;
}
