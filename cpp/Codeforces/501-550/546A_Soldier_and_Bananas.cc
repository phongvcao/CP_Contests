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
    Int k = 0, n = 0, w = 0;
    cin >> k >> n >> w;

    if (w == 0) {
        cout << 0;
    } 
    
    else {
        Int sum = 0;
        for (Int i = 1; i <= w; ++i) {
            sum += i * k;
        }

        if (sum < n) {
            cout << 0;
        }

        else {
            cout << sum - n;
        }
    }

    return 0;
}
