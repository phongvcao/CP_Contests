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

    // Read the next line
    int removalCount = 0;
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        for (unsigned int i = 0; i != line.length() - 1; ++i) {
            if (line[i] == line[i + 1]) {
                ++removalCount;
            }
        }
    }

    std::cout << removalCount;

    return 0;
}
