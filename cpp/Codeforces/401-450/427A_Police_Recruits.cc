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

    int policesCount = 0;
    int crimesCount = 0;
    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        while (n > 0) {
            int curNum = 0;
            ss >> curNum;

            if (curNum > 0) {
                policesCount += curNum;
            }

            else {
                if (policesCount > 0) {
                    --policesCount;
                }

                else {
                    ++crimesCount;
                }
            }
            --n;
        }
    }

    std::cout << crimesCount;

    return 0;
}
