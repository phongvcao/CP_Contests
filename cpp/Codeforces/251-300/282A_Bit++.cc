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
    long long int x = 0;
    while (std::getline(std::cin, line)) {
        if ((line.compare("++X") == 0) || (line.compare("X++") == 0)) {
            ++x;
        }

        else if ((line.compare("--X") == 0) || (line.compare("X--") == 0)) {
            --x;
        }

        --n;
        if (n == 0) break;
    }

    std::cout << x;

    return 0;
}
