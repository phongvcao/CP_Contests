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
        while (intArr[left] < pivot) ++left;
        while (intArr[right] > pivot) --right;

        if (left <= right) {
            swap(intArr[left], intArr[right]);

            ++left;
            --right;
        }

    } while (left <= right);

    quickSort(intArr, first, right);
    quickSort(intArr, left, last);
}


Int skipValue(Int *intArr, Int curIdx, Int value) {
    ++curIdx;

    while (intArr[curIdx] == value) {
        ++curIdx;
    }

    return curIdx;
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

    // Logic starts here
    quickSort(intArr, 0, n - 1);

    Int pairsCount = 0;
    for (Int i = 0; i < n; ++i) {
        if (intArr[i] == 0) {
            i = skipValue(intArr, i, intArr[i]);
            --i;
        }

        else {
            Int nextIdx = skipValue(intArr, i, intArr[i]);

            if (nextIdx <= n) {
                if (nextIdx - i == 2) {
                    ++pairsCount;
                    i = nextIdx;
                    --i;
                }

                else if (nextIdx - i > 2) {
                    cout << -1;
                    return 0;
                }
            }

            else {
                break;
            }
        }
    }

    cout << pairsCount;

    return 0;
}
