#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdint.h>
#include <map>


int64_t isContain(int64_t *intArr, int64_t length, int64_t value) {
    int64_t left = 0;
    int64_t right = length - 1;
    int64_t middle = (left + right) / 2;
    int64_t pivot = intArr[middle];

    // Perform binary search
    while (right - left > 1) {
        // If the value belongs to halfLeft
        if (value < pivot) {
            right = middle;
            middle = (left + right) / 2;
            pivot = intArr[middle];
        }

        // If the value belongs to halfRight
        else if (value > pivot){
            left = middle;
            middle = (left + right) / 2;
            pivot = intArr[middle];
        }

        // If found
        else {
            return middle;
        }
    }

    return -1;
}


void testIsContain() {
    int64_t intArr[] = { 1, 2, 3, 4, 5, 10 };

    std::cout << isContain(intArr, 5, 4);
}


int main(int argc, char **argv) {
    // testIsContain();

    int64_t n = 0;
    int64_t d = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n >> d;
    }

    int64_t intArr[n];
    int64_t intArrIdx = 0;
    // Read the next n lines
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> intArr[intArrIdx++];

        if (intArrIdx == n) break;
    }

    // Logic starts here



    return 0;
}
