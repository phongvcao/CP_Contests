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
    int evenCount = 0;
    int oddCount = 0;
    int odd = 0;
    int even = 0;
    for (int i = 0; i != n; ++i) {
        if (intArr[i] % 2 == 0) {
            ++evenCount;
            even = i;
        }

        else {
            ++oddCount;
            odd = i;
        }
    }

    if (oddCount == 1) {
        std::cout << odd + 1;
    }

    else if (evenCount == 1) {
        std::cout << even + 1;
    }

    return 0;
}
