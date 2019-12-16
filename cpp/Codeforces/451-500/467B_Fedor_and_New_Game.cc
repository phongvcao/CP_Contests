#include <iostream>
#include <string>
#include <sstream>
#include <vector>


std::string toBinary(int n, int width) {
    std::string binNum = "";

    int quotient = n;
    int remainder = 0;

    do {
        remainder = quotient % 2;
        quotient = quotient / 2;

        std::stringstream ss;

        ss << remainder;

        binNum = ss.str() + binNum;
    } while (quotient > 0);

    // Left-padding with 0
    if (binNum.length() < width) {
        int loops = width - binNum.length();

        for (int i = 0; i != loops; ++i) {
            binNum = "0" + binNum;
        }
    }

    return binNum;
}


void testToBinary() {
    std::cout << toBinary(8, 10) << std::endl;
}


bool isFriends(std::string binNum1, std::string binNum2, int k) {
    if (binNum1.length() != binNum2.length()) return false;
    int diffCount = 0;

    for (int i = 0; i != binNum1.length(); ++i) {
        if (binNum1[i] != binNum2[i]) {
            ++diffCount;
        }
    }

    return diffCount <= k;
}


int intPow(int b, int e) {
    int result = 1;

    for (int i = 0; i != e; ++i) {
        result *= b;
    }

    return result;
}


int testIntPow() {
    std::cout << intPow(8, 2) << std::endl;
}


int main(int argc, char **argv) {
    // testToBinary();
    // testIntPow();

    int n = 0;
    int m = 0;
    int k = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n >> m >> k;
    }

    int intArr[m + 1];
    int intArrIdx = 0;
    // Read the next m + 1 lines
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> intArr[intArrIdx++];

        if (intArrIdx == m + 1) break;
    }

    int friendsCount = 0;
    // Logic starts here
    std::string fedorStr = toBinary(intArr[m], n);
    for (int i = m - 1; i >= 0; --i) {
        if (isFriends(fedorStr, toBinary(intArr[i], n), k)) {
            ++friendsCount;
        }
    }

    std::cout << friendsCount;

    return 0;
}
