#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>


int main(int argc, char **argv) {
    int n = 5;
    int matrixArr[5][5];
    // Read the next n lines
    std::string line = "";
    int i = 0;
    int j = 0;
    int iOne = 0;
    int jOne = 0;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        while (j != n) {
            ss >> matrixArr[i][j];

            if (matrixArr[i][j] == 1) {
                iOne = i;
                jOne = j;
            }
            ++j;
        }

        ++i;
        j = 0;

        if (i == n) break;
    }

    //
    std::cout << (int)(std::abs(2 - iOne) + std::abs(2 - jOne));

    return 0;
}
