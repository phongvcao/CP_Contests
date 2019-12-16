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
    Int k = 0;
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n >> k;
    }

    Int letterCountArr[26];
    for (Int i = 0; i != 26; ++i) {
        letterCountArr[i] = 0;
    }
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        for (Int i = 0; i != line.length(); ++i) {
            ++letterCountArr[line[i] - 'A'];
        }
    }

    // Logic starts here
    quickSort(letterCountArr, 0, 25);
    Int maxCoinsCount = 0;
    Int cardsChosenSoFar = 0;
    Int orgK = k;
    for (Int i = 0; i != 26; ++i) {
        k -= letterCountArr[i];

        if (k >= 0) {
            maxCoinsCount += letterCountArr[i] * letterCountArr[i];
            cardsChosenSoFar += letterCountArr[i];
        }

        else {
            maxCoinsCount += (orgK - cardsChosenSoFar) * (orgK - cardsChosenSoFar);
            break;
        }
    }

    cout << maxCoinsCount;


    return 0;
}
