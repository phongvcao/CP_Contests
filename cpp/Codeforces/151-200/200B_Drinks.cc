#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>


int main(int argc, char **argv) {
    int n = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n;
    }

    double doubleArr[n];
    int doubleArrIdx = 0;
    double sum = 0;
    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        while (doubleArrIdx < n) {
            ss >> doubleArr[doubleArrIdx];
            sum += doubleArr[doubleArrIdx];
            ++doubleArrIdx;
        }
    }

    // Logic starts here
    double result = sum / (100 * n) * 100;
    printf("%.8f", result);

    return 0;
}
