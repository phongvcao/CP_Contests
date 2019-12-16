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

    bool levelsArr[n + 1];
    levelsArr[0] = true;
    for (int i = 1; i != n + 1; ++i) {
        levelsArr[i] = false;
    }

    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        int levelsXSize = 0;
        ss >> levelsXSize;

        for (int i = 0; i != levelsXSize; ++i) {
            int a = 0;
            ss >> a;
            levelsArr[a] = true;
        }
    }

    // Read the third line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        int levelsYSize = 0;
        ss >> levelsYSize;

        for (int i = 0; i != levelsYSize; ++i) {
            int a = 0;
            ss >> a;
            levelsArr[a] = true;
        }
    }

    // Now the logic
    bool isPassed = true;
    for (int i = 0; i != n + 1; ++i) {
        if (!levelsArr[i]) {
            isPassed = false;
        }
    }

    if (!isPassed) {
        std::cout << "Oh, my keyboard!";
    }

    else {
        std::cout << "I become the guy.";
    }

    return 0;
}
