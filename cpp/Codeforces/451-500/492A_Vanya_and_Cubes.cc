#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    int levelsCount = 0;
    int n = 0;
    std::cin >> n;
    int cubesLeft = n;
    int cubesCurrentLevel = 0;

    if (cubesLeft == 1) {
        ++levelsCount;
    }

    else {
        while (cubesLeft >= cubesCurrentLevel + levelsCount + 1) {
            ++levelsCount;
            cubesCurrentLevel += levelsCount;
            cubesLeft -= cubesCurrentLevel;
        }
    }

    std::cout << levelsCount;

    return 0;
}
