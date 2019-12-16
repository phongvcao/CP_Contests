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


string decToBin( UInt n ) {
    string binNum = "";

    int quotient = n;
    int remainder = 0;

    do {
        remainder = quotient % 2;
        quotient = quotient / 2;

        stringstream ss;
        ss << remainder;
        binNum = ss.str() + binNum;
    } while ( quotient > 0 );

    return binNum;
}


UInt intPow( UInt a, UInt b ) {
    if ( a == 0 ) return 0;

    UInt result = 1;

    for ( UInt i = 0; i < b; ++i ) {
        result *= a;
    }

    return result;
}


UInt binToDec( string binNum ) {
    UInt result = 0;

    for ( Int i = binNum.size() - 1; i >= 0; --i ) {
        result += intPow( charToInt( binNum[ i ] ) * 2, binNum.size() - 1 - i );
    }

    return result;
}


void testFunc() {
    char charNum = '9';
    cout << "TEST: charToInt( '9' ): " << charToInt( charNum ) << endl;

    UInt decNum = 10;
    cout << "TEST: decToBin( 10 ): " << decToBin( decNum ) << endl;

    UInt a = 2;
    UInt b = 4;
    cout << "TEST: intPow( 2, 4 ): " << intPow( a, b ) << endl;

    string binNum = "1000";
    cout << "TEST: binToDec( 1000 ): " << binToDec( binNum ) << endl;
}


int main(int argc, char **argv) {
    // testFunc();

    UInt x = 0;
    cin >> x;

    string xBin = decToBin( x );

    UInt bacteriaCount = 0;
    for ( UInt i = 0; i < xBin.size(); ++i ) {
        if ( xBin[ i ] == '1' ) {
            ++bacteriaCount;
        }
    }

    cout << bacteriaCount;

    return 0;
}
