#include <iostream>
#include <string>
#include <sstream>
#include <vector>


char toLowerCase(char c) {
    if ((c >= 'A') && (c <= 'Z')) {
        return c + ('a' - 'A');
    }

    return c;
}


bool isVowel(char c) {
    std::string vowels = "aoyeui";

    for (unsigned int i = 0; i != vowels.length(); ++i) {
        if (vowels[i] == toLowerCase(c)) {
            return true;
        }
    }

    return false;
}


void testToLowerCase() {
    std::cout << toLowerCase('C') << std::endl;
}


void testIsVowel() {
    if (isVowel('Y')) {
        std::cout << "It is vowel!" << std::endl;
    }

    else {
        std::cout << "It is not vowel!" << std::endl;
    }
}


std::string processString(std::string str) {
    std::string returnStr = "";

    for (unsigned int i = 0; i != str.length(); ++i) {
        if (!isVowel(str[i])) {
            returnStr += '.';
            returnStr += toLowerCase(str[i]);
        }
    }

    return returnStr;
}


int main(int argc, char **argv) {
    // testToLowerCase();
    // testIsVowel();

    std::string word;
    std::cin >> word;

    std::cout << processString(word);

    return 0;
}
