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

    int intArr[n];
    int intArrIdx = 0;
    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        while (intArrIdx < n) {
            ss >> intArr[intArrIdx++];
        }
    }

    int min = intArr[0];
    int max = intArr[0];
    int amazingCount = 0;
    // Logic starts here
    for (int i = 1; i != n; ++i) {
        if (intArr[i] < min) {
            min = intArr[i];
            ++amazingCount;
        }

        if (intArr[i] > max) {
            max = intArr[i];
            ++amazingCount;
        }
    }

    std::cout << amazingCount;

    return 0;
}
