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
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n;
    }

    if (n % 2 == 1) {
        cout << -1;
        return 0;
    }

    for (UInt i = n; i > 0; --i) {
        cout << i;

        if (i > 1) {
            cout << " ";
        }
    }

    return 0;
}
