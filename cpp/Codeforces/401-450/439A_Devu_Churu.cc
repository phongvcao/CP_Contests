#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    int n = 0;
    int d = 0;
    // Read the first line
    std::string line;
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n >> d;
    }

    int intArr[n];
    int intArrIdx = 0;
    int sum = 0;
    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        while (intArrIdx < n) {
            ss >> intArr[intArrIdx];
            sum += intArr[intArrIdx++];
        }
    }

    // Logic starts here
    int devuDuration = sum + (n - 1) * 10;

    if (devuDuration > d) {
        std::cout << -1;
    }

    else {
        int churuBeginDuration = d - devuDuration;
        int churuDuration = churuBeginDuration / 5;
        churuDuration += (n - 1) * 10 / 5;

        std::cout << churuDuration;
    }

    return 0;
}
