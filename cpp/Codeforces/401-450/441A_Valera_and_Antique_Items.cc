#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdint.h>


bool isAbleToMakeADeal(const std::vector<int64_t>& sellerVector, int64_t v) {
    for (uint64_t i = 0; i != sellerVector.size(); ++i) {
        if (sellerVector[i] < v) return true;
    }

    return false;
}


int main(int argc, char **argv) {
    int64_t n = 0;
    int64_t v = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n >> v;
    }

    std::vector<std::vector<int64_t> > sellersVector;
    int64_t sellersVectorIdx = 0;
    // Read the next n lines
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        int k = 0;
        ss >> k;

        std::vector<int64_t> sellerVector;
        int64_t sellerVectorIdx = 0;
        while (sellerVectorIdx < k) {
            int64_t curNum = 0;
            ss >> curNum;
            sellerVector.push_back(curNum);
            ++sellerVectorIdx;
        }
        sellersVector.push_back(sellerVector);

        ++sellersVectorIdx;

        if (sellersVectorIdx == n) break;
    }

    std::vector<uint64_t> sellersIdxVector;
    // Logic starts here
    for (uint64_t i = 0; i != sellersVector.size(); ++i) {
        if (isAbleToMakeADeal(sellersVector[i], v)) {
            sellersIdxVector.push_back(i + 1);
        }
    }

    std::cout << sellersIdxVector.size() << std::endl;
    for (uint64_t i = 0; i != sellersIdxVector.size(); ++i) {
        std::cout << sellersIdxVector[i];

        if (i < sellersIdxVector.size() - 1) std::cout << " ";
    }

    return 0;
}
