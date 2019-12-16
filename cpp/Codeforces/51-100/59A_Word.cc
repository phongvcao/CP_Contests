#include <iostream>
#include <string>
#include <sstream>
#include <vector>


bool isLowerCase(char c) {
    return (c >= 'a') && (c <= 'z');
}


bool isUpperCase(char c) {
    return (c >= 'A') && (c <= 'Z');
}


char toUpperCase(char c) {
    if (isLowerCase(c)) {
        return c - ('a' - 'A');
    }

    return c;
}


char toLowerCase(char c) {
    if (isUpperCase(c)) {
        return c + ('a' - 'A');
    }

    return c;
}


bool isToLower(std::string str) {
    int lowerCaseCount = 0;

    for (unsigned int i = 0; i != str.length(); ++i) {
        if (isLowerCase(str[i])) {
            ++lowerCaseCount;
        }
    }

    if (lowerCaseCount >= str.length() - lowerCaseCount) {
        return true;
    }

    return false;
}


std::string toLowerCase(std::string str) {
    for (unsigned int i = 0; i != str.length(); ++i) {
        str[i] = toLowerCase(str[i]);
    }

    return str;
}


std::string toUpperCase(std::string str) {
    for (unsigned int i = 0; i != str.length(); ++i) {
        str[i] = toUpperCase(str[i]);
    }

    return str;
}


int main(int argc, char **argv) {
    std::string word = "";
    std::cin >> word;

    if (isToLower(word)) {
        std::cout << toLowerCase(word);
    }

    else {
        std::cout << toUpperCase(word);
    }

    return 0;
}
