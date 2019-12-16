#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>


using namespace std;
typedef int64_t Int;
typedef uint64_t UInt;


UInt calculateBinominal(UInt n, UInt k) {
    if ((n == k) || (k == 0)) return 1;

    if (k > n) return 0;

    if (k == 1) return n;

    UInt m = (k > (n - k)) ? n - k : k;
    UInt bin = 1;
    for (UInt i = 1; i < m + 1; ++i) {
        bin *= n - (m - i);
        bin /= i;
    }

    return bin;
}


void testCalculateBinonimal() {
    cout << calculateBinominal(10, 1) << endl;
    cout << calculateBinominal(10, 2) << endl;
    cout << calculateBinominal(10, 3) << endl;
    cout << calculateBinominal(10, 10) << endl;
}


int main(int argc, char **argv) {
    // testCalculateBinonimal();

    UInt n = 0;
    UInt m = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n >> m;
    }

    // Logic starts here
    UInt minPairs = 0;
    UInt maxPairs = 0;

    if (n == m) {

        cout << minPairs << " " << maxPairs;
    }

    else {
        UInt quotient = n / m;
        UInt remainder = n % m;
        UInt stopIdx = 0;
        UInt result = 0;

        if (remainder == 0) {
            result = calculateBinominal(quotient, 2) * (m - stopIdx);
            minPairs = result;
        }

        else {
            minPairs += calculateBinominal(quotient + 1, 2) * remainder;
            minPairs += calculateBinominal(quotient, 2) * (m - remainder);
        }

        // Calculate maxArr
        maxPairs += calculateBinominal(n - (m - 1), 2);

        cout << minPairs << " " << maxPairs;
    }

    return 0;
}
