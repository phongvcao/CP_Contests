#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    int n = 0;
    int c = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n >> c;
    }

    int intArr[n];
    int intArrIdx = 0;
    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        while (intArrIdx < n) {
            ss >> intArr[intArrIdx++];
        }
    }

    // Logic starts here
    int maxKilos = 0;
    for (int i = 0; i != n - 1; ++i) {
        if (intArr[i] - intArr[i + 1] - c > maxKilos) {
            maxKilos = intArr[i] - intArr[i + 1] - c;
        }
    }

    std::cout << maxKilos;

    return 0;
}
