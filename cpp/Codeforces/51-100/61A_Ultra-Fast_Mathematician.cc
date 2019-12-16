#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    std::string num1 = "";
    std::string num2 = "";
    if (std::getline(std::cin, num1)) {

    }

    if (std::getline(std::cin, num2)) {

    }

    for (unsigned int i = 0; i != num1.length(); ++i) {
        if (num1[i] == num2[i]) {
            std::cout << "0";
        }

        else {
            std::cout << "1";
        }
    }

    return 0;
}
