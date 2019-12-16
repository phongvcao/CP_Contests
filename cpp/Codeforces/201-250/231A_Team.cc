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
        ss >> n;
    }

    // Read the next n lines
    long long int problemsCount = 0;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        int first = 0;
        int second = 0;
        int third = 0;

        ss >> first >> second >> third;

        if (first + second + third >= 2) {
            ++problemsCount;
        }

        --n;
        if (n == 0) break;
    }

    std::cout << problemsCount;

    return 0;
}
