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
        UInt count = 0;
        for ( int i = 0; i < line.size(); ++i ) {
            if ( ( line[ i ] == 'u' )
                    || ( line[ i ] == 'e' )
                    || ( line[ i ] == 'o' )
                    || ( line[ i ] == 'a' )
                    || ( line[ i ] == 'i' )
                    || ( ( line[ i ] - '0' >= 0 )
                        && ( line[ i ] - '0' <= 9 )
                        && ( ( line[ i ] - '0' ) % 2 == 1 ) ) ) {
                ++count;
            }
        }
        cout << count;
    }

    return 0;
}
