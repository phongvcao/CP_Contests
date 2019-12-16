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

    int soldiersArr[n];
    int soldiersArrIdx = 0;
    int maxSoldierIdx = 0;
    int minSoldierIdx = 0;
    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        while (soldiersArrIdx < n) {
            ss >> soldiersArr[soldiersArrIdx++];

            if (soldiersArr[soldiersArrIdx - 1] > soldiersArr[maxSoldierIdx]) {
                maxSoldierIdx = soldiersArrIdx - 1;
            }

            if (soldiersArr[soldiersArrIdx - 1] <= soldiersArr[minSoldierIdx]) {
                minSoldierIdx = soldiersArrIdx - 1;
            }
        }
    }

    // Logic starts here
    int minSwapsCount = maxSoldierIdx + n - 1 - minSoldierIdx;
    if (maxSoldierIdx > minSoldierIdx) {
        minSwapsCount -= 1;
    }

    else if (maxSoldierIdx == minSoldierIdx){
        minSwapsCount = 0;
    }
    std::cout << minSwapsCount;

    return 0;
}
