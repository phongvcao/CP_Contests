#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    int r = 0;
    int c = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> r >> c;
    }

    char charMatrix[r][c];
    int rowIdx = 0;
    int colIdx = 0;
    int isRowSArr[r];
    int isColSArr[c];
    std::fill_n(isRowSArr, r, false);
    std::fill_n(isColSArr, c, false);

    while (std::getline(std::cin, line)) {
        bool isRowContainsS = false;

        for (unsigned int i = 0; i != line.length(); ++i) {
            charMatrix[rowIdx][i] = line[i];

            if (line[i] == 'S') {
                isColSArr[i] = true;
                isRowContainsS = true;
            }
        }

        isRowSArr[rowIdx] = isRowContainsS;
        ++rowIdx;

        if (rowIdx == r) break;
    }

    int cakesAteCount = 0;
    // Logic starts here
    for (int i = 0; i != r; ++i) {
        if (!isRowSArr[i]) {
            cakesAteCount += c;

            for (int j = 0; j != c; ++j) {
                charMatrix[i][j] = '\0';
            }
        }
    }

    for (int i = 0; i != c; ++i) {
        if (!isColSArr[i]) {
            for (int j = 0; j != r; ++j) {
                if (charMatrix[j][i] == '.') {
                    ++cakesAteCount;
                    charMatrix[j][i] = '\0';
                }
            }
        }
    }

    std::cout << cakesAteCount;

    return 0;
}
