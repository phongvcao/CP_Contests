#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include <cstdlib>


using namespace std;
typedef int64_t Int;
typedef uint64_t UInt;


int main(int argc, char **argv) {
    UInt n = 0;
    UInt m = 0;

    cin >> n >> m;

    UInt sumN = (n / 2 * 2 + 1) * (n / 2);

    if (n % 2 == 1) sumN += n;

    UInt quotient = m / sumN;
    UInt remainder = m % sumN;

    for (UInt i = 1; i < n + 1; ++i) {
        if (remainder >= i) {
            remainder -= i;
        }

        else {
            break;
        }
    }

    cout << remainder;

    return 0;
}
