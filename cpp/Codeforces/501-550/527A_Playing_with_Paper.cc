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
    Int a = 0;
    Int b = 0;

    cin >> a >> b;

    Int count = 0;

    while ( ( a != 0 ) && ( b != 0 ) ) {

        // // DEBUG
        // cout << "DEBUG ( 0 ): a: " << a << "; b: " << b << endl;
        // // END OF DEBUG

        if ( a > b ) {

            // // DEBUG
            // cout << "DEBUG ( 1 ): a: " << a << "; b: " << b << endl;
            // // END OF DEBUG

            count += a / b;
            a = a % b;
        } else if ( b > a ) {

            // // DEBUG
            // cout << "DEBUG ( 2 ): a: " << a << "; b: " << b << endl;
            // // END OF DEBUG

            count += b / a;
            b = b % a;
        } else {

            // // DEBUG
            // cout << "DEBUG ( 3 ): a: " << a << "; b: " << b << endl;
            // // END OF DEBUG

            break;
        }

        // // DEBUG
        // cout << "DEBUG ( 3 ): a: " << a << "; b: " << b << endl;
        // // END OF DEBUG

    }

    cout << count;

    return 0;
}
