#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>
#include <tr1/memory>


int main(int argc, char **argv) {
    long long int n = 0;
    // Read the first line
    std::string line;
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> n;
    }

    // Read the next n lines
    int roomCount = 0;
    int p = 0;
    int q = 0;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> p;
        ss >> q;

        if (q - p >= 2) {
            ++roomCount;
        }

        --n;
        if (n == 0) break;
    }

    std::cout << roomCount;

    return 0;
}
