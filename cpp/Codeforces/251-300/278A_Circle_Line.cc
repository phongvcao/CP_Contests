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

    // Read the second line
    int intArr[n];
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        for (int i = 0; i != n; ++i) {
            ss >> intArr[i];
        }
    }

    // Read the third line
    int s = 0;
    int t = 0;
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> s >> t;
    }

    // Logic starts here
    int start      = (s < t) ? s : t;
    int end        = (s > t) ? s : t;
    int startIdx   = start - 1;
    int endIdx     = end - 1;
    int firstHalf  = 0;
    int secondHalf = 0;

    for (int i = startIdx; i != endIdx; ++i) {
        firstHalf += intArr[i];
    }

    for (int i = endIdx; i != startIdx; ++i) {
        i = i % n;
        if (i == startIdx) break;
        secondHalf += intArr[i];
    }

    if (firstHalf < secondHalf) {
        std::cout << firstHalf;
    }

    else {
        std::cout << secondHalf;
    }

    return 0;
}
