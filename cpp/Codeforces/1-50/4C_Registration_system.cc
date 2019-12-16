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


string intToString(UInt n) {
    stringstream ss;

    ss << n;

    return ss.str();
}


int main(int argc, char **argv) {
    UInt n = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n;
    }

    unordered_map<string, UInt> nameMap;
    vector<string> outputVector;
    UInt lineIdx = 0;
    // Read the next n lines
    while (getline(cin, line)) {
        unordered_map<string, UInt>::iterator iter = nameMap.find(line);

        if (iter != nameMap.end()) {
            ++iter->second;
            outputVector.push_back(line + intToString(iter->second));
        }

        else {
            nameMap.insert(make_pair(line, 0));
            outputVector.push_back("OK");
        }

        ++lineIdx;
        if (lineIdx == n) break;
    }

    for (UInt i = 0; i != outputVector.size(); ++i) {
        cout << outputVector[i];

        if (i < outputVector.size() - 1) {
            cout << endl;
        }
    }

    return 0;
}
