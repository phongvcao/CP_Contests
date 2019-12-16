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


int main(int argc, char **argv) {
    Int maxN = 4001;
    Int ribbonArr[maxN];
    Int piecesArr[3];
    Int n = 0;

    cin >> n >> piecesArr[0] >> piecesArr[1] >> piecesArr[2];

    for (Int i = 0; i != maxN; ++i) {
        ribbonArr[i] = -1;
    }
    ribbonArr[0] = 1;

    if (piecesArr[0] > piecesArr[1]) swap(piecesArr[0], piecesArr[1]);
    if (piecesArr[1] > piecesArr[2]) swap(piecesArr[1], piecesArr[2]);
    if (piecesArr[0] > piecesArr[2]) swap(piecesArr[0], piecesArr[2]);

    for (Int i = 0; i != 3; ++i) {
        for (Int j = 0; j < maxN; ++j) {
            if ((j - piecesArr[i] >= 0) && (ribbonArr[j - piecesArr[i]] != 0)) {
                // The key is this condition - it makes sure that the count at
                // ribbonArr[j] is not incremented (from ribbonArr[j -
                // piecesArr[i]] more than once in case several piecesArr[i]
                // satisfy if condition above.
                //
                // Since we sorted piecesArr in non-decreasing order, the
                // piecesArr[i] that is smaller will go forward faster than the
                // piecesArr[i] that is larger. Thus, in the case that they
                // collide, meaning the larger and smaller piecesArr[i] have
                // the same Lowest Common Denominator, the larger piecesArr[i]
                // will replace the counts previously set by the smaller
                // piecesArr[i] which is larger. Thus, the following condition
                // exists to allow only the slots ribbon[j] that have not been
                // initialized or have been initialized but have not been
                // maximized (which is unlikely to be the case since the
                // piecesArr was sorted in non-decreasing order and we are
                // looping incrementally from i = 0 to i = 2, thus
                // ribbonArr[j - piecesArr[i]] for the smaller piecesArr[i] was
                // examined first and it was maxed out already) to be initialized.
                //

                if (ribbonArr[j] < ribbonArr[j - piecesArr[i]] + 1) {
                    ribbonArr[j] = ribbonArr[j - piecesArr[i]] + 1;
                }
            }
        }
    }

    cout << ribbonArr[n] - 1;


    return 0;
}
