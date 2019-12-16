#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    int sticksArr[10];
    for (int i = 0; i != sizeof(sticksArr) / sizeof(int); ++i) {
        sticksArr[i] = 0;
    }

    // Read data
    int idx = 0;
    while (idx < 6) {
        int num = 0;
        std::cin >> num;
        ++sticksArr[num];

        ++idx;
    }

    bool isAnimal = false;
    bool isElephant = false;
    bool isBear = false;
    // Conclusion
    for (int i = 0; i != sizeof(sticksArr) / sizeof(int); ++i) {
        if (sticksArr[i] == 4) {
            isAnimal = true;
            break;
        }

        else if (sticksArr[i] == 6) {
            isAnimal = true;
            isElephant = true;
            break;
        }

        else if (sticksArr[i] == 5) {
            isAnimal = true;
            isBear = true;
            break;
        }
    }

    if (isAnimal) {
        if ((!isElephant) && (!isBear)) {
            for (int i = 0; i != sizeof(sticksArr) / sizeof(int); ++i) {
                if (sticksArr[i] == 2) {
                    isElephant = true;
                }
            }
        }

        if (isElephant) std::cout << "Elephant";
        else if (isBear) std::cout << "Bear";
        else std::cout << "Bear";
    }

    else {
        std::cout << "Alien";
    }

    return 0;
}
