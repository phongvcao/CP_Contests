#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
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
    int leftIdx = 0;
    int rightIdx = n - 1;
    int serejaScore = 0;
    int dimaScore = 0;
    bool serejaTurn = true;

    while (leftIdx <= rightIdx) {
        if (serejaTurn) {
            if (intArr[leftIdx] < intArr[rightIdx]) {
                serejaScore += intArr[rightIdx];
                --rightIdx;
            }

            else {
                serejaScore += intArr[leftIdx];
                ++leftIdx;
            }
        }

        else {
            if (intArr[leftIdx] < intArr[rightIdx]) {
                dimaScore += intArr[rightIdx];
                --rightIdx;
            }

            else {
                dimaScore += intArr[leftIdx];
                ++leftIdx;
            }
        }

        serejaTurn = !serejaTurn;
    }

    std::cout << serejaScore << " " << dimaScore;

    return 0;
}
