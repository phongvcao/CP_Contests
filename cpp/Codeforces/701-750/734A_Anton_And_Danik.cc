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

UInt charToInt( char c ) {
    return c - '0';
}

int main(int argc, char **argv) {
    UInt n = 0;
    string line = "";
    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> n;
    }

    UInt antonCount = 0;
    UInt danikCount = 0;

    if ( getline( cin, line ) ) {
        for ( std::string::size_type i = 0; i < line.size(); ++i ) {
            if ( line[ i ] == 'A' ) {
                ++antonCount;
            } else {
                ++danikCount;
            }
        }

        if ( antonCount == danikCount ) {
            cout << "Friendship";
        } else if ( antonCount < danikCount ) {
            cout << "Danik";
        } else {
            cout << "Anton";
        }
    }

    return 0;
}
