#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include <cstdlib>
#include <algorithm>


using namespace std;
typedef int64_t Int;
typedef uint64_t UInt;


void quickSort(vector<Int>& intVector, Int first, Int last) {
    Int left = first;
    Int right = last;
    Int pivot = intVector[(left + right) / 2];

    if (first >= last) return;

    do {
        while (intVector[left] < pivot) ++left;
        while (intVector[right] > pivot) --right;

        if (left <= right) {
            Int temp = intVector[left];
            intVector[left] = intVector[right];
            intVector[right] = temp;

            ++left;
            --right;
        }

    } while (left <= right);

    quickSort(intVector, first, right);
    quickSort(intVector, left, last);
}


Int indexOf(const vector<Int>& intVector, Int value) {
    Int index = -1;

    Int left = 0;
    Int right = intVector.size() - 1;
    Int middle = (left + right) / 2;
    Int pivot = intVector[middle];

    while (right - left > 1) {
        if (value > pivot) {
            left = middle;
            middle = (left + right) / 2;
            pivot = intVector[middle];
        }

        else if (value < pivot) {
            right = middle;
            middle = (left + right) / 2;
            pivot = intVector[middle];
        }

        if (value == pivot) {
            index = middle;
            break;
        }
    }

    return index;
}


void testIndexOf() {
    Int intArr[] = { 1, 4, 8, 12, 14, 16, 25 };
    vector<Int> intVector;
    intVector.assign((Int*)intArr, (Int*)intArr + sizeof(intArr)/sizeof(Int));

    cout << indexOf(intVector, 1) << endl;
    cout << indexOf(intVector, 4) << endl;
    cout << indexOf(intVector, 8) << endl;
    cout << indexOf(intVector, 33) << endl;
}


int main(int argc, char **argv) {
    // testIndexOf();

    Int n = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n;
    }

    // vector<Point> pVector;
    unordered_map<Int, vector<Int> > xCountMap;
    unordered_map<Int, vector<Int> > yCountMap;
    Int lineIdx = 0;
    // Read the next n lines
    while (getline(cin, line)) {
        stringstream ss(line);

        Int x = 0;
        Int y = 0;

        ss >> x >> y;

        // Record x into xCountMap
        unordered_map<Int, vector<Int> >::iterator iter = xCountMap.find(x);

        if (iter != xCountMap.end()) {
            iter->second.push_back(y);
        }

        else {
            vector<Int> pVector;
            pVector.push_back(y);
            xCountMap.insert(make_pair(x, pVector));
        }

        // Record y into yCountMap
        iter = yCountMap.find(y);

        if (iter != yCountMap.end()) {
            iter->second.push_back(x);
        }

        else {
            vector<Int> pVector;
            pVector.push_back(x);
            yCountMap.insert(make_pair(y, pVector));
        }

        ++lineIdx;
        if (lineIdx == n) break;
    }

    // Logic starts here
    for (unordered_map<Int, vector<Int> >::iterator iter = xCountMap.begin(); iter != xCountMap.end(); ++iter) {
        if (iter->second.size() >= 3) {
            quickSort(iter->second, 0, iter->second.size() - 1);
        }
    }

    for (unordered_map<Int, vector<Int> >::iterator iter = yCountMap.begin(); iter != yCountMap.end(); ++iter) {
        if (iter->second.size() >= 3) {
            quickSort(iter->second, 0, iter->second.size() - 1);
        }
    }

    Int centralPointsCount = 0;
    // Now access the elements
    for (unordered_map<Int, vector<Int> >::iterator iter = xCountMap.begin(); iter != xCountMap.end(); ++iter) {
        if (iter->second.size() >= 3) {
            for (Int i = 1; i < iter->second.size() - 1; ++i) {
                unordered_map<Int, vector<Int> >::iterator yIter = yCountMap.find(iter->second[i]);

                if (yIter != yCountMap.end()) {
                    if (yIter->second.size() >= 3) {
                        Int index = indexOf(yIter->second, iter->first);

                        if ((index > 0) && (index < yIter->second.size() - 1)) {
                            ++centralPointsCount;
                        }
                    }
                }
            }
        }
    }

    // Output
    cout << centralPointsCount;

    return 0;
}
