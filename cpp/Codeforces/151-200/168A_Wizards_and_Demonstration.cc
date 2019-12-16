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
    Int n = 0;
    Int x = 0;
    Int y = 0;
    cin >> n >> x >> y;

    double doubleY = (double)y;
    double percentage = doubleY / 100;

    double totalWizards = n * percentage;
    Int totalWizardsInt = (Int)totalWizards;

    if (totalWizards != (Int)totalWizards) {
        ++totalWizardsInt;
    }

    if (totalWizardsInt - x > 0) {
        cout << totalWizardsInt - x;
    }

    else {
        cout << 0;
    }


    return 0;
}
