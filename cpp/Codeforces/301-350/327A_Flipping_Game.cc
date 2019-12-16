#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>


std::string indexesToString(int first, int last) {
    std::stringstream ss;

    ss << first << last;

    return ss.str();
}


int countFlippedOnes(int *intArr, int first, int last, int length) {
    int flippedOnesCount = 0;

    for (int i = first; i != last + 1; ++i) {
        if (intArr[i] == 0) {
            ++flippedOnesCount;
        }
    }

    for (int i = 0; i != first; ++i) {
        if (intArr[i] == 1) {
            ++flippedOnesCount;
        }
    }

    for (int i = last + 1; i != length; ++i) {
        if (intArr[i] == 1) {
            ++flippedOnesCount;
        }
    }

    return flippedOnesCount;
}


void calculatePossibleFlippedOnes(int *intArr, int left, int right, int length, std::map<std::string, int>& flippedOnesMap) {
    if (left > right) return;

    std::string indexesStr = indexesToString(left, right);
    std::map<std::string, int>::iterator iter = flippedOnesMap.find(indexesStr);

    if (iter == flippedOnesMap.end()) {
        flippedOnesMap.insert(std::pair<std::string, int>(indexesStr, countFlippedOnes(intArr, left, right, length)));
    }

    else {
        return;
    }

    calculatePossibleFlippedOnes(intArr, left + 1, right, length, flippedOnesMap);
    calculatePossibleFlippedOnes(intArr, left, right - 1, length, flippedOnesMap);
}


void testCalculatePossibleFlippedOnes() {
    int intArr[] = { 1, 1, 1, 1, 1 };

    std::map<std::string, int> flippedOnesMap;

    calculatePossibleFlippedOnes(intArr, 0, 4, 5, flippedOnesMap);

    for (std::map<std::string, int>::iterator iter = flippedOnesMap.begin(); iter != flippedOnesMap.end(); ++iter) {
        std::cout << iter->first << ": " << iter->second << std::endl;
    }
}


int maxOnes(int *intArr, int left, int right, int nonFlippedOnes) {
    int nonFlippedOnesLeft = intArr[left];
    int nonFlippedOnesRight = intArr[right];

    if (left > right) {
        if (intArr[left] == 0) {
            return 1;
        }

        else if (intArr[right] == 0) {
            return 1;
        }

        else {
            return 0;
        }
    }

    int maxRight = nonFlippedOnesLeft + maxOnes(intArr, left + 1, right, nonFlippedOnes + nonFlippedOnesLeft);
    int maxLeft = nonFlippedOnesRight + maxOnes(intArr, left, right - 1, nonFlippedOnes + nonFlippedOnesRight);

    std::cout << "left: " << left << std::endl;
    std::cout << "right: " << right << std::endl;
    std::cout << "nonFlippedOnesLeft: " << nonFlippedOnesLeft << std::endl;
    std::cout << "nonFlippedOnesRight: " << nonFlippedOnesRight << std::endl;
    std::cout << "maxRight: " << maxRight << std::endl;
    std::cout << "maxLeft: " << maxLeft << std::endl;
    std::cout << std::endl;

    return (maxLeft < maxRight) ? maxRight : maxLeft;
}

void testMaxOnes() {
    int intArr[] = { 1, 0, 0, 0, 1, 0};

    std::cout << maxOnes(intArr, 0, 5, 0) << std::endl;
}


int main(int argc, char **argv) {
    // testMaxOnes();
    // testCalculatePossibleFlippedOnes();

    int n = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n;
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
    if (n == 1) {
        if (intArr[0] == 0) {
            std::cout << 1;
        }

        else {
            std::cout << 0;
        }
    }

    else {
        std::map<std::string, int> flippedOnesMap;

        calculatePossibleFlippedOnes(intArr, 0, n - 1, n, flippedOnesMap);

        int maxOnes = 0;
        std::string maxIndexes = "";

        for (std::map<std::string, int>::iterator iter = flippedOnesMap.begin(); iter != flippedOnesMap.end(); ++iter) {
            if (iter->second > maxOnes) {
                maxOnes = iter->second;
                maxIndexes = iter->first;
            }
        }

        std::cout << maxOnes;
    }

    return 0;
}
