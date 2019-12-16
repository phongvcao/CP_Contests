#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    int n = 0;
    int m = 0;

    std::cin >> n;
    std::cin >> m;

    int daysCount = 0;
    while (n > 0) {
        --n;

        ++daysCount;

        if (daysCount % m == 0) {
            ++n;
        }
    }

    std::cout << daysCount;

    return 0;
}
