#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>


using namespace std;
typedef int64_t Int;


int main(int argc, char **argv) {
    Int n = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n;
    }

    Int exerciseArr[n];
    Int exerciseArrIdx = 0;
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (exerciseArrIdx < n) {
            ss >> exerciseArr[exerciseArrIdx++];
        }
    }

    Int repeatArr[3];
    repeatArr[0] = 0;
    repeatArr[1] = 0;
    repeatArr[2] = 0;
    // Logic starts here
    for (Int i = 0; i != n; ++i) {
        repeatArr[i % 3] += exerciseArr[i];
    }

    int maxRepeatIdx = 0;
    for (Int i = 1; i != 3; ++i) {
        if (repeatArr[i] > repeatArr[maxRepeatIdx]) {
            maxRepeatIdx = i;
        }
    }

    if (maxRepeatIdx == 0) {
        cout << "chest";
    }

    else if (maxRepeatIdx == 1) {
        cout << "biceps";
    }

    else {
        cout << "back";
    }

    return 0;
}
