#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdint.h>


template <typename T>
inline T stringToType(std::string valueStr) {
    std::stringstream ss(valueStr);
    T value;
    ss >> value;

    return value;
}


int main(int argc, char **argv) {
    std::string numStr = "";
    if (std::getline(std::cin, numStr)) {

    }

    // Logic starts here
    if (numStr[0] == '-') {
        int64_t lastDigitRemovedNum = stringToType<int64_t>(numStr.substr(0, numStr.length() - 1));
        int64_t secondToLastDigitRemovedNum = stringToType<int64_t>(numStr.substr(0, numStr.length() - 2) + numStr[numStr.length() - 1]);

        if (lastDigitRemovedNum < secondToLastDigitRemovedNum) {
            std::cout << secondToLastDigitRemovedNum;
        }

        else {
            std::cout << lastDigitRemovedNum;
        }
    }

    else {
        std::cout << numStr;
    }

    return 0;
}
