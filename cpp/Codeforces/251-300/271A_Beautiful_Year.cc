#include <iostream>
#include <string>
#include <sstream>
#include <vector>


std::string intToString(int n) {
    std::stringstream ss;
    ss << n;
    return ss.str();
}


bool hasDistinctDigits(int n) {
    std::string nStr = intToString(n);

    bool digitsArr[10];
    for (unsigned int i = 0; i != sizeof(digitsArr)/sizeof(bool); ++i) {
        digitsArr[i] = false;
    }

    for (unsigned int i = 0; i != nStr.length(); ++i) {
        if (digitsArr[nStr[i] - '0']) {
            return false;
        }

        digitsArr[nStr[i] - '0'] = true;
    }

    return true;
}


void testHasDistinctDigits() {
    if (hasDistinctDigits(1234)) {
        std::cout << "YES";
    }

    else {
        std::cout << "NO";
    }
}


int main(int argc, char **argv) {
    int y;
    std::cin >> y;

    // testHasDistinctDigits();

    for (unsigned int i = y + 1; i != 10001; ++i) {
        if (hasDistinctDigits(i)) {
            std::cout << i;
            break;
        }
    }


    return 0;
}
