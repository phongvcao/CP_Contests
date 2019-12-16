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


int main(int argc, char **argv) {
    UInt n = 0;
    cin >> n;

    if (n > 2) {
        for (UInt i = n; i >= 1; --i) {
            cout << i;

            if (i > 1) {
                cout << " ";
            }
        }
    }

    else {
        cout << -1;
    }


    return 0;
}
