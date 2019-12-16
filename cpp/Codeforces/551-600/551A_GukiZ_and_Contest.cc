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


class Number {
    public:
        Number();
        Number( UInt value, UInt index );
        virtual ~Number();

        UInt value;
        UInt index;
        UInt rank;
};


Number::Number() :
    value( 0 ),
    index( 0 ),
    rank( 0 )
{

}

Number::Number( UInt value, UInt index ) :
    value( value ),
    index( index ),
    rank( 0 )
{

}

Number::~Number() {

}

void quickSortIndex( vector< Number >& numVector, Int first, Int last ) {
    Int left = first;
    Int right = last;
    Number pivot = numVector[ ( left + right ) / 2 ];

    if ( first >= last ) return;

    do {
        while ( numVector[ left ].index < pivot.index ) ++left;
        while ( numVector[ right ].index > pivot.index ) --right;

        if ( left <= right ) {
            Number temp = numVector[ left ];
            numVector[ left ] = numVector[ right ];
            numVector[ right ] = temp;

            ++left;
            --right;
        }
    } while ( left <= right );

    quickSortIndex( numVector, first, right );
    quickSortIndex( numVector, left, last );
}

void quickSortValue( vector< Number >& numVector, Int first, Int last ) {
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

    quickSortValue( numVector, first, right );
    quickSortValue( numVector, left, last );
}


int main(int argc, char **argv) {
    string line = "";

    UInt n = 0;

    if ( getline( cin, line ) ) {
        stringstream ss( line );

        ss >> n;
    }

    vector< Number > numVector;

    if ( getline( cin, line ) ) {
        stringstream ss( line );

        for ( int i = 0; i < n; ++i ) {
            UInt m = 0;
            ss >> m;

            Number num( m, i );
            numVector.push_back( num );
        }

        quickSortValue( numVector, 0, n - 1 );
        
        UInt curRating = numVector[ numVector.size() - 1 ].value;
        UInt curRank = 0;
        UInt curIdx = 0;

        for ( int i = numVector.size() - 1; i >= 0; --i ) {
            ++curIdx;

            if ( numVector[ i ].value < curRating ) {
                curRating = numVector[ i ].value;
                curRank = curIdx - 1;
            }

            curRating = numVector[ i ].value;
            numVector[ i ].rank = curRank;
        }

        quickSortIndex( numVector, 0, n - 1 );

        for ( int i = 0; i < numVector.size(); ++i ) {
            cout << numVector[ i ].rank + 1;

            if ( i < numVector.size() - 1 ) {
                cout << " ";
            }
        }
    }

    return 0;
}
