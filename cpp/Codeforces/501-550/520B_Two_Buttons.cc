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

Int finalCount = -1;

class Node {
    public:
        Node();
        Node(Int value, Int count);
        virtual ~Node();

        Int value;
        Int count;
};

Node::Node() :
    value( 0 ),
    count( 0 )
{

}

Node::Node( Int value, Int count ) :
    value( value ),
    count( count )
{

}

Node::~Node() {

}

int main(int argc, char **argv) {
    UInt n = 0, m = 0;

    cin >> n >> m;

    if ( n > m ) {
        cout << n - m;
    } else {
        // UInt initialDistance = distance( n, m );
        // UInt newDistance = initialDistance;
        //
        // while ( newDistance <= initialDistance ) {
        //     n *= 2;
        //     newDistance = distance( n, m );
        // }
    }

    return 0;
}
