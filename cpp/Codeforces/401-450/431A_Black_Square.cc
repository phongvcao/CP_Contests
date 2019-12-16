#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    int aArr[4] = { 0, 0, 0, 0 };
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> aArr[0] >> aArr[1] >> aArr[2] >> aArr[3];
    }

    int sum = 0;
    // Read the second line
    if (std::getline(std::cin, line)) {
        for (unsigned int i = 0; i != line.length(); ++i) {
            sum += aArr[line[i] - '0' - 1];
        }
    }

    std::cout << sum;

    return 0;
}
