#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int getIdxNextNonZero(int *intArr, int curPos, int length) {
    int nextNonZero = -1;

    for (int i = curPos + 1; i != length; ++i) {
        if (intArr[i] != 0) {
            nextNonZero = i;
            break;
        }
    }

    return nextNonZero;
}


int getIdxPrevNonZero(int *intArr, int curPos) {
    int prevNonZero = -1;

    for (int i = curPos - 1; i >= 0; --i) {
        if (intArr[i] != 0) {
            prevNonZero = i;
        }
    }

    return prevNonZero;
}


int main(int argc, char **argv) {
    int n = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n;
    }

    int intArr[n];
    int intArrIdx = 0;
    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        while (intArrIdx < n) {
            ss >> intArr[intArrIdx++];
        }
    }

    // Logic starts here
    int nextNonZeroIdx = 0;
    int prevNonZeroIdx = 0;
    int curIdx = 0;
    bool isMovingForward = true;
    std::string operationsStr = "";


    while (getIdxNextNonZero(intArr, -1, n) != -1) {
        if (isMovingForward) {
            if ((intArr[curIdx] > 0) && (curIdx < n)) {
                operationsStr += "RLP";
                --intArr[curIdx];
            }

            // Now go ahead and check others
            nextNonZeroIdx = getIdxNextNonZero(intArr, curIdx, n);

            while (nextNonZeroIdx != -1) {
                for (int i = curIdx; i != nextNonZeroIdx; ++i) {
                    operationsStr += "R";
                }

                operationsStr += "P";
                --intArr[nextNonZeroIdx];

                curIdx = nextNonZeroIdx;
                nextNonZeroIdx = getIdxNextNonZero(intArr, nextNonZeroIdx, n);
            }

            isMovingForward = false;
        }

        else {
            if ((intArr[curIdx] > 0) && (curIdx > 0)) {
                operationsStr += "LRP";
                --intArr[curIdx];
            }

            prevNonZeroIdx = getIdxPrevNonZero(intArr, curIdx);

            while (prevNonZeroIdx != -1) {
                for (int i = curIdx; i > prevNonZeroIdx; --i) {
                    operationsStr += "L";
                }

                operationsStr += "P";
                --intArr[prevNonZeroIdx];

                curIdx = prevNonZeroIdx;
                prevNonZeroIdx = getIdxPrevNonZero(intArr, curIdx);
            }

            isMovingForward = true;
        }
    }

    std::cout << operationsStr;

    return 0;
}
