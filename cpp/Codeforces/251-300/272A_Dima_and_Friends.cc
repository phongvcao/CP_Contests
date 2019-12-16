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
    UInt n = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n;
    }

    UInt sum = 0;
    UInt intArrIdx = 0;
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (intArrIdx < n) {
            UInt curNum = 0;
            ss >> curNum;
            sum += curNum;
            ++intArrIdx;
        }
    }

    UInt waysCount = 0;
    // Logic starts here
    for (UInt i = 1; i != 6; ++i) {
        // Error here
        if ((sum + i) % (n + 1) != 1) {
            ++waysCount;
        }
    }

    cout << waysCount;

    return 0;
}
