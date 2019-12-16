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
    Int n = 0, m = 0;
    cin >> n >> m;

    for (Int i = 1; i <= n; ++i) {
        if (i % 2 == 1) {
            for (Int j = 0; j < m; ++j) {
                cout << "#";
            }
            cout << endl;
        } 

        else {
            if ((i / 2) % 2 == 1) {
                for (Int j = 0; j < m - 1; ++j) {
                    cout << ".";
                }
                cout << "#" << endl;
            }

            else {
                cout << "#";
                for (Int j = 1; j < m; ++j) {
                    cout << ".";
                }
                cout << endl;
            }
        }
    }

    return 0;
}
