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


bool isContainsBlackSquare(vector<vector<bool> >& rectMatrix, Int curRowIdx, Int curColIdx, Int totalRow, Int totalCol) {
    // Check upper left
    if ((curRowIdx - 1 >= 0) && (curColIdx - 1 >= 0)) {
        if ((rectMatrix[curRowIdx][curColIdx])
                && (rectMatrix[curRowIdx - 1][curColIdx])
                && (rectMatrix[curRowIdx][curColIdx - 1])
                && (rectMatrix[curRowIdx - 1][curColIdx - 1])) {
            return true;
        } }

    // Check upper right
    if ((curRowIdx - 1 >= 0) && (curColIdx + 1 < totalCol)) {
        if ((rectMatrix[curRowIdx][curColIdx])
                && (rectMatrix[curRowIdx - 1][curColIdx])
                && (rectMatrix[curRowIdx][curColIdx + 1])
                && (rectMatrix[curRowIdx - 1][curColIdx + 1])) {
            return true;
        }
    }

    // Check lower left
    if ((curRowIdx + 1 < totalRow) && (curColIdx - 1 >= 0)) {
        if ((rectMatrix[curRowIdx][curColIdx])
                && (rectMatrix[curRowIdx + 1][curColIdx])
                && (rectMatrix[curRowIdx][curColIdx - 1])
                && (rectMatrix[curRowIdx + 1][curColIdx - 1])) {
            return true;
        }
    }

    // Check lower right
    if ((curRowIdx + 1 < totalRow) && (curColIdx + 1 < totalCol)) {
        if ((rectMatrix[curRowIdx][curColIdx])
                && (rectMatrix[curRowIdx + 1][curColIdx])
                && (rectMatrix[curRowIdx][curColIdx + 1])
                && (rectMatrix[curRowIdx + 1][curColIdx + 1])) {
            return true;
        }
    }

    return false;
}


int main(int argc, char **argv) {
    Int n = 0;
    Int m = 0;
    Int k = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n >> m >> k;
    }

    Int rowArr[k];
    Int colArr[k];
    Int rowColIdx = 0;
    // Read the next k lines
    while (getline(cin, line)) {
        stringstream ss(line);

        ss >> rowArr[rowColIdx] >> colArr[rowColIdx];

        ++rowColIdx;

        if (rowColIdx == k) break;
    }


    // Logic starts here
    vector<vector<bool> > rectMatrix;
    for (Int i = 0; i != n; ++i) {
        vector<bool> rowVector;
        for (Int j = 0; j != m; ++j) {
            rowVector.push_back(false);
        }

        rectMatrix.push_back(rowVector);
    }

    Int movesIdx = -1;
    for (Int i = 0; i != k; ++i) {
        rectMatrix[rowArr[i] - 1][colArr[i] - 1] = true;

        if (isContainsBlackSquare(rectMatrix, rowArr[i] - 1, colArr[i] - 1, n, m)) {
            movesIdx = i;
            break;
        }
    }

    cout << movesIdx + 1;


    return 0;
}
