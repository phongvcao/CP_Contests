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
    string line = "";
    UInt n = 0;
    UInt sum = 0;
    Int minOdd = -1;

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> n;
    }

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        for ( int i = 0; i < n; ++i ) {
            UInt num = 0;
            ss >> num;
            sum += num;
            if ( ( num % 2 == 1 ) && ( ( minOdd == -1 ) || ( minOdd > num ) ) ) {
                minOdd = num;
            }
        }

        if ( sum % 2 == 1 ) {
            sum -= minOdd;
        }
    }

    cout << sum;

    return 0;
}
