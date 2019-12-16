#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>


int main(int argc, char **argv) {
    int n = 0;
    std::cin >> n;

    int n2 = n * n;
    int sum = (n2 + 1) * (n2 / 2);

    int candiesPerLine = sum / n;
    int candiesCountPerLine = 0;
    // Print each line
    for (int i = 1; i != n2 / 2 + 1; ++i) {
        candiesCountPerLine += i + (n2 + 1 - i);
        std::cout << i << " " << (n2 + 1 - i);

        if (candiesCountPerLine < candiesPerLine) {
            std::cout << " ";
        }

        if (candiesCountPerLine >= candiesPerLine) {
            if (i != n2 / 2) {
                std::cout << std::endl;
            }
            candiesCountPerLine = 0;
        }
    }

    return 0;
}
