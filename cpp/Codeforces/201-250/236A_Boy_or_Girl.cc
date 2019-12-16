#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    bool alphabets[26];
    std::string name;

    std::cin >> name;

    for (unsigned int i = 0; i != 26; ++i) {
        alphabets[i] = false;
    }

    for (unsigned int i = 0; i != name.length(); ++i) {
        alphabets[name[i] - 'a'] = true;
    }

    int uniqueCharsCount = 0;
    for (unsigned int i = 0; i != sizeof(alphabets)/sizeof(bool); ++i) {
        if (alphabets[i]) {
            ++uniqueCharsCount;
        }
    }

    if (uniqueCharsCount % 2 == 0) {
        std::cout << "CHAT WITH HER!";
    }

    else {
        std::cout << "IGNORE HIM!";
    }

    return 0;
}
