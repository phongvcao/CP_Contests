#include "FixedCapacityStackOfStrings.h"
#include <stringstream>

int main( int argc, char **argv ) {
    FixedCapacityStackOfStrings s( 100 );

    std::string line;
    while ( getline( std::cin, line ) ) {
        std::stringstream ss( line );
    }

    std::cout << "My FixedCapacityStackOfStringsTest!!!" << std::endl;

    return 0;
}
