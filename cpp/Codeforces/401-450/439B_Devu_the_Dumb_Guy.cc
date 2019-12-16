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


int main(int argc, char **argv) {
    Int n = 0;
    Int x = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n >> x;
    }

    if (x == 1) {
        UInt hoursCount = 0;

        Int intArrIdx = 0;
        // Read the second line
        if (getline(cin, line)) {
            stringstream ss(line);

            while (intArrIdx < n) {
                Int curNum = 0;
                ss >> curNum;
                hoursCount += curNum;
                ++intArrIdx;
            }
        }

        cout << hoursCount;
    }

    else {
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
        UInt hoursCount = 0;
        Int oneStartIdx = -1;
        for (Int i = 0; i != n; ++i) {
            if (x > 1) {
                hoursCount += intArr[i] * (x--);
            }

            else {
                oneStartIdx = i;
                break;
            }
        }

        if (oneStartIdx != -1) {
            for (Int i = oneStartIdx; i != n; ++i) {
                hoursCount += intArr[i] * x;
            }
        }

        cout << hoursCount;
    }

    return 0;
}
