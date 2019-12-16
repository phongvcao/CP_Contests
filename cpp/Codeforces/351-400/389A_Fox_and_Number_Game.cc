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


void quickSort(Int *intArr, Int first, Int last) {
    Int left = first;
    Int right = last;
    Int pivot = intArr[(left + right) / 2];

    if (first >= last) return;

    do {
        while (intArr[left] > pivot) ++left;
        while (intArr[right] < pivot) --right;

        if (left <= right) {
            swap(intArr[left], intArr[right]);

            ++left;
            --right;
        }

    } while (left <= right);

    quickSort(intArr, first, right);
    quickSort(intArr, left, last);
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
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (intArrIdx < n) {
            ss >> intArr[intArrIdx++];
        }
    }

    quickSort(intArr, 0, n - 1);
    // Logic starts here
    while (intArr[0] != intArr[n - 1]) {

        for (Int i = 0; i != n - 1; ++i) {
            if (intArr[i] > intArr[i + 1]) {
                intArr[i] = intArr[i] - intArr[i + 1];
            }
        }

        quickSort(intArr, 0, n - 1);
    };

    cout << intArr[0] * n;


    return 0;
}
