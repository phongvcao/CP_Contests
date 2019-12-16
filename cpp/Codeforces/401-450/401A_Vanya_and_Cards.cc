#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>


int main(int argc, char **argv) {
    int n = 0;
    int x = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n >> x;
    }

    int intArr[n];
    int sum = 0;
    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        for (int i = 0; i != n; ++i) {
            ss >> intArr[i];
            sum += intArr[i];
        }
    }

    sum = (int)std::abs(sum);

    int cardsCount = sum / x;

    if (sum % x != 0) ++cardsCount;

    std::cout << cardsCount;

    return 0;
}
