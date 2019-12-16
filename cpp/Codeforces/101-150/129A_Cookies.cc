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
    UInt n = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n;
    }

    UInt intArr[n];
    UInt intArrIdx = 0;
    UInt evenCount = 0;
    UInt oddCount = 0;
    UInt sum = 0;
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (intArrIdx < n) {
            ss >> intArr[intArrIdx++];

            if (intArr[intArrIdx - 1] % 2 == 0) {
                ++evenCount;
            }

            else {
                ++oddCount;
            }

            sum += intArr[intArrIdx - 1];
        }
    }

    // Logic starts here
    if (sum % 2 == 0) {
        cout << evenCount;
    }

    else {
        cout << oddCount;
    }


    return 0;
}
