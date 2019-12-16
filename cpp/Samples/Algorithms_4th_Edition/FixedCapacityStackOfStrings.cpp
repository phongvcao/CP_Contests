#include "FixedCapacityStackOfStrings.h"

FixedCapacityStackOfStrings::FixedCapacityStackOfStrings() :
    N( 0 ),
    a( NULL )
{

}

FixedCapacityStackOfStrings::FixedCapacityStackOfStrings( int cap ) :
    N( cap ),
    a( NULL )
{
    this->a = new std::string[ cap ];
}

FixedCapacityStackOfStrings::~FixedCapacityStackOfStrings() {
    delete [] this->a;
}

bool FixedCapacityStackOfStrings::isEmpty() {
    return N == 0;
}

int FixedCapacityStackOfStrings::size() {
    return N;
}

void FixedCapacityStackOfStrings::push( std::string item ) {
    a[ N++ ] = item;
}

std::string FixedCapacityStackOfStrings::pop() {
    return a[ --N ];
}
