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


UInt getMinDistance( UInt a, UInt b ) {
    return a - b < 10 - a + b ? a - b : 10 - a + b;
}


int main(int argc, char **argv) {

    string line = "";
    if ( getline( cin, line ) ) {
        UInt n = 0;
        string orgCombination = "";
        string correctCombination = "";
        UInt totalMoves = 0;

        stringstream ss( line );
        ss >> n;
        if ( getline( cin, orgCombination ) ) {
            if ( getline( cin, correctCombination ) ) {
                for ( UInt i = 0; i < orgCombination.size(); ++i ) {
                    UInt a = orgCombination[ i ] >= correctCombination[ i ] ?
                        orgCombination[ i ] : correctCombination[ i ];
                    UInt b = orgCombination[ i ] <= correctCombination[ i ] ?
                        orgCombination[ i ] : correctCombination[ i ];
                    totalMoves += getMinDistance( a, b );
                }
            }
        }

        cout << totalMoves;
    }

    return 0;
}
