#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>


using namespace std;
typedef int64_t Int;
typedef uint64_t UInt;


Int stringToInt(string str) {
    Int n = 0;

    stringstream ss(str);

    ss >> n;

    return n;
}


string intToString(Int n) {
    stringstream ss;

    ss << n;

    return ss.str();
}


bool isLucky(string numStr) {
    Int lastZeroIdx = 0;
    // Remove leading zeroes
    if (numStr[0] == '0') {
        for (Int i = 0; i != numStr.length(); ++i) {
            if (numStr[i] != '0') {
                lastZeroIdx = i;
            }
        }
    }

    numStr = numStr.substr(lastZeroIdx, numStr.length());

    for (Int i = 0; i != numStr.length(); ++i) {
        if ((numStr[i] != '4') && (numStr[i] != '7')) {
            return false;
        }
    }

    return true;
}


bool isHalfSumsBalance(string numStr) {
    Int lastZeroIdx = 0;
    // Remove leading zeroes
    if (numStr[0] == '0') {
        for (Int i = 0; i != numStr.length(); ++i) {
            if (numStr[i] != '0') {
                lastZeroIdx = i;
            }
        }
    }

    numStr = numStr.substr(lastZeroIdx, numStr.length());

    Int firstHalf = 0;
    Int secondHalf = 0;

    for (Int i = 0; i != numStr.length() / 2; ++i) {
        firstHalf += numStr[i] - '0';
    }

    for (Int i = numStr.length() / 2; i != numStr.length(); ++i) {
        secondHalf += numStr[i] - '0';
    }

    return firstHalf == secondHalf;
}


int main(int argc, char **argv) {
    Int n = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n;
    }

    string numStr = "";
    // Read the second line
    if (getline(cin, numStr)) {

    }

    // Logic starts here
    if ((isLucky(numStr)) && (isHalfSumsBalance(numStr))) {
        cout << "YES";
    }

    else {
        cout << "NO";
    }


    return 0;
}
