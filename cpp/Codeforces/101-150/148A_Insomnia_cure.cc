#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    // Read the lines
    std::string line;
    long long int lineNumArr[] = { 0, 0, 0, 0, 0 };
    int idx = 0;

    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> lineNumArr[idx++];

        if (idx == 5) break;
    }

    bool damagedArr[lineNumArr[4]];
    for (unsigned int i = 0; i != sizeof(damagedArr)/sizeof(bool); ++i) {
        damagedArr[i] = false;
    }

    for (unsigned int i = 0; i != sizeof(lineNumArr)/sizeof(long long int) - 1; ++i) {
        if (sizeof(damagedArr)/sizeof(bool) >= lineNumArr[i]) {
            for (unsigned int j = lineNumArr[i] - 1; j <= sizeof(damagedArr)/sizeof(bool); j += lineNumArr[i]) {
                damagedArr[j] = true;
            }
        }
    }

    // Count the number of damagedDragons
    long long int damagedCount = 0;
    for (unsigned int i = 0; i != sizeof(damagedArr)/sizeof(bool); ++i) {
        if (damagedArr[i]) ++damagedCount;
    }

    std::cout << damagedCount;

    return 0;
}
