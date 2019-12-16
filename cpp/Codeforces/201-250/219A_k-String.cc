#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include <cstdlib>


using namespace std;
typedef int64_t Int;
typedef uint64_t UInt;


int main(int argc, char **argv) {
    UInt k = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> k;
    }

    UInt charCountArr[26];
    for (UInt i = 0; i != 26; ++i) {
        charCountArr[i] = 0;
    }
    // Read the second line
    if (getline(cin, line)) {
        for (UInt i = 0; i != line.length(); ++i) {
            ++charCountArr[line[i] - 'a'];
        }
    }

    string baseStr = "";
    // Logic starts here
    for (UInt i = 0; i != 26; ++i) {
        if (charCountArr[i] % k != 0) {
            cout << -1;
            return 0;
        }

        else {
            for (UInt j = 0; j != charCountArr[i] / k; ++j) {
                baseStr += 'a' + i;
            }
        }
    }

    for (UInt i = 0; i != k; ++i) {
        cout << baseStr;
    }

    return 0;
}
