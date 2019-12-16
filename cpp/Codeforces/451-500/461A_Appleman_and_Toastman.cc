#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdint.h>


template <typename T, typename CONT>
inline void copy(CONT& orgList, uint64_t orgStart, CONT& destList, uint64_t destStart, uint64_t length) {
    uint64_t destStartIdx = destStart;
    while (destStartIdx < destStart + length) {
        destList[destStartIdx++] = orgList[orgStart++];
    }
}


template <typename T, typename CONT>
inline void merge(CONT& list1, CONT& list2, CONT& list3) {
    uint64_t list1Idx = 0;
    uint64_t list2Idx = 0;
    uint64_t list3Idx = 0;

    while ((list1Idx < list1.size()) && (list2Idx < list2.size())) {
        if (list1[list1Idx] >= list2[list2Idx]) {
            list3[list3Idx++] = list1[list1Idx++];
        }

        else if (list1[list1Idx] < list2[list2Idx]) {
            list3[list3Idx++] = list2[list2Idx++];
        }
    }

    while (list1Idx < list1.size()) {
        list3[list3Idx++] = list1[list1Idx++];
    }

    while (list2Idx < list2.size()) {
        list3[list3Idx++] = list2[list2Idx++];
    }
}


template <typename T, typename CONT>
inline void mergeSort(CONT& list) {
    if (list.size() > 1) {
        // Divide the array into first & second halves
        CONT firstHalf(list.size() / 2);
        copy<T, CONT>(list, 0, firstHalf, 0, list.size() / 2);

        CONT secondHalf(list.size() - list.size() / 2);
        copy<T, CONT>(list, list.size() / 2, secondHalf, 0, list.size() - list.size() / 2);

        // Now start merging & sorting them
        mergeSort<T, CONT>(firstHalf);
        mergeSort<T, CONT>(secondHalf);
        merge<T, CONT>(firstHalf, secondHalf, list);
    }
}


void testMergeSort() {
    uint64_t intArr[] = { 16, 2, 77, 29, 3, 5, 1, 22 };
    std::vector<uint64_t> intVector(intArr, intArr + sizeof(intArr) / sizeof(uint64_t));

    mergeSort<uint64_t, std::vector<uint64_t> >(intVector);

    for (uint64_t i = 0; i != intVector.size(); ++i) {
        std::cout << intVector[i] << " ";
    }

    std::cout << std::endl;
}


int main(int argc, char **argv) {
    // testMergeSort();

    uint64_t n = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> n;
    }

    std::vector<uint64_t> intVector;
    std::vector<uint64_t> sumVector;
    uint64_t sum = 0;
    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        while (n > 0) {
            uint64_t num = 0;
            ss >> num;
            intVector.push_back(num);
            sum += num;

            --n;
        }
    }

    // Logic starts here
    mergeSort<uint64_t, std::vector<uint64_t> >(intVector);

    uint64_t curSum = 0;
    for (uint64_t i = 0; i != intVector.size(); ++i) {
        curSum += intVector[i];
        sumVector.push_back(curSum);
    }

    uint64_t maxSum = sum;
    for (uint64_t i = 1; i != sumVector.size(); ++i) {
        maxSum += sumVector[i];
    }

    std::cout << maxSum;

    return 0;
}
