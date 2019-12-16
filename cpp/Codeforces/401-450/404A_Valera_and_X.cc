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
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n;
    }

    UInt lineIdx = 0;
    char edgeChar = '\0';
    char fillChar = '\0';
    string answer = "YES";
    // Read the next n lines
    while (getline(cin, line)) {
        if (edgeChar == '\0') edgeChar = line[0];
        if (fillChar == '\0') fillChar = line[1];

        if (edgeChar == fillChar) {
            answer = "NO";
        }

        if ((line[lineIdx] != edgeChar) || (line[n - 1- lineIdx] != edgeChar)) {
            answer = "NO";
        }

        string newLine = line;
        if (lineIdx != n / 2) {
            UInt smallerLineIdx = (lineIdx > n - 1 - lineIdx) ? n - 1 - lineIdx : lineIdx;
            UInt largerLineIdx = (lineIdx > n - 1 - lineIdx) ? lineIdx : n - 1 - lineIdx;

            string oneThird = newLine.substr(0, smallerLineIdx);
            string secondThird = newLine.substr(smallerLineIdx + 1, largerLineIdx - smallerLineIdx - 1);
            string thirdThird = newLine.substr(largerLineIdx + 1);

            newLine = oneThird + secondThird + thirdThird;
        }

        else {
            newLine = newLine.substr(0, n / 2) + newLine.substr(n / 2 + 1);
        }

        for (UInt i = 0; i < newLine.length(); ++i) {
            if (newLine[i] != fillChar) {
                answer = "NO";
            }
        }


        ++lineIdx;
        if (lineIdx == n) break;
    }

    cout << answer;

    return 0;
}
