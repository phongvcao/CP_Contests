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

    quickSort(intArr, left, last);
    quickSort(intArr, first, right);
}


int main(int argc, char **argv) {
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

        while (intArrIdx < n) {
            ss >> intArr[intArrIdx++];
        }
    }

    // Logic starts here
    quickSort(intArr, 0, n - 1);

    int teamsCount = 0;
    for (int i = 2; i < n; i += 3) {
        if (intArr[i] + k <= 5) {
            ++teamsCount;
        }
    }

    std::cout << teamsCount;

    return 0;
}
