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


void quickSort(Int *intArr, Int first, Int last) {
    Int left = first;
    Int right = last;
    Int pivot = intArr[(left + right) / 2];

    if (first >= last) return;

    do {
        while (intArr[left] < pivot) ++left;
        while (intArr[right] > pivot) --right;

        if (left <= right) {
            Int temp = intArr[left];
            intArr[left] = intArr[right];
            intArr[right] = temp;

            ++left;
            --right;
        }

    } while (left <= right);

    quickSort(intArr, first, right);
    quickSort(intArr, left, last);
}


void copyArray(Int *srcArr, Int srcIdx, Int *destArr, Int destIdx, Int length) {
    for (Int i = 0; i != length; ++i) {
        destArr[destIdx++] = srcArr[srcIdx++];
    }
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
    Int orgIntArr[n];
    Int intArrIdx = 0;
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (intArrIdx < n) {
            ss >> intArr[intArrIdx++];
        }
    }

    // Logic starts here
    copyArray(intArr, 0, orgIntArr, 0, n);
    quickSort(intArr, 0, n - 1);

    Int firstDiffIdx = -1;
    Int secondDiffIdx = -1;
    for (Int i = 0; i != n; ++i) {
        if (intArr[i] != orgIntArr[i]) {
            if (firstDiffIdx == -1) {
                firstDiffIdx = i;
                break;
            }
        }
    }

    for (Int i = n - 1; i >= 0; --i) {
        if (intArr[i] != orgIntArr[i]) {
            if (secondDiffIdx == -1) {
                secondDiffIdx = i;
                break;
            }
        }
    }

    if ((firstDiffIdx == -1) && (secondDiffIdx == -1)) {
        cout << "yes" << endl;
        cout << 1 << " " << 1;
    }

    else {
        for (Int i = 0; i + firstDiffIdx <= secondDiffIdx; ++i) {
            if (intArr[i + firstDiffIdx] != orgIntArr[secondDiffIdx - i]) {
                cout << "no";
                return 0;
            }
        }

        cout << "yes" << endl;
        cout << firstDiffIdx + 1 << " " << secondDiffIdx + 1;
    }


    return 0;
}
