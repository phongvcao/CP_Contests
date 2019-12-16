#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    int i = (n % 2 == 1) ? n / 2 + 1 : n / 2;
    while (i != n + 1) {
        if (i % m == 0) {
            std::cout << i;
            return 0;
        }

        ++i;
    }

    std::cout << -1;

    return 0;
}
