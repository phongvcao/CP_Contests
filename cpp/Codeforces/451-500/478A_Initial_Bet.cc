#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    int intArr[5];
    int sum = 0;

    for (int i = 0; i != 5; ++i) {
        std::cin >> intArr[i];
    }

    for (int i = 0; i != 5; ++i) {
        sum += intArr[i];
    }

    if ((sum % 5 == 0) && (sum / 5 >= 1)) {
        std::cout << sum / 5;
    }

    else {
        std::cout << -1;
    }

    return 0;
}
