#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

int main(int argc, char **argv) {
    unsigned int t = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> t;
    }

    // Read the next t lines
    unsigned int intArr[t];
    unsigned int intArrIdx = 0;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> intArr[intArrIdx++];

        if (intArrIdx == t) break;
    }

    // Logic starts here
    for (unsigned int i = 0; i != t; ++i) {
        /* int threeEdges = 3 * intArr[i] - 1 * 180;
        int fourEdges = 4 * intArr[i] - 2 * 180;
        threeEdges = (int)std::abs(threeEdges);
        fourEdges = (int)std::abs(fourEdges);

        if ((fourEdges == 0) || (threeEdges == 0) || ((fourEdges < threeEdges)
                        && (intArr[i] % (threeEdges - fourEdges) == 0))) {
            std::cout << "YES" << std::endl;
        }

        else {
            std::cout << "NO" << std::endl;
            } */

        int exteriorAngle = 180 - intArr[i];

        if (360 % exteriorAngle != 0) {
            std::cout << "NO" << std::endl;
        }

        else {
            std::cout << "YES" << std::endl;
        }
    }

    return 0;
}
