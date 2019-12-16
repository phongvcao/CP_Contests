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
    UInt n = 1, h = 1;
    vector<UInt> heightVector;
    string line;

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> n >> h;
    }

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        UInt w = 0;
        for ( UInt i = 0; i < n; ++i ) {
            UInt height = 0;
            ss >> height;
            // heightVector.push_back( height );
            if ( height > h ) {
                w += 2;
            } else {
                w += 1;
            }
        }
        cout << w;
    }

    return 0;
}
