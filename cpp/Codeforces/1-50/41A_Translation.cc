#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    std::string line1 = "";
    std::string line2 = "";

    if (std::getline(std::cin, line1)) {

    }

    if (std::getline(std::cin, line2)) {

    }

    bool isCorrect = true;
    for (unsigned int i = 0; i != line1.length(); ++i) {
        if (line1[i] != line2[line1.length() - 1 - i]) {
            isCorrect = false;
            break;
        }
    }

    if (isCorrect) {
        std::cout << "YES";
    }

    else {
        std::cout << "NO";
    }

    return 0;
}
