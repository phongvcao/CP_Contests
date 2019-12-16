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

    if ( getline( cin, line ) ) {
        for ( int i = 0; i < line.size(); ++i ) {
            cout << line[ i ];
        }
        for ( int i = line.size() - 1; i >= 0; --i ) {
            cout << line[ i ];
        }
    }

    return 0;
}
