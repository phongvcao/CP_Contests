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
    UInt n = 0;
    UInt m = 0;
    cin >> n >> m;

    UInt dancesCount = n + (m - 1);

    cout << dancesCount << endl;

    for (UInt i = 0; i != m; ++i) {
        cout << 1 << " " << i + 1;

        if (i < m - 1) {
            cout << endl;
        }
    }

    if (n >= 2) cout << endl;

    for (UInt j = 2; j <= n; ++j) {
        cout << j << " " << 1;

        if (j < n) {
            cout << endl;
        }
    }

    return 0;
}
