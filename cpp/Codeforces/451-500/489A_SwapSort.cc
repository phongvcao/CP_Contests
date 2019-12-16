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


void quickSort(vector<Int>& numVector, Int first, Int last) {
    Int left = first;
    Int right = last;
    Int pivot = numVector[(left + right) / 2];

    if (first >= last) return;

    do {
        while (numVector[left] < pivot) ++left;
        while (numVector[right] > pivot) --right;

        if (left <= right) {
            Int temp = numVector[left];
            numVector[left] = numVector[right];
            numVector[right] = temp;

            ++left;
            --right;
        }

    } while (left <= right);

    quickSort(numVector, first, right);
    quickSort(numVector, left, last);
}


int main(int argc, char **argv) {
    Int n = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n;
    }

    vector<Int> orgNumVector;
    vector<Int> newNumVector;
    Int numIdx = 0;
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (numIdx < n) {
            Int value = 0;
            ss >> value;

            orgNumVector.push_back(value);
            newNumVector.push_back(value);

            ++numIdx;
        }
    }

    // Logic starts here
    quickSort(newNumVector, 0, n - 1);
    vector<Int> swappedPairs;

    for (Int i = 0; i != n; ++i) {
        if (newNumVector[i] != orgNumVector[i]) {
            for (Int j = n - 1; j >= i + 1; --j) {
                if ((newNumVector[i] == orgNumVector[j]) && (newNumVector[i] != newNumVector[j]) && (orgNumVector[i] != orgNumVector[j])) {
                    Int temp = orgNumVector[i];
                    orgNumVector[i] = orgNumVector[j];
                    orgNumVector[j] = temp;

                    swappedPairs.push_back(i);
                    swappedPairs.push_back(j);
                }
            }
        }
    }

    // Write out
    if (swappedPairs.size() == 0) {
        cout << 0;
    }

    else {
        cout << swappedPairs.size() / 2 << endl;
        for (Int i = 0; i + 1 < swappedPairs.size(); i += 2) {
            cout << swappedPairs[i] << " " << swappedPairs[i + 1];

            if (i + 2 < swappedPairs.size()) {
                cout << endl;
            }
        }
    }

    return 0;
}
