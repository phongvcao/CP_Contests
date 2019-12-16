#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    int n = 0;
    std::cin >> n;

    int dCount = 1;
    for (int i = 0; i != (n + 1) / 2; ++i) {
        // Print left half
        for (int j = 0; j != (n - dCount) / 2; ++j) {
            std::cout << "*";
        }

        // Print middle
        for (int j = 0; j != dCount; ++j) {
            std::cout << "D";
        }

        // Print right
        for (int j = 0; j != (n - dCount) / 2; ++j) {
            std::cout << "*";
        }

        std::cout << std::endl;
        dCount += 2;
    }

    dCount -= 4;
    for (int i = 0; i != n / 2; ++i) {
        // Print left half
        for (int j = 0; j != (n - dCount) / 2; ++j) {
            std::cout << "*";
        }

        // Print middle
        for (int j = 0; j != dCount; ++j) {
            std::cout << "D";
        }

        // Print right
        for (int j = 0; j != (n - dCount) / 2; ++j) {
            std::cout << "*";
        }

        std::cout << std::endl;
        dCount -= 2;
    }

    // Print the upper half
    // (including equator line)


    // Print the lower half

    return 0;
}
