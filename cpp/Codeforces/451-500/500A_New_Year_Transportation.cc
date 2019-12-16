#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>


int main(int argc, char **argv) {
    int n = 0;
    int t = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> n >> t;
    }

    int startIdx = 1;
    std::map<int, int> portalsMap;
    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        while (n > 1) {
            int destCell = 0;
            ss >> destCell;

            portalsMap.insert(std::pair<int, int>(startIdx, startIdx + destCell));

            --n;
            ++startIdx;
        }
    }

    // Check if possible going to cell t
    int curPos = 1;
    std::map<int, int>::iterator iter = portalsMap.find(curPos);
    while (true) {
        if (iter->second == t) {
            std::cout << "YES";
            break;
        }

        else {
            iter = portalsMap.find(iter->second);

            if (iter != portalsMap.end()) {
                curPos = iter->second;
            }

            else {
                std::cout << "NO";
                break;
            }
        }
    }

    return 0;
}
