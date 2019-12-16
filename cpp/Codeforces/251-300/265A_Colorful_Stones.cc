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
    string s = "";
    // Read the first line
    if (getline(cin, s)) {

    }

    string t = "";
    // Read the second line
    if (getline(cin, t)) {

    }

    UInt sIdx = 0;
    // Logic starts here
    for (UInt i = 0; i != t.length(); ++i) {
        if (t[i] == s[sIdx]) {
            ++sIdx;
        }
    }

    cout << sIdx + 1;


    return 0;
}
