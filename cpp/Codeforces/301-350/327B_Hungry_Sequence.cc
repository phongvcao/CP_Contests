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
    cin >> n;

    UInt boolArrSize = 10000001;
    // UInt boolArrSize = 1001;
    bool boolArr[boolArrSize];
    for (UInt i = 0; i != boolArrSize; ++i) {
        boolArr[i] = true;
    }

    UInt curIdx = 2;
    while (n > 0) {
        cout << curIdx;
        // Cross out all dividend
        for (UInt i = 1; i * curIdx < boolArrSize; ++i) {
            boolArr[i * curIdx] = false;
        }

        // Find the next curIdx
        for (UInt i = curIdx + 1; i < boolArrSize; ++i) {
            if (boolArr[i]) {
                curIdx = i;
                break;
            }
        }

        --n;
        if (n > 0) cout << " ";
    }

    return 0;
}
