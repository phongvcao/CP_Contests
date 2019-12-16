#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include <cmath>


using namespace std;
typedef int64_t Int;


Int stringToInt(string str) {
    Int result = 0;

    for (Int i = 0; i != str.length(); ++i) {
        result += (str[i] - '0') * (Int)pow(10, str.length() - 1 - i);
    }

    return result;
}


void testStringToInt() {
    cout << stringToInt("110") << endl;
}


string intToString(Int n) {
    stringstream ss;
    ss << n;

    string resultStr = ss.str();

    return (resultStr.length() == 1) ? "0" + resultStr : resultStr;
}


string subtractTime(string time, string duration) {
    string resultStr = "";

    Int timeHours = stringToInt(time.substr(0, 2));
    Int timeMinutes = stringToInt(time.substr(3, 5));

    Int durHours = stringToInt(duration.substr(0, 2));
    Int durMinutes = stringToInt(duration.substr(3, 5));

    Int carryIn = 0;

    if (timeMinutes - durMinutes < 0) {
        resultStr += ":" + intToString(60 + (timeMinutes - durMinutes));
        carryIn = 1;
    }

    else {
        resultStr += ":" + intToString(timeMinutes - durMinutes);
    }

    if (timeHours - durHours - carryIn < 0) {
        resultStr = intToString(24 + (timeHours - durHours - carryIn)) + resultStr;
    }

    else {
        resultStr = intToString(timeHours - durHours - carryIn) + resultStr;
    }

    return resultStr;
}


void testSubtractTime() {
    cout << subtractTime("05:50", "05:44") << endl;
    cout << subtractTime("00:00", "01:00") << endl;
    cout << subtractTime("00:01", "00:00") << endl;
}


int main(int argc, char **argv) {
    // testStringToInt();
    // testSubtractTime();

    string s = "";
    // Read the first line
    if (getline(cin, s)) {

    }

    string t = "";
    // Read the second line
    if (getline(cin, t)) {

    }

    cout << subtractTime(s, t);

    return 0;
}
