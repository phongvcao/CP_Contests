#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdint.h>


int main(int argc, char **argv) {
    int n = 0;
    int m = 0;
    std::vector<int> intVector;

    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> n >> m;
    }

    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        while (m > 0) {
            int curNum = 0;
            ss >> curNum;

            if ((intVector.size() == 0) || (curNum != intVector[intVector.size() - 1])) {
                intVector.push_back(curNum);
            }

            --m;
        }
    }

    long long int totalTime = intVector[0] - 1;
    int prevStep = intVector[0];
    // Logic starts here
    for (unsigned int i = 1; i != intVector.size(); ++i) {
        if (intVector[i] > prevStep) {
            totalTime += intVector[i] - prevStep;
        }

        else {
            totalTime += intVector[i] - 1;
            totalTime += n - prevStep + 1;
        }

        prevStep = intVector[i];
    }

    std::cout << totalTime;

    return 0;
}
