#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdint.h>


int main(int argc, char **argv) {
    int64_t n = 0;
    int64_t k = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n >> k;
    }

    int64_t lineIdx = 0;
    int64_t maxJoyValue = -1;
    bool justStarted = true;
    // Read the next n lines
    // Logic also starts here
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        int64_t f = 0;
        int64_t t = 0;
        int64_t joyForThisLunch = 0;

        ss >> f >> t;

        if (t > k) {
            joyForThisLunch = f - (t - k);
        }

        else {
            joyForThisLunch = f;
        }

        if ((joyForThisLunch > maxJoyValue) || (justStarted)) {
            maxJoyValue = joyForThisLunch;
            justStarted = false;
        }

        ++lineIdx;

        if (lineIdx == n) break;
    }

    std::cout << maxJoyValue;

    return 0;
}
