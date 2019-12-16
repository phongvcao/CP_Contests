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


Int max(Int a, Int b) {
    return (a > b) ? a : b;
}


int main(int argc, char **argv) {
    Int n = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n;
    }

    Int intArr[n];
    Int intArrIdx = 0;
    Int maxSum = 0;
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (intArrIdx < n) {
            ss >> intArr[intArrIdx++];
            maxSum += intArr[intArrIdx - 1];
        }
    }

    // Logic starts here
    // Find divisor of n that is larger than 2 (>= 3)
    // since a polygon must have at least 3 edges
    for (Int i = 1; i < n / 2; ++i) {
        if (n % i == 0) {
            // Now that we got n / i as a divisor of n which is larger than 3,
            // this means that i is the block size of the circle if we
            // divide the circle into n / i blocks (segments).

            // Now we choose an index (smaller than blockSize) which applies to
            // all the blocks since they are of equal size.
            // (j is the element index)
            for (Int j = 0; j < i; ++j) {
                // Here is the currentSum for the current n / i
                Int curSum = 0;

                // Then we loop through all the blocks
                // (k is the block index)
                for (Int k = 0; k < n / i; ++k) {
                    curSum += intArr[k * i + j];
                }
                maxSum = max(curSum, maxSum);
            }

        }
    }

    cout << maxSum;


    return 0;
}
