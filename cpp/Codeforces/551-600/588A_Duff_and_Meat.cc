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


int main(int argc, char **argv) {
    UInt n = 0;
    string line = "";
    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> n;
    }

    UInt curMinPrice = -1;
    UInt totalPrice = 0;
    while ( getline( cin, line ) ) {
        UInt a = 0, p = 0;
        stringstream ss( line );
        ss >> a >> p;

        if ( ( curMinPrice == -1 ) || ( curMinPrice > p ) ) {
            curMinPrice = p;
        }

        totalPrice += curMinPrice * a;
        --n;

        if ( n == 0 ) {
            break;
        }
    }

    cout << totalPrice;


    return 0;
}
