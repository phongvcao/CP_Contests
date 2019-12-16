#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include <cmath>
#include <algorithm>


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

    Int intArr[n];
    Int intArrIdx = 0;
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (intArrIdx < n) {
            ss >> intArr[intArrIdx++];
        }
    }

    // Logic starts here
    Int maxPrime = 1000001;
    bool isPrime[maxPrime];
    for (Int i = 0; i != maxPrime; ++i) {
        isPrime[i] = true;
    }

    for (Int i = 2; i < maxPrime; ++i) {
        for (Int j = 2; j * i < maxPrime; ++j) {
            isPrime[i * j] = false;
        }

        // Find the next prime
        for (Int k = i + 1; k < maxPrime; ++k) {
            if (isPrime[k]) {
                i = k - 1;
                break;
            }
        }
    }

    for (Int i = 0; i != n; ++i) {
        double tempSqrt = sqrt(intArr[i]);
        Int tempSqrtInt = (Int)tempSqrt;

        if (tempSqrtInt >= 2) {
            if ((tempSqrt == tempSqrtInt) && (isPrime[tempSqrtInt])) {
                cout << "YES";
            }

            else {
                cout << "NO";
            }
        }

        else {
            cout << "NO";
        }

        if (i < n - 1) cout << endl;
    }



    return 0;
}
