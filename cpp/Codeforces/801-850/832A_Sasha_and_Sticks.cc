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
    Int n = 0;
    Int k = 0;
    
    cin >> n >> k;

    if ( ( n / k ) % 2 == 0 ) {
        cout << "NO";
    } else {
        cout << "YES";
    }

    return 0;
}
