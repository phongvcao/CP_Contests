#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    int n;
    int totalPresses = 0;
    std::cin >> n;

    if (n == 1) {
        totalPresses = 1;
    }

    else {
        totalPresses = n + 1;

        for (int i = 2; i < n; ++i) {
            totalPresses += i * (n - i) + 1;
        }
    }

    std::cout << totalPresses;

    return 0;
}
