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


string whitePieces = "QRBNPK";
string blackPieces = "qrbnpk";


bool isWhite( char c ) {
    for ( UInt i = 0; i < whitePieces.size(); ++i ) {
        if ( c == whitePieces[ i ] ) {
            return true;
        }
    }

    return false;
}


bool isBlack( char c ) {
    for ( UInt i = 0; i < blackPieces.size(); ++i ) {
        if ( c == blackPieces[ i ] ) {
            return true;
        }
    }

    return false;
}


int getWeight( char c ) {
    switch ( c ) {
        case 'q':
        case 'Q':
            {
                return 9;
            }

        case 'r':
        case 'R':
            {
                return 5;
            }

        case 'b':
        case 'B':
            {
                return 3;
            }

        case 'n':
        case 'N':
            {
                return 3;
            }

        case 'p':
        case 'P':
            {
                return 1;
            }

        default: 
            {
                return 0;
            }
    }
}


int main(int argc, char **argv) {
    int totalWhite = 0;
    int totalBlack = 0;

    string line = "";
    for ( int i = 0; i < 8; ++i ) {
        if ( getline( cin, line ) ) {
            for ( int j = 0; j < 8; ++j ) {
                if ( isWhite( line[ j ] ) ) {
                    totalWhite += getWeight( line[ j ] );
                }

                else if ( isBlack( line[ j ] ) ) {
                    totalBlack += getWeight( line[ j ] );
                }
            }
        }
    }

    if ( totalWhite > totalBlack ) {
        cout << "White";
    }

    else if ( totalWhite < totalBlack ) {
        cout << "Black";
    }

    else {
        cout << "Draw";
    }

    return 0;
}
