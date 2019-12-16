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


void reverseArr(UInt *intArr, int first, int last) {
    while (first < last) {
        UInt temp = intArr[first];
        intArr[first] = intArr[last];
        intArr[last] = temp;

        ++first;
        --last;
    }
}


int main(int argc, char **argv) {
    UInt n = 0;
    UInt k = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n >> k;
    }

    UInt intArr[n];
    // Fill array
    for (UInt i = 1; i != n + 1; ++i) {
        intArr[i - 1] = i;
    }

    // Logic starts here
    reverseArr(intArr, 0, k);

    for (UInt i = 0; i != n; ++i) {
        cout << intArr[i];

        if (i < n - 1)
            cout << " ";
    }

    return 0;
}
