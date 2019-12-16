#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include <cstdlib>
#include <cmath>


using namespace std;
typedef int64_t Int;
typedef uint64_t UInt;


Int sumDigits(Int n) {
    Int sum = 0;

    stringstream ss;
    ss << n;

    string nStr = ss.str();
    for (Int i = 0; i != nStr.length(); ++i) {
        sum += nStr[i] - '0';
    }

    return sum;
}


Int intPow(Int b, Int e) {
    Int result = 1;

    for (Int i = 0; i != e; ++i) {
        result *= b;
    }

    return result;
}


int main(int argc, char **argv) {
    Int a = 0;
    Int b = 0;
    Int c = 0;
    cin >> a >> b >> c;

    vector<Int> answers;
    for (Int i = 0; i != 82; ++i) {
        Int x = b * intPow(i, a) + c;

        if ((x < 1000000000) && (sumDigits(x) == i) && (x > 0)) {
            answers.push_back(x);
        }
    }

    cout << answers.size();
    if (answers.size() > 0) cout << endl;
    for (Int i = 0; i != answers.size(); ++i) {
        cout << answers[i];

        if (i < answers.size() - 1) {
            cout << " ";
        }
    }


    return 0;
}
