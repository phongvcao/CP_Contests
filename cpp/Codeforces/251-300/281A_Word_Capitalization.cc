#include <iostream>
#include <string>
#include <sstream>
#include <vector>


char toUpperCase(char c) {
    if ((c >= 'a') && (c <= 'z')) {
        return c - ('a' - 'A');
    }

    return c;
}


std::string capitalizeStr(std::string str) {
    std::string returnStr = "";

    returnStr += toUpperCase(str[0]);

    if (str.length() > 1) {
        for (unsigned int i = 1; i != str.length(); ++i) {
            returnStr += str[i];
        }
    }

    return returnStr;
}


int main(int argc, char **argv) {
    std::string word = "";
    std::cin >> word;

    std::cout << capitalizeStr(word);

    return 0;
}
