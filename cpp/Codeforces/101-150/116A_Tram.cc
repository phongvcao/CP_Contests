#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include <cstdlib>


using namespace std;
typedef int64_t Int;
typedef uint64_t UInt;


int main(int argc, char **argv) {
    long long int n = 0;

    // Read the first line
    std::string line;
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n;
    }

    // Read the next n lines
    long long int capacity = 0;
    long long int curCapacity = 0;

    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        long long int exitsCount = 0;
        long long int entersCount = 0;

        ss >> exitsCount >> entersCount;

        curCapacity += entersCount - exitsCount;

        if (curCapacity > capacity) {
            capacity = curCapacity;
        }

        --n;
        if (n == 0) break;
    }

    std::cout << capacity;

    return 0;
}
