#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    std::string numStr = "";
    std::cin >> numStr;

    if (numStr.length() >= 2) {
        for (int i = 0; i < numStr.length() - 2; ++i) {
            if (numStr.substr(i, 3).compare("144") == 0) {
                numStr[i] = 'a';
                numStr[i + 1] = 'a';
                numStr[i + 2] = 'a';
            }
        }
    }

    if (numStr.length() >= 1) {
        for (int i = 0; i < numStr.length() - 1; ++i) {
            if (numStr.substr(i, 2).compare("14") == 0) {
                numStr[i] = 'a';
                numStr[i + 1] = 'a';
            }
        }
    }

    for (int i = 0; i < numStr.length(); ++i) {
        if (numStr[i] == '1') {
            numStr[i] = 'a';
        }
    }

    for (int i = 0; i < numStr.length(); ++i) {
        if (numStr[i] != 'a') {
            std::cout << "NO";
            return 0;
        }
    }

    std::cout << "YES";

    return 0;
}
