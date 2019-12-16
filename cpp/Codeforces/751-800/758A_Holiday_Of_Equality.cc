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
    UInt n = 0;
    string line = "";

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> n;
    }

    if ( getline( cin, line ) ) {
        int intArr[ n ];
        stringstream ss( line );
        UInt max = 0;
        UInt num = 0;
        UInt sum = 0;
        for ( int i = 0; i < n; ++i ) {
            ss >> num;
            sum += num;

            if ( num > max ) {
                max = num;
            }
        }

        cout << max * n - sum;
    }

    return 0;
}
