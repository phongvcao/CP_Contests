#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include <cstdlib>
#include <stdio.h>


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
    Int l = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n >> l;
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

    double maxDist = 0;
    for (Int i = 0; i != n - 1; ++i) {
        if (intArr[i + 1] - intArr[i] > maxDist) {
            maxDist = intArr[i + 1] - intArr[i];
        }
    }

    maxDist /= 2;

    double streetBegin = intArr[0];
    double streetEnd = intArr[n - 1];
    double streetBeginDist = streetBegin;
    double streetEndDist = l - streetEnd;

    if (maxDist < streetBeginDist) {
        maxDist = streetBeginDist;
    }

    if (maxDist < streetEndDist) {
        maxDist = streetEndDist;
    }

    printf("%.10f", maxDist);

    return 0;
}
