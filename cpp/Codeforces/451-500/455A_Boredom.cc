#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>


using namespace std;
typedef int64_t Int;

Int max(Int a, Int b) {
    return (a > b) ? a : b;
}


int main(int argc, char **argv) {
    Int n = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n;
    }

    unordered_map<Int, Int> freqMap;
    Int freqMapIdx = 0;
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (freqMapIdx < n) {
            Int curNum = 0;
            ss >> curNum;

            unordered_map<Int, Int>::iterator iter = freqMap.find(curNum);

            if (iter != freqMap.end()) {
                ++(iter->second);
            }

            else {
                freqMap.insert(make_pair(curNum, 1));
            }

            ++freqMapIdx;
        }
    }

    // Logic starts here
    Int intArr[10001][2];
    intArr[0][0] = 0;
    intArr[0][1] = 0;
    for (Int i = 1; i < 10001; ++i) {
        unordered_map<Int, Int>::iterator iter = freqMap.find(i);

        if (iter != freqMap.end()) {
            intArr[i][0] = max(intArr[i - 1][0], intArr[i - 1][1]);
            intArr[i][1] = intArr[i - 1][0] + iter->first * iter->second;
        }

        else {
            intArr[i][0] = max(intArr[i - 1][0], intArr[i - 1][1]);
            intArr[i][1] = max(intArr[i - 1][0], intArr[i - 1][1]);
        }
    }

    cout << max(intArr[100000][0], intArr[100000][1]);

    return 0;
}
