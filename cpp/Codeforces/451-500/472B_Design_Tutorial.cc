#include <iostream>
#include <string>
#include <sstream>
#include <vector>


void quickSort(int *intArr, int first, int last) {
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
        }

    } while (left <= right);

    quickSort(intArr, first, right);
    quickSort(intArr, left, last);
}


void testQuickSort() {
    int intArr[] = { 10, 3, 44, 2, 11, 10, 21, 12, 5, 6, 7 };

    quickSort(intArr, 0, sizeof(intArr)/sizeof(int) - 1);

    for (unsigned int i = 0; i != sizeof(intArr)/sizeof(int); ++i) {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;
}


int main(int argc, char **argv) {
    // testQuickSort();

    int n = 0;
    int k = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> n >> k;
    }

    int intArr[n];
    int intArrIdx = 0;
    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        while (intArrIdx != n) {
            ss >> intArr[intArrIdx++];
        }
    }

    // Logic starts here
    quickSort(intArr, 0, n - 1);

    intArrIdx = 0;
    int minimalTime = 0;

    // Special Case: n <= k
    if (n <= k) {
        intArrIdx += k;
        minimalTime += 2 * (intArr[n - 1] - 1);
        std::cout << minimalTime;
        return 0;
    }

    // Reverse looping to add times in
    for (int i = n - 1; i >= 0; i -= k) {
        minimalTime += 2 * (intArr[i] - 1);
    }

    std::cout << minimalTime;

    return 0;
}
