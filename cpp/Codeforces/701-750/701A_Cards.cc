#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
typedef int64_t Int;
typedef uint64_t UInt;

class Number {
    public:
        Number();
        Number( Int value, Int pos );
        virtual ~Number();
        Int value;
        Int pos;
};

Number::Number() :
    value( 0 ),
    pos( 0 )
{

}

Number::Number( Int value, Int pos ) :
    value( value ),
    pos( pos )
{

}

Number::~Number() {

}


void quickSort( vector< Number >& numVector, Int first, Int last ) {
    Int left = first;
    Int right = last;
    Number pivot = numVector[ ( left + right ) / 2 ];

    if ( first >= last ) return;

    do {
        while ( numVector[ left ].value < pivot.value ) ++left;
        while ( numVector[ right ].value > pivot.value ) --right;

        if ( left <= right ) {
            Number temp = numVector[ left ];
            numVector[ left ] = numVector[ right ];
            numVector[ right ] = temp;

            ++left;
            --right;
        }

    } while ( left <= right );

    quickSort( numVector, first, right );
    quickSort( numVector, left, last );
}

int main(int argc, char **argv) {
    UInt n = 0;
    string line = "";

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> n;
    }

    if ( getline( cin, line ) ) {
        stringstream ss( line );

        vector< Number > intVector;
        for ( int i = 0; i < n; ++i ) {
            Int val = 0;
            ss >> val;
            Number num( val, i );
            intVector.push_back( num );
        }

        quickSort( intVector, 0, n - 1 );

        for ( int i = 0; i < intVector.size() / 2; ++i ) {
            cout << intVector[ i ].pos + 1 << " " << intVector[ intVector.size() - 1 - i ].pos + 1;

            if ( i < intVector.size() / 2 - 1 ) {
                cout << endl;
            }
            // cout << "DEBUG: value: " << intVector[ i ].value << "; pos: " << intVector[ i ].pos << endl;
        }
    }

    return 0;
}
