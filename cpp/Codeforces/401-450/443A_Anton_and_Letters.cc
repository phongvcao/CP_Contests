#include <iostream>
#include <string>
#include <sstream>
#include <vector>


bool isAlphabet(char c) {
    return ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'));
}


char toLowerCase(char c) {
    if ((c >= 'A') && (c <= 'Z')) {
        return c + ('a' - 'A');
    }

    return c;
}


int main(int argc, char **argv) {
    std::string setStr = "";

    if (std::getline(std::cin, setStr)) {

    }

    int charsCountArr[26];
    for (int i = 0; i != 26; ++i) {
        charsCountArr[i] = 0;
    }

    for (unsigned int i = 0; i != setStr.length(); ++i) {
        if (isAlphabet(setStr[i])) {
            ++charsCountArr[toLowerCase(setStr[i]) - 'a'];
        }
    }

    int distinctLettersCount = 0;
    for (int i = 0; i != 26; ++i) {
        if (charsCountArr[i] > 0) {
            ++distinctLettersCount;
        }
    }

    std::cout << distinctLettersCount;

    return 0;
}
