#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main(int argc, char **argv) {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    bool intersectionsArr[n][m];
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != m; ++j) {
            intersectionsArr[i][j] = true;
        }
    }

    int turnsCount = 0;
    int intersectionsCount = n * m;
    int i = 0;
    int j = 0;
    while ((i < n) && (j < m)) {
        int rowIdx = i;
        int colIdx = j;

        for (int subColIdx = 0; subColIdx != m; ++subColIdx) {
            if (intersectionsArr[rowIdx][subColIdx]) {
                --intersectionsCount;
            }
            intersectionsArr[rowIdx][subColIdx] = false;
        }

        for (int subRowIdx = 0; subRowIdx != n; ++subRowIdx) {
            if (intersectionsArr[subRowIdx][colIdx]) {
                --intersectionsCount;
            }
            intersectionsArr[subRowIdx][colIdx] = false;
        }

        ++i;
        ++j;
        ++turnsCount;

        if (intersectionsCount == 0) break;
    }

    if (turnsCount % 2 == 1) {
        std::cout << "Akshat";
    }

    else {
        std::cout << "Malvika";
    }

    /* if ((n == 1) || (m == 1)) {
        std::cout << "Akshat";
    }

    else {
        if ((n * m) % 2 == 0) {
            std::cout << "Malvika";
        }

        else {
            std::cout << "Akshat";
        }
        } */

    return 0;
}
