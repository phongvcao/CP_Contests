#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    int cupsArr[3];
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> cupsArr[0] >> cupsArr[1] >> cupsArr[2];
    }

    int medalsArr[3];
    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> medalsArr[0] >> medalsArr[1] >> medalsArr[2];
    }

    int n;
    // Read the third line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> n;
    }

    // Logic starts here
    int totalCups = cupsArr[0] + cupsArr[1] + cupsArr[2];
    int totalMedals = medalsArr[0] + medalsArr[1] + medalsArr[2];

    int totalCupsShelves = totalCups / 5;
    if (totalCups % 5 != 0) {
        ++totalCupsShelves;
    }

    int totalMedalsShelves = totalMedals / 10;
    if (totalMedals % 10 != 0) {
        ++totalMedalsShelves;
    }

    if (totalCupsShelves + totalMedalsShelves <= n) {
        std::cout << "YES";
    }

    else {
        std::cout << "NO";
    }

    return 0;
}
