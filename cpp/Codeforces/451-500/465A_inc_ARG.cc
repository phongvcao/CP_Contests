#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    int n = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n;
    }

    std::string numStr = "";
    // Read the second line
    if (std::getline(std::cin, line)) {
        numStr = line;
    }

    // Logic starts here
    int carryIn = 1;
    int lastIdx = 0;
    for (unsigned int i = 0; i != numStr.length(); ++i) {
        if (numStr[i] - '0' == 1) {
            carryIn = 1;
        }

        else {
            carryIn = 0;
            lastIdx = i;
            break;
        }

        lastIdx = i;
    }

    std::cout << lastIdx + 1;

    return 0;
}
