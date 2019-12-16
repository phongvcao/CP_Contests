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

bool isSeatEmpty( char seat ) {
    if ( ( seat == 'O' ) || ( seat == 'o' ) ) {
        return true;
    }

    return false;
}

bool isLeftPairEmpty( string row ) {
    if ( isSeatEmpty( row[ 0 ] ) && isSeatEmpty( row[ 1 ] ) ) {
        return true;
    }

    return false;
}

bool isRightPairEmpty( string row ) {
    if ( isSeatEmpty( row[ 3 ] ) && isSeatEmpty( row[ 4 ] ) ) {
        return true;
    }

    return false;
}


int main(int argc, char **argv) {
    string line = "";
    vector<string> lineVector;

    getline( cin, line );

    while ( getline( cin, line ) ) {
        lineVector.push_back( line );
    }

    string answer = "NO";
    for ( UInt i = 0; i < lineVector.size(); ++i ) {
        if ( isLeftPairEmpty( lineVector[ i ] ) ) {
            lineVector[ i ][ 0 ] = '+';
            lineVector[ i ][ 1 ] = '+';
            answer = "YES";
            break;
        } else if ( isRightPairEmpty( lineVector[ i ] ) ) {
            lineVector[ i ][ 3 ] = '+';
            lineVector[ i ][ 4 ] = '+';
            answer = "YES";
            break;
        }
    }

    if ( answer == "YES" ) {
        cout << answer << endl;
        for ( UInt i = 0; i < lineVector.size(); ++i ) {
            cout << lineVector[ i ];

            if ( i < lineVector.size() - 1 ) {
                cout << endl;
            }
        }
    } else {
        cout << answer;
    }

    return 0;
}
