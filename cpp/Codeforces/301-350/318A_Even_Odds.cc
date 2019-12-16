#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    long long int n = 0;
    long long int k = 0;
    std::cin >> n >> k;

    long long int oddNumCount = (n + 1) / 2;

    if (k <= oddNumCount) {
        std::cout << 1 + 2 * (k - 1);
    }

    else if (k > oddNumCount) {
        std::cout << 2 + 2 * (k - oddNumCount - 1);
    }

    return 0;
}
