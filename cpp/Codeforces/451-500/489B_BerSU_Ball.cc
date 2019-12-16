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


Int countPairs(Int *bArr, Int bArrLength, Int *gArr, Int gArrLength) {
    Int bArrIdx = 0;
    Int gArrIdx = 0;
    Int pairsCount = 0;

    while ((bArrIdx < bArrLength) && (gArrIdx < gArrLength)) {
        if (abs(bArr[bArrIdx] - gArr[gArrIdx]) <= 1) {
            ++pairsCount;
            ++bArrIdx;
            ++gArrIdx;
        }

        else {
            if (bArr[bArrIdx] < gArr[gArrIdx]) {
                ++bArrIdx;
            }

            else if (bArr[bArrIdx] > gArr[gArrIdx]) {
                ++gArrIdx;
            }
        }
    }

    return pairsCount;
}


int main(int argc, char **argv) {
    Int n = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n;
    }

    Int boysArr[n];
    Int boysArrIdx = 0;
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (boysArrIdx < n) {
            ss >> boysArr[boysArrIdx++];
        }
    }

    Int m  = 0;
    // Read the third line
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> m;
    }

    Int girlsArr[m];
    Int girlsArrIdx = 0;
    // Read the fourth line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (girlsArrIdx < m) {
            ss >> girlsArr[girlsArrIdx++];
        }
    }

    // Logic starts here
    quickSort(boysArr, 0, n - 1);
    quickSort(girlsArr, 0, m - 1);

    cout << countPairs(boysArr, n, girlsArr, m);

    return 0;
}
