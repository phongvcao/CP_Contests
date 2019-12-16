#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    int n = 0;
    int m = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n >> m;
    }

    std::vector<int> intVector;
    std::vector<int> idxVector;
    int intArrIdx = 0;
    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        while (intArrIdx < n) {
            int curNum = 0;
            ss >> curNum;
            intVector.push_back(curNum);
            ++intArrIdx;
            idxVector.push_back(intArrIdx);
        }
    }

    // Logic starts here
    while (intVector.size() > 0) {
        if (intVector.size() == 1) {
            break;
        }

        if (intVector[0] <= m) {
            intVector.erase(intVector.begin());
            idxVector.erase(idxVector.begin());
        }

        else {
            int temp = intVector[0];
            intVector.erase(intVector.begin());
            intVector.push_back(temp - m);

            int tempIdx = idxVector[0];
            idxVector.erase(idxVector.begin());
            idxVector.push_back(tempIdx);
        }
    }

    std::cout << idxVector[0];

    return 0;
}
