#include <iostream>
#include <string>
#include <sstream>
#include <vector>


template <typename T, typename CONT>
void copyContainer(const CONT& srcList, int srcPos, CONT& destList, int destPos, int length) {
    for (T i = srcPos; i != srcList.size(); ++i) {
        destList[destPos++] = srcList[i];
    }
}


template <typename T, typename CONT>
void merge(CONT& list1, CONT& list2, CONT& list3) {
    T list1Idx = 0;
    T list2Idx = 0;
    T list3Idx = 0;

    while ((list1Idx < list1.size()) && (list2Idx < list2.size())) {
        if (list1[list1Idx] <= list2[list2Idx]) {
            list3[list3Idx++] = list1[list1Idx++];
        }

        else {
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
void mergeSort(CONT& list) {
    if (list.size() > 1) {
        // Create the firstHalf
        CONT firstHalf(list.begin(), list.begin() + list.size() / 2);
        mergeSort<T, CONT>(firstHalf);

        // Create the secondHalf
        CONT secondHalf(list.begin() + list.size() / 2, list.end());
        mergeSort<T, CONT>(secondHalf);

        merge<T, CONT>(firstHalf, secondHalf, list);
    }
}


void testMergeSort() {
    unsigned int intArr[] = { 10, 13, 2, 3, 5, 1, 22, 20, 44, 41, 1000 };
    std::vector<unsigned int> intVector(intArr, intArr + sizeof(intArr)/sizeof(unsigned int));

    mergeSort<unsigned int, std::vector<unsigned int> >(intVector);

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

        unsigned int i = 0;

        while (i < n) {
            unsigned int m = 0;
            ss >> m;
            intVector.push_back(m);
            ++i;
        }
    }

    // Logic starts here
    mergeSort<unsigned int, std::vector<unsigned int> >(intVector);

    unsigned int highestTower = 0;
    unsigned int towerCount = 0;

    if (intVector.size() > 1) {
        for (unsigned int i = 0; i < intVector.size() - 1; ++i) {
            ++towerCount;
            unsigned int firstEle = intVector[i];
            unsigned int curTowerHeight = 1;

            while (intVector[i + 1] == firstEle) {
                ++i;
                ++curTowerHeight;
            }

            if (curTowerHeight > highestTower) {
                highestTower = curTowerHeight;
            }
        }

        if (intVector.size() > 2) {
            if (intVector[intVector.size() - 1] != intVector[intVector.size() - 2]) {
                ++towerCount;
            }
        }

        std::cout << highestTower << " " << towerCount;
    }

    else {
        std::cout << 1 << " " << 1;
    }

    return 0;
}
