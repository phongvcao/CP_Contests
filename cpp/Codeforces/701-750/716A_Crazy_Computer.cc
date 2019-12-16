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
    UInt n = 0, c = 0;
    string line = "";

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> n >> c;
    }

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        UInt curNum = 0;
        UInt prevNum = 0;
        UInt wordCount = 0;

        if ( n == 1 ) {
            ss >> curNum;
            wordCount = 1;
        } else {
            ss >> prevNum;
            wordCount = 1;
            for ( int i = 1; i < n; ++i ) {
                ss >> curNum;

                if ( curNum - prevNum > c ) {
                    wordCount = 1;
                } else {
                    ++wordCount;
                }
                prevNum = curNum;
            }
        }

        cout << wordCount;
    }

    return 0;
}
