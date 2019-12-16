#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdint.h>


template <typename T, typename CONT>
inline void quickSort(CONT& list, T first, T last) {
    T left = first;
    T right = last;
    T pivot = list[(left + right) / 2];

    if (first >= last) return;

    do {
        while (list[left] < pivot) ++left;
        while (list[right] > pivot) --right;

        if (left <= right) {
            T temp = list[left];
            list[left] = list[right];
            list[right] = temp;

            ++left;
            --right;
        }

    } while (left <= right);

    quickSort<T, CONT>(list, first, right);
    quickSort<T, CONT>(list, left, last);
}


template <typename T>
inline T factorial(T n) {
    T result = 1;

    for (T i = 1; i != n + 1; ++i) {
        result *= i;
    }

    return result;
}


inline void testQuickSort() {
    int intArr[] = { 3, 2, 15, 11, 56, 32, 31, 10, 11, 14 };

    std::vector<int> intVector(intArr, intArr + sizeof(intArr) / sizeof(int));

    quickSort<int, std::vector<int> >(intVector, 0, intVector.size() - 1);

    for (unsigned int i = 0; i != intVector.size(); ++i) {
        std::cout << intVector[i] << " ";
    }

    std::cout << std::endl;
}


int main(int argc, char **argv) {
    // testQuickSort();

    int64_t n = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> n;
    }

    std::vector<int64_t> intVector;
    int64_t intVectorIdx = 0;
    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        while (n > 0) {
            int64_t curNum = 0;
            ss >> curNum;
            intVector.push_back(curNum);

            ++intVectorIdx;
            if (intVectorIdx == n) break;
        }
    }

    quickSort<int64_t, std::vector<int64_t> >(intVector, 0, n - 1);

    int64_t min = intVector[0];
    int64_t max = intVector[intVector.size() - 1];
    int64_t minCount = 0;
    int64_t maxCount = 0;

    if (min == max) {
        uint64_t result = n * (n - 1) / 2;
        std::cout << 0 << " " << result;
    }

    else {
        for (int64_t i = 0; intVector[i] == min; ++i) {
            ++minCount;
        }

        for (int64_t i = intVector.size() - 1; intVector[i] == max; --i) {
            ++maxCount;
        }

        std::cout << max - min << " " << maxCount * minCount;
    }

    return 0;
}
