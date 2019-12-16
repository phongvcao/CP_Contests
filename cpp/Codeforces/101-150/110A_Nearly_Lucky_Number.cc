#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    std::string n;
    std::cin >> n;

    int luckyNumCount = 0;
    for (unsigned int i = 0; i != n.length(); ++i) {
        if ((n[i] - '0' == 4) || (n[i] - '0' == 7)) {
            ++luckyNumCount;
        }
    }

    if ((luckyNumCount == 4) || (luckyNumCount == 7)) {
        std::cout << "YES";
    }

    else {
        std::cout << "NO";
    }

    return 0;
}
