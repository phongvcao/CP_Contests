#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>


int main(int argc, char **argv) {
    int a = 0;
    int b = 0;
    std::cin >> a >> b;

    int firstPlayerWinCount = 0;
    int secondPlayerWinCount = 0;
    int drawCount = 0;

    for (int i = 1; i != 7; ++i) {
        if (abs(a - i) > abs(b - i)) {
            ++secondPlayerWinCount;
        }

        else if (abs(a - i) < abs(b - i)) {
            ++firstPlayerWinCount;
        }

        else {
            ++drawCount;
        }
    }

    std::cout << firstPlayerWinCount << " " << drawCount << " " << secondPlayerWinCount;

    return 0;
}
