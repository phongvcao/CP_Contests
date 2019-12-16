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

    Int a = 0, b = 0;
    cin >> a >> b;

    Int diffSocks = a <= b ? a : b;
    Int sameSocks = (int)abs( ( a - b ) / 2 );

    cout << diffSocks << " " << sameSocks;

    return 0;
}

