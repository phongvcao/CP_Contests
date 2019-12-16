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


Int intPow(Int a, Int b) {
    Int result = 1;

    for (Int i = 0; i != b; ++i) {
        result *= a;
    }

    return result;
}


Int goLeftChild(Int *treeArr, bool *visitedArr, Int curIdx, Int n, Int *stepsCount) {


    goRightChild(curIdx);

    return curIdx * 2 + 1;
}


Int goRightChild(Int *treeArr, bool *visitedArr, Int curIdx, Int n, Int *stepsCount) {
    return curIdx * 2 + 2;
}


Int goParent(Int curIdx) {
    return (curIdx - 1) / 2;
}


int main(int argc, char **argv) {
    Int h = 0;
    Int n = 0;
    cin >> h >> n;

    Int nodesCount = intPow(2, h + 1) - 1;
    Int treeArr[nodesCount];
    bool visitedArr[nodesCount];
    Int noneLeavesCount = intPow(2, h) - 1;
    Int leavesCount = nodesCount - noneLeavesCount;

    for (Int i = 0; i != noneLeavesCount; ++i) {
        treeArr[i] = 0;
    }

    Int index = 1;
    for (Int i = noneLeavesCount; i != nodesCount; ++i) {
        treeArr[i] = index;
        ++index;
    }

    for (Int i = 0; i != nodesCount; ++i) {
        visitedArr[i] = false;
    }

    Int curIdx = 0;
    Int visitedCount = 0;
    Int lastStep = -1;
    bool justSkipped = false;
    bool justBacktracked = false;
    bool keepGoing = true;
    while (treeArr[curIdx] != n) {
        keepGoing = true;

        // If the destination node is already visited, Amr skips current command
        if (visitedArr[curIdx]) {
            // Skipped 2 consecutive commands
            if (justSkipped) {
                justSkipped = false;

                // If Amr skipped two consecutive commands, he goes back to the
                // parent of the current node
                curIdx = goParent(curIdx);
                keepGoing = false;
                justBacktracked = true;
            }

            else {
                // If he has not skipped two consecutive commands, mark this as
                // skipped and continue to go
                justSkipped = true;
            }

        }

        if (keepGoing) {
            visitedArr[curIdx] = true;
            ++visitedCount;
            // justSkipped = false;
            justBacktracked = false;

            if (lastStep == 1) {
                if (treeArr[curIdx] == 0) {
                    curIdx = goRightChild(curIdx);

                    if ((treeArr[curIdx] != 0) && (treeArr[curIdx] != n)) {
                        visitedArr[curIdx] = true;
                        curIdx = goParent(curIdx);
                    }
                }

                else if (treeArr[curIdx] != 0) {
                    curIdx = goParent(curIdx);
                }
            }

            else {
                if (treeArr[curIdx] == 0) {
                    curIdx = goLeftChild(curIdx);

                    if ((treeArr[curIdx] != 0) && (treeArr[curIdx] != n)) {
                        visitedArr[curIdx] = true;
                        curIdx = goParent(curIdx);
                    }
                }

                else if (treeArr[curIdx] != 0) {
                    curIdx = goParent(curIdx);
                }
            }

            lastStep = -lastStep;
        }
    }

    cout << visitedCount;

    return 0;
}
