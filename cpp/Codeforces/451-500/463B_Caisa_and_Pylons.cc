#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdint.h>


int main(int argc, char **argv) {
    int64_t n = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n;
    }

    int64_t intArr[n + 1];
    int64_t intArrIdx = 0;
    intArr[intArrIdx++] = 0;
    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        while (intArrIdx < n + 1) {
            ss >> intArr[intArrIdx++];
        }
    }

    int64_t dollarsPaid = 0;
    int64_t energy = 0;
    // Logic starts here
    for (int64_t i = 0; i != n; ++i) {
        if (intArr[i + 1] > intArr[i]) {
            if (energy < intArr[i + 1] - intArr[i]) {
                dollarsPaid += (intArr[i + 1] - intArr[i]) - energy;
                energy = 0;
            }

            else {
                energy -= intArr[i + 1] - intArr[i];
            }

        }

        else {
            energy += intArr[i] - intArr[i + 1];
        }
    }

    std::cout << dollarsPaid;

    return 0;
}
