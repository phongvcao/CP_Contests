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


int main(int argc, char **argv) {

    UInt n1 = 0, n2 = 0, k1 = 0, k2 = 0;

    cin >> n1 >> n2 >> k1 >> k2;

    if ( n1 > n2 ) {
        cout << "First";
    }

    else {
        cout << "Second";
    }

    return 0;
}
