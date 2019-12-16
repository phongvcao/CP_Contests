#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdint.h>


int64_t binarySearch(int64_t *intArr, int64_t first, int64_t last, int64_t value) {
    int64_t left = first;
    int64_t right = last;
    int64_t middle = (left + right) / 2;
    int64_t pivot = intArr[middle];
    int64_t returnIdx = -1;

    while (right - left > 1) {
        if (value < pivot) {
            right = middle;
            middle = (left + right) / 2;
            pivot = intArr[middle];
        }

        else if (value > pivot) {
            left = middle;
            middle = (left + right) / 2;
            pivot = intArr[middle];
        }

        else {
            return middle;
        }
    }

    if (right - left == 1) {
        if ((value > intArr[left]) && (value <= intArr[right])) {
            returnIdx = right;
        }
    }

    return returnIdx;
}


void testBinarySearch() {
    int64_t intArr[] = { 0, 2, 9, 12, 16, 25 };

    std::cout << binarySearch(intArr, 0, 5, 1);
}


int main(int argc, char **argv) {
    // testBinarySearch();

    int64_t n = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n;
    }

    int64_t aArr[n + 1];
    int64_t aArrIdx = 0;
    aArr[aArrIdx++] = 0;
    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        while (aArrIdx < n + 1) {
            int64_t curNum = 0;

            ss >> curNum;

            aArr[aArrIdx] = curNum;

            if (aArrIdx > 0) {
                aArr[aArrIdx] += aArr[aArrIdx - 1];
            }

            ++aArrIdx;
        }
    }

    int64_t m = 0;
    // Read the third line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> m;
    }

    int64_t qArr[m];
    int64_t qArrIdx = 0;
    // Read the forth line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        while (qArrIdx < m) {
            ss >> qArr[qArrIdx++];
        }
    }

    // Logic starts here
    for (int64_t i = 0; i != m; ++i) {
        std::cout << binarySearch(aArr, 0, n, qArr[i]);

        if (i < m - 1) {
            std::cout << std::endl;
        }
    }


    return 0;
}
