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
    string firstHalf = "";
    string secondHalf = "";
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        string token = "";

        if (getline(ss, token, '|')) {
            firstHalf = token;
        }

        if (getline(ss, token, '|')) {
            secondHalf = token;
        }
    }

    string extraStr = "";
    // Read the second line
    if (getline(cin, extraStr)) {

    }

    // Logic starts here
    if (firstHalf.length() < secondHalf.length()) {
        firstHalf += extraStr;

        if (firstHalf.length() < secondHalf.length()) {
            cout << "Impossible";
        }

        else if (firstHalf.length() > secondHalf.length()) {
            if ((firstHalf.length() + secondHalf.length()) % 2 == 0) {
                string newFirstHalf = firstHalf.substr(0, (firstHalf.length() + secondHalf.length()) / 2);
                string newSecondHalf = secondHalf + firstHalf.substr((firstHalf.length() + secondHalf.length()) / 2, (firstHalf.length() + secondHalf.length()) / 2);
                cout << newFirstHalf << "|" << newSecondHalf;
            }

            else {
                cout << "Impossible";
            }
        }

        else {
            cout << firstHalf << "|" << secondHalf;
        }
    }

    else if (firstHalf.length() > secondHalf.length()) {
        secondHalf += extraStr;

        if (firstHalf.length() > secondHalf.length()) {
            cout << "Impossible";
        }

        else if (firstHalf.length() < secondHalf.length()) {
            if ((firstHalf.length() + secondHalf.length()) % 2 == 0) {
                string newSecondHalf = secondHalf.substr(0, (firstHalf.length() + secondHalf.length()) / 2);
                string newFirstHalf = firstHalf + secondHalf.substr((firstHalf.length() + secondHalf.length()) / 2, (firstHalf.length() + secondHalf.length()) / 2);
                cout << newFirstHalf << "|" << newSecondHalf;
            }

            else {
                cout << "Impossible";
            }
        }

        else {
            cout << firstHalf << "|" << secondHalf;
        }
    }

    else {
        if (extraStr.length() % 2 != 0) {
            cout << "Impossible";
        }

        else {
            cout << firstHalf << extraStr.substr(0, extraStr.length() / 2);
            cout << "|";
            cout << secondHalf << extraStr.substr(extraStr.length() / 2, extraStr.length() / 2);
        }
    }



    return 0;
}
