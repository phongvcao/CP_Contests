#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    int intArr[4];
    bool replaceArr[4];
    int toBeBoughtShoes = 0;
    for (unsigned int i = 0; i != sizeof(intArr)/sizeof(int); ++i) {
        std::cin >> intArr[i];
        replaceArr[i] = false;
    }

    for (unsigned int i = 0; i != sizeof(intArr)/sizeof(int) - 1; ++i) {
        for (unsigned int j = i + 1; j != sizeof(intArr)/sizeof(int); ++j) {
            // std::cout << "Comparing " << intArr[i] << " and " << intArr[j] << std::endl

            if (!replaceArr[j]) {
                if (intArr[i] == intArr[j]) {
                    replaceArr[j] = true;
                }
            }
        }
    }

    for (unsigned int i = 0; i != sizeof(replaceArr)/sizeof(bool); ++i) {
        if (replaceArr[i]) {
            ++toBeBoughtShoes;
        }
    }

    std::cout << toBeBoughtShoes;

    return 0;
}
