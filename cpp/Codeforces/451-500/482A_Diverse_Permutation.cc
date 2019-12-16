#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include <cstdlib>


using namespace std;
typedef int64_t Int;
typedef uint64_t UInt;


int main(int argc, char **argv) {
    Int n = 0;
    Int k = 0;
    cin >> n >> k;

    Int mult = k;
    Int multSign = 1;

    Int base = 1;
    string output = "";

    while (mult >= 0) {
        cout << base;
        base += mult * multSign;
        multSign = -multSign;
        --mult;

        if (mult >= 0) {
            cout << " ";
        }
    }

    if (n - k > 1) {
        cout << " ";

        for (int i = k + 2; i < n + 1; ++i) {
            cout << i;

            if (i < n) {
                cout << " ";
            }
        }
    }

    return 0;
}
