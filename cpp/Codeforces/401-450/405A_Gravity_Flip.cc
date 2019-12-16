#include <iostream>
#include <string>
#include <sstream>
#include <vector>


template <typename T, typename CONT>
inline void copy(CONT& orgList, int orgStart, CONT& destList, int destStart, int length) {
    for (int i = 0; i != length; ++i) {
        destList[destStart++] = orgList[orgStart++];
    }
}


template <typename T, typename CONT>
inline void merge(CONT& list1, CONT& list2, CONT& list3) {
    unsigned int list1Idx = 0;
    unsigned int list2Idx = 0;
    unsigned int list3Idx = 0;

    while ((list1Idx < list1.size()) && (list2Idx < list2.size())) {
        if (list1[list1Idx] <= list2[list2Idx]) {
            list3[list3Idx++] = list1[list1Idx++];
        }

        if (list1[list1Idx] > list2[list2Idx]) {
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
        // Divide the list into 2 halves
        CONT firstHalf(list.size() / 2);
        copy<T, CONT>(list, 0, firstHalf, 0, list.size() / 2);

        CONT secondHalf(list.size() - list.size() / 2);
        copy<T, CONT>(list, list.size() / 2, secondHalf, 0, list.size() - list.size() / 2);

        mergeSort<T, CONT>(firstHalf);
        mergeSort<T, CONT>(secondHalf);
        merge<T, CONT>(firstHalf, secondHalf, list);
    }
}


void testMergeSort() {
    int intArr[] = { 5, 3, 13, 25, 22, 16 };

    std::vector<int> intVector(intArr, intArr + sizeof(intArr) / sizeof(int));

    mergeSort<int, std::vector<int> >(intVector);

    for (unsigned int i = 0; i != intVector.size(); ++i) {
        std::cout << intVector[i] << " ";
    }

    std::cout << std::endl;
}


int main(int argc, char **argv) {
    // testMergeSort();

    unsigned int n = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> n;
    }

    std::vector<unsigned int> intVector;
    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        while (n > 0) {
            unsigned int i = 0;
            ss >> i;
            intVector.push_back(i);

            --n;
        }
    }

    // Logic starts here
    mergeSort<unsigned int, std::vector<unsigned int> >(intVector);

    // Writes result
    for (unsigned int i = 0; i != intVector.size(); ++i) {
        std::cout << intVector[i];

        if (i < intVector.size() - 1) {
            std::cout << " ";
        }
    }

    return 0;
}
