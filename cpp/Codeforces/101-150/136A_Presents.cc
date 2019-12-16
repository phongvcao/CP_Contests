#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    int n;
    // Read the first line
    std::string line;
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> n;
    }

    // Read the second line
    // 2 3 4 1
    // => 2 give to 1
    // => 3 give to 2
    // => 4 give to 3
    // => 1 give to 4
    //
    // Output:
    // 4 1 2 3
    //
    // Implement an Array with number ith as index and indexes
    // as values
    int intArr[n + 1];
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        int cinIdx = 0;
        for (int i = 1; i != n + 1; ++i) {
            ss >> cinIdx;
            intArr[cinIdx] = i;
        }
    }

    for (int i = 1; i != n + 1; ++i) {
        std::cout << intArr[i] << " ";
    }

    return 0;
}
