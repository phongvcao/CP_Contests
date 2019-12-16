#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    int a = 0;
    int b = 0;
    int c = 0;

    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> a;
    }

    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> b;
    }

    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> c;
    }

    // Logic starts here
    int intArr[6] = { a + b + c, a + b * c, a * b + c, (a + b) * c, a * (b + c), a * b * c };

    int max = 0;
    for (int i = 0; i != 6; ++i) {
        if (intArr[i] > max) {
            max = intArr[i];
        }
    }

    std::cout << max;

    return 0;
}
