#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
typedef int64_t Int;
typedef uint64_t UInt;

int main(int argc, char **argv) {
    map< string, UInt > facesCount;
    facesCount[ "Tetrahedron" ] = 4;
    facesCount[ "Cube" ] = 6;
    facesCount[ "Octahedron" ] = 8;
    facesCount[ "Dodecahedron" ] = 12;
    facesCount[ "Icosahedron" ] = 20;

    UInt n = 0, sum = 0;
    string line = "";

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> n;

        for ( int i = 0; i < n; ++i ) {
            if ( getline( cin, line ) ) {
                sum += facesCount[ line ];
            }
        }
    }

    cout << sum;

    return 0;
}
