#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    bool isOutput = false;

    // Read the first line
    std::string line;
    if (std::getline(std::cin, line)) {
        for (unsigned int i = 0; i != line.length(); ++i) {
            if ((line[i] == 'H') || (line[i] == 'Q') || (line[i] == '9')) {
                isOutput = true;
                break;
            }
        }
    }

    if (isOutput) std::cout << "YES";
    else std::cout << "NO";

    return 0;
}
