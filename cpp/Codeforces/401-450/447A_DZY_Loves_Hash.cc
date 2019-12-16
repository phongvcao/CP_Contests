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
    UInt p = 0;
    UInt n = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> p >> n;
    }

    unordered_map<Int, Int> intMap;
    UInt lineIdx = 0;
    UInt insertionCount = 0;
    // Read the next n line
    while (getline(cin, line)) {
        stringstream ss(line);

        UInt value = 0;
        ss >> value;
        UInt key = value % p;

        unordered_map<Int, Int>::iterator iter = intMap.find(key);

        if (iter != intMap.end()) {
            break;
        }

        else {
            intMap.insert(make_pair(key, value));
            ++insertionCount;
        }

        ++lineIdx;
        if (lineIdx == n) break;
    }

    if (insertionCount == n)
        cout << -1;
    else
        cout << insertionCount + 1;


    return 0;
}
