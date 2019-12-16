#include <iostream>
#include <string>
#include <sstream>
#include <vector>


void printArr(int *intArr, int length) {
    for (int i = 0; i != length; ++i) {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;
}


void quickSort(int *intArr, int first, int last, int length) {
    int left = first;
    int right = last;
    int pivot = intArr[(left + right) / 2];

    if (first >= last) return;

    do {
        while (intArr[left] < pivot) ++left;
        while (intArr[right] > pivot) --right;

        if (left <= right) {
            int temp = intArr[left];
            intArr[left] = intArr[right];
            intArr[right] = temp;

            ++left;
            --right;

            // printArr(intArr, length);
        }
    } while (left <= right);

    quickSort(intArr, first, right, length);
    quickSort(intArr, left, last, length);
}


void testQuickSort() {
    int n = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> n;
    }

    int intArr[n];
    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        int intArrIdx = 0;
        while (intArrIdx != n) {
            ss >> intArr[intArrIdx++];
        }
    }

    // Logic starts here
    quickSort(intArr, 0, n - 1, n);

    // Print everything
    printArr(intArr, n);
}


int main(int argc, char **argv) {
    // testQuickSort();

    int n = 0;
    int m = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> n >> m;
    }

    int intArr[m];
    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        int intArrIdx = 0;
        while (intArrIdx != m) {
            ss >> intArr[intArrIdx++];
        }
    }

    // Logic starts here
    quickSort(intArr, 0, m - 1, m);

    // printArr(intArr, m);
    int minDistance = -1;
    for (int i = 0; i + n - 1 < m; ++i) {
        if ((minDistance == -1) || (intArr[i + n - 1] - intArr[i] < minDistance)) {
            minDistance = intArr[i + n - 1] - intArr[i];
        }
    }

    std::cout << minDistance;

    return 0;
}
