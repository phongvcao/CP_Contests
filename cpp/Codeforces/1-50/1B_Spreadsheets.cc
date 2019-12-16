#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>


bool isAlphabet(char c) {
    if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z'))) {
        return true;
    }

    return false;
}


// The first type contains a consecutive sequence of letters and then a
// consecutive sequence of digits without intefering
bool isFirstType(std::string str) {
    int startIdx = 0;

    while (isAlphabet(str[startIdx])) ++startIdx;

    while ((startIdx < str.length()) && (!isAlphabet(str[startIdx]))) ++startIdx;

    if (startIdx == str.length()) return true;

    return false;
}


void testIsFirstType() {
    std::string strArr[] = { "BC23", "R23C55", "R2", "RC23" };

    for (int i = 0; i != 4; ++i) {
        if (isFirstType(strArr[i])) {
            std::cout << strArr[i] << " is first-type" << std::endl;
        }

        else {
            std::cout << strArr[i] << " is second-type" << std::endl;
        }
    }
}


int intPow(int b, int e) {
    return (e == 0) ? 1 : b * intPow(b, e - 1);
}


std::string toSecondType(std::string str) {
    int lastLetterIdx = 0;
    int col = 0;
    int row = 0;
    int firstNumberIdx = 0;
    int multiplier = 10;

    while (isAlphabet(str[lastLetterIdx])) ++lastLetterIdx;
    firstNumberIdx = lastLetterIdx;
    --lastLetterIdx;

    while (lastLetterIdx >= 0) {
        int digit = (str[lastLetterIdx] - 'A' + 1) * intPow(26, firstNumberIdx - lastLetterIdx - 1);
        col += digit;
        --lastLetterIdx;
    }

    for (int i = str.length() - 1; i >= firstNumberIdx; --i) {
        row += intPow(10, str.length() - i - 1) * (str[i] - '0');
    }

    std::stringstream ss;

    ss << "R" << row << "C" << col;

    return ss.str();
}


void testToSecondType() {
    std::cout << toSecondType("BC23") << std::endl;
}


std::string toBase26(int n) {
    int quotient = n;
    int remainder = n % 26;
    std::string returnStr = "";

    do {
        remainder = quotient % 26;
        quotient = quotient / 26;

        if (remainder >= 1) --remainder;
        else {
            remainder = 25;
            --quotient;
        }

        char c = remainder + 'A';

        std::stringstream ss;

        ss << c;

        returnStr = ss.str() + returnStr;
    } while (quotient != 0);

    return returnStr;
}

// Error here
// toBase26 has error
void testToBase26() {
    std::cout << toBase26(494) << std::endl;;
}


std::string toFirstType(std::string str) {
    int row = 0;
    int col = 0;
    int rLetterIdx = 0;
    int cLetterIdx = 0;

    for (unsigned int i = 0; i != str.length(); ++i) {
        if (str[i] == 'C') {
            cLetterIdx = i;
        }
    }

    for (unsigned int i = str.length() - 1; i > cLetterIdx; --i) {
        col += intPow(10, str.length() - i - 1) * (str[i] - '0');
    }

    for (unsigned int i = cLetterIdx - 1; i > 0; --i) {
        row += intPow(10, cLetterIdx - i - 1) * (str[i] - '0');
    }

    std::stringstream ss;

    ss << row;

    // Now convert to base-26 format
    return toBase26(col) + ss.str();
}


void testToFirstType() {
    std::cout << toFirstType("R23C55") << std::endl;
}


int main(int argc, char **argv) {
    int n = 0;

    // testIsFirstType();
    // testToSecondType();
    // testToBase26();
    // testToFirstType();

    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n;
    }

    std::vector<std::string> outputsArr;
    // Read the next n lines
    while (std::getline(std::cin, line)) {
        if (isFirstType(line)) {
            outputsArr.push_back(toSecondType(line));
        }

        else {
            outputsArr.push_back(toFirstType(line));
        }

        --n;

        if (n == 0) break;
    }

    for (unsigned int i = 0; i != outputsArr.size(); ++i) {
        std::cout << outputsArr[i];

        if (i < outputsArr.size() - 1) {
            std::cout << std::endl;
        }
    }

    return 0;
}
