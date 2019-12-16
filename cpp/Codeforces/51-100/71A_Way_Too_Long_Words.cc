#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    long long int n = 0;

    // Read the first line
    std::string line;
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        long long int curInt = 0;

        if (ss >> curInt) {
            n = curInt;
        }
    }

    // std::cout << n << std::endl;

    std::vector<std::string> strVector;
    while (std::getline(std::cin, line)) {
        strVector.push_back(line);

        --n;
        if (n == 0) break;
    }

    /* for (unsigned int i = 0; i != strVector.size(); ++i) {
       std::cout << strVector[i] << std::endl;
       } */

    for (unsigned int i = 0; i != strVector.size(); ++i) {
        if (strVector[i].length() > 10) {
            std::cout << strVector[i][0];
            std::cout << strVector[i].length() - 2;
            std::cout << strVector[i][strVector[i].length() - 1];
            std::cout << std::endl;
        }

        else {
            std::cout << strVector[i] << std::endl;
        }
    }

    return 0;
}
