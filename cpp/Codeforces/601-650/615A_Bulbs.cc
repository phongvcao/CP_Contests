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
    string line = "";
    Int n = 0;
    Int m = 0;

    if ( getline( cin, line ) ) {
        stringstream ss( line );

        ss >> n >> m;
    }

    bool boolArr[ m ];
    fill_n( boolArr, m, false );
    for ( int i = 0; i < n; ++i ) {
        if ( getline( cin, line ) ) {
            stringstream ss( line );

            Int x = 0;
            ss >> x;

            for ( int j = 0; j < x; ++j ) {
                Int num = 0;
                ss >> num;
                boolArr[ num - 1 ] = true;
            }
        }
    }
   
    bool isTurnOnAll = true;
    for ( int i = 0; i < m; ++i ) {
        if ( ! boolArr[ i ] ) {
            isTurnOnAll = false;
            break;
        }
    }

    if ( isTurnOnAll ) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
