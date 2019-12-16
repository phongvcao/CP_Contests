#include <iostream>
#include <string>
#include <sstream>
#include <vector>


void quickSort(int *intArr, int first, int last) {
    int left = first;
    int right = last;
    int pivot = intArr[(first + last) / 2];

    if (first >= last) return;

    do {
        while (intArr[left] > pivot) ++left;
        while (intArr[right] < pivot) --right;

        if (left <= right) {
            int temp = intArr[left];
            intArr[left] = intArr[right];
            intArr[right] = temp;

            ++left;
            --right;
        }

    } while (left <= right);

    quickSort(intArr, first, right);
    quickSort(intArr, left, last);
}


int main(int argc, char **argv) {
    int n = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n;
    }

    // Read the second line
    int intArr[n];
    int intArrIdx = 0;
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        while (intArrIdx < n) {
            ss >> intArr[intArrIdx++];
        }
    }

    // Logic starts here
    // quickSort(intArr, 0, n - 1);

    int fiveCount = 0;
    for (int i = 0; i != n; ++i) {
        if (intArr[i] == 5) ++fiveCount;
    }

    if (fiveCount >= 9) {
        int fiveLoops = fiveCount / 9;
        int zeroCount = n - fiveCount;

        if (zeroCount > 0) {
            for (int i = 0; i != fiveLoops * 9; ++i) {
                std::cout << 5;
            }

            for (int i = 0; i != zeroCount; ++i) {
                std::cout << 0;
            }
        }

        else {
            std::cout << -1;
        }
    }

    else {
        int zeroCount = n - fiveCount;

        if (zeroCount > 0) {
            std::cout << 0;
        }

        else {
            std::cout << -1;
        }
    }

    return 0;
}
