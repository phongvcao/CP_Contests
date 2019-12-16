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

    char charMatrix[n][n];
    int rowIdx = 0;
    int colIdx = 0;
    // Read the next n lines
    while (std::getline(std::cin, line)) {
        for (unsigned int i = 0; i != line.length(); ++i) {
            charMatrix[rowIdx][i] = line[i];
        }

        ++rowIdx;

        if (rowIdx == n) break;
    }

    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            int adjacentOCount = 0;

            // Inspect upper cell
            if (i - 1 >= 0) {
                if (charMatrix[i - 1][j] == 'o') {
                    ++adjacentOCount;
                }
            }

            // Inspect lower cell
            if (i + 1 <= n - 1) {
                if (charMatrix[i + 1][j] == 'o') {
                    ++adjacentOCount;
                }
            }

            // Inspect left cell
            if (j - 1 >= 0) {
                if (charMatrix[i][j - 1] == 'o') {
                    ++adjacentOCount;
                }
            }

            // Inspect right cell
            if (j + 1 <= n - 1) {
                if (charMatrix[i][j + 1] == 'o') {
                    ++adjacentOCount;
                }
            }

            if (adjacentOCount % 2 == 1) {
                std::cout << "NO";
                return 0;
            }
        }
    }

    std::cout << "YES";

    return 0;
}
