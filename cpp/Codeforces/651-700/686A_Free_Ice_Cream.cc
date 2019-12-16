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
    UInt x = 0;

    if ( getline( cin, line ) ) {
        stringstream ss( line );

        ss >> n >> x;
    }

    UInt distressed = 0;
    for ( int i = 0; i < n; ++i ) {
        if ( getline( cin, line ) ) {
            stringstream ss( line );

            string sign = "";
            UInt num = 0;

            ss >> sign >> num;

            if ( sign == "+" ) {
                x += num;
            } else if ( sign == "-" ) {
                if ( num > x ) {
                    ++distressed;
                } else {
                    x -= num;
                }
            }
        }
    }

    cout << x << " " << distressed;

    return 0;
}
