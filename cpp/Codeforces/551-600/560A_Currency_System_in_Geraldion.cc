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
    UInt n = 0;
    
    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> n;
    }

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        for ( int i = 0; i < n; ++i ) {
            UInt num = 0;
            ss >> num;

            if ( num == 1 ) {
                cout << -1;
                return 0;
            }
        }

        cout << 1;
    }

    return 0;
}
