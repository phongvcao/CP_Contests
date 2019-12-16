#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    std::string str;
    std::cin >> str;

    char curChar = str[0];
    int curCharCount = 1;
    bool isDangerous = false;

    for (unsigned int i = 1; i != str.length(); ++i) {
        if (str[i] == curChar) {
            ++curCharCount;
        }

        else {
            curChar = str[i];
            curCharCount = 1;
        }

        if (curCharCount == 7) {
            isDangerous = true;
            break;
        }
    }

    if (isDangerous) {
        std::cout << "YES";
    }

    else {
        std::cout << "NO";
    }

    return 0;
}
