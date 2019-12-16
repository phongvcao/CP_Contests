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


Int absValue( Int n ) {
    if ( n < 0 ) {
        return 0 - n;
    }
    return n;
}


int main(int argc, char **argv) {
    Int n = 0;
    Int a = 0;
    Int b = 0;

    cin >> n >> a >> b;

    Int result = 0;

    if ( n == 1 ) {
        result = 1;
    } else {

        if ( b > 0 ) {
            // // DEBUG
            // cout << "FIRST DEBUG ( 0 )" << endl;
            // // END OF DEBUG

            result = ( a + b ) % n;
        } else if ( b < 0 ) {
            // // DEBUG
            // cout << "FIRST DEBUG ( 1 )" << endl;
            // cout << b % n << endl;
            // // END OF DEBUG

            result = ( n + ( a + b ) % n ) % n;

            if ( result == 0 ) {
                result = n;
            }
        } else {
            // // DEBUG
            // cout << "FIRST DEBUG ( 2 )" << endl;
            // // END OF DEBUG

            result = a;
        }
    }

    if ( result == 0 ) {
        cout << n;
    } else {
        cout << result;
    }

    return 0;
}
