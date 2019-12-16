#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>


int stringToInt(std::string str) {
    int returnInt = 0;

    for (unsigned int i = 0; i != str.length(); ++i) {
        int digit = str[i] - '0';
        int power = (int)pow(10, str.length() - 1 - i);
        returnInt += digit * power;
    }

    return returnInt;
}


void copyArr(int *orgArr, int start, int *destArr, int destPos, int length) {
    int destArrPos = destPos;

    for (unsigned int i = start; i != start + length; ++i) {
        destArr[destArrPos] = orgArr[i];
        ++destArrPos;
    }
}


void merge(int *arr1, int *arr2, int *destArr, int arr1Length, int arr2Length) {
    int arr1Idx = 0;
    int arr2Idx = 0;
    int destArrIdx = 0;

    while ((arr1Idx < arr1Length) && (arr2Idx < arr2Length)) {
        if (arr1[arr1Idx] < arr2[arr2Idx]) {
            destArr[destArrIdx++] = arr1[arr1Idx++];
        }

        else {
            destArr[destArrIdx++] = arr2[arr2Idx++];
        }
    }

    while (arr1Idx < arr1Length) {
        destArr[destArrIdx++] = arr1[arr1Idx++];
    }

    while (arr2Idx < arr2Length) {
        destArr[destArrIdx++] = arr2[arr2Idx++];
    }
}


void mergeSort(int *arr, int arrLength) {
    if (arrLength > 1) {
        int firstHalf[arrLength / 2];
        copyArr(arr, 0, firstHalf, 0, arrLength / 2);

        int secondHalfLength = arrLength - arrLength / 2;
        int secondHalf[secondHalfLength];
        copyArr(arr, arrLength / 2, secondHalf, 0, arrLength - arrLength / 2);

        mergeSort(firstHalf, arrLength / 2);
        mergeSort(secondHalf, arrLength - arrLength / 2);

        // Merge first with secondHalf
        merge(firstHalf, secondHalf, arr, arrLength / 2, arrLength - arrLength / 2);
    }
}


int main(int argc, char **argv) {
        // Read the first line
    std::string line;
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        int arrLength = 0;
        for (unsigned int i = 0; i != line.length(); ++i) {
            if (line[i] == '+') {
                ++arrLength;
            }
        }
        ++arrLength;

        int intArr[arrLength];
        int intArrIdx = 0;
        std::string token;
        while (std::getline(ss, token, '+')) {
            intArr[intArrIdx++] = stringToInt(token);

            if (intArrIdx == arrLength) break;
        }

        mergeSort(intArr, arrLength);

        for (unsigned int i = 0; i != arrLength; ++i) {
            std::cout << intArr[i];

            if (i != arrLength - 1) {
                std::cout << "+";
            }
        }
    }

    return 0;
}
