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
    Int m = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n >> m;
    }

    Int intArr[n];
    Int intArrIdx = 0;
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (intArrIdx < n) {
            ss >> intArr[intArrIdx++];
        }
    }

    intArrIdx = 0;
    Int busesCount = 0;
    // Logic starts here
    while (intArrIdx < n) {
        Int peopleSoFar = 0;

        for (Int i = intArrIdx; i != n; ++i) {
            peopleSoFar += intArr[i];

            if (peopleSoFar > m) {
                intArrIdx = i;
                ++busesCount;
                break;
            }

            else if (peopleSoFar == m) {
                intArrIdx = i + 1;
                ++busesCount;
                break;
            }

            else {
                if (i == n - 1) {
                    intArrIdx = i + 1;
                    ++busesCount;
                    break;
                }
            }
        }
    }

    cout << busesCount;


    return 0;
}
