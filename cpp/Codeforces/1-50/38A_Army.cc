#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>


using namespace std;
typedef int64_t Int;
typedef uint64_t UInt;


int main(int argc, char **argv) {
    Int n = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n;
    }

    Int yearsArr[n];
    Int yearsArrIdx = 1;
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (yearsArrIdx < n) {
            ss >> yearsArr[yearsArrIdx++];
        }
    }

    Int a = 0;
    Int b = 0;
    // Read the third line
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> a >> b;
    }

    Int yearsCount = 0;
    // Logic starts here
    for (Int i = a; i < b; ++i) {
        yearsCount += yearsArr[i];
    }

    cout << yearsCount;


    return 0;
}
