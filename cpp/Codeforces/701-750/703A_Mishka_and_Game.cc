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
    UInt m = 0, c = 0;
    UInt mTotal = 0, cTotal = 0;
    string line = "";

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> n;
    }

    for ( int i = 0; i < n; ++i ) {
        if ( getline( cin, line ) ) {
            stringstream ss( line );
            ss >> m >> c;

            if ( m > c ) {
                ++mTotal;
            } else if ( m < c ) {
                ++cTotal;
            }
        }
    }

    if ( mTotal > cTotal ) {
        cout << "Mishka";
    } else if ( mTotal < cTotal ) {
        cout << "Chris";
    } else {
        cout << "Friendship is magic!^^";
    }

    return 0;
}
