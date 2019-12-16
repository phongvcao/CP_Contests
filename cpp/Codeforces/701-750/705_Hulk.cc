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
    UInt n = 0;
    cin >> n;

    string begin = "I hate";
    string love = "that I love";
    string hate = "that I hate";
    string end = " it";

    cout << begin;
    for ( UInt i = 1; i < n; ++i ) {
        cout << " ";
        if ( i % 2 == 1 ) {
            cout << love;
        } else {
            cout << hate;
        }
    }
    cout << end;

    return 0;
}
