#include <iostream>
#include <string>
#include <sstream>
#include <vector>


void quickSort(int *arr, int first, int last) {
    if (first >= last) return;

    int left = first;
    int right = last;
    int pivot = arr[(first + last) / 2];

    do {
        while (arr[left] < pivot) ++left;
        while (pivot < arr[right]) --right;

        if (left <= right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }

        // Keep moving forward & backward
        // This will help us end the loop in the case of
        // left == right. Without this extra advancement,
        // when left == right and arr[left] == arr[right] == pivot,
        // the loop will be infinite.
        ++left;
        --right;

        // std::cout << "left: " << left << std::endl;
        // std::cout << "right: " << right << std::endl;
        // std::cout << "arr[left]: " << arr[left] << std::endl;
        // std::cout << "arr[right]: " << arr[right] << std::endl;

    } while (left <= right);

    quickSort(arr, first, right);
    quickSort(arr, left, last);
}


void quickSortReversed(int *arr, int first, int last, int length) {
    if (first >= last) return;

    int left = first;
    int right = last;
    int pivot = arr[(left + right) / 2];

    do {
        while (arr[left] > pivot) ++left;
        while (arr[right] < pivot) --right;

        if (left <= right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            /* std::cout << "Swaping " << arr[left] << " and " << arr[right] << std::endl;
            std::cout << "Swaping indexes " << left << " and " << right << std::endl;
            std::cout << "Pivot " << pivot << std::endl; */

            ++left;
            --right;
        }

    } while (left <= right);

    /* std::cout << "Before Recursion: " << std::endl;
    std::cout << "first: " << first << std::endl;
    std::cout << "right: " << right << std::endl;
    std::cout << "left: " << left << std::endl;
    std::cout << "last: " << last << std::endl;
    std::cout << "Array content: " << std::endl;
    for (unsigned int i = 0; i != length; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl; */
    quickSortReversed(arr, first, right, length);
    quickSortReversed(arr, left, last, length);
}


int sum(int *arr, int length) {
    int arrSum = 0;

    for (unsigned int i = 0; i != length; ++i) {
        arrSum += arr[i];
    }

    return arrSum;
}


int main(int argc, char **argv) {
    /* int arr[10];

    for (unsigned int i = 0; i != sizeof(arr)/sizeof(int); ++i) {
        std::cin >> arr[i];
    }

    for (unsigned int i = 0; i != sizeof(arr)/sizeof(int); ++i) {
        std::cout << arr[i] << std::endl;
    }

    quickSortReversed(arr, 0, 9);

    std::cout << "After Sort: " << std::endl;
    for (unsigned int i = 0; i != sizeof(arr)/sizeof(int); ++i) {
        std::cout << arr[i] << std::endl;
        } */

    long long int n = 0;
    // Read first line
    std::string line;
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> n;
    }

    // Read second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        int coinsArr[n];

        for (unsigned int i = 0; i != n; ++i) {
            ss >> coinsArr[i];
        }

        quickSortReversed(coinsArr, 0, n - 1, n);

        int arrSum = sum(coinsArr, n);
        int curSum = 0;

        int coinsCount = 0;
        for (unsigned int i = 0; i != n; ++i) {
            curSum += coinsArr[i];
            ++coinsCount;

            if (curSum > arrSum - curSum) {
                break;
            }
        }

        /* std::cout << "arrSum: " << arrSum << std::endl;
        std::cout << "curSum: " << curSum << std::endl;
        std::cout << "After Sort: " << std::endl;
        for (unsigned int i = 0; i != sizeof(coinsArr)/sizeof(int); ++i) {
            std::cout << coinsArr[i] << std::endl;
            } */

        std::cout << coinsCount;
    }

    return 0;
}
