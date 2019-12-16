#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    std::string guestName = "";
    std::string hostName = "";
    std::string lettersPile = "";

    // Read the first line
    if (std::getline(std::cin, guestName)) {

    }

    if (std::getline(std::cin, hostName)) {

    }

    if (std::getline(std::cin, lettersPile)) {

    }

    int lettersPileArr[26];
    int guestHostArr[26];
    for (int i = 0; i != 26; ++i) {
        lettersPileArr[i] = 0;
        guestHostArr[i] = 0;
    }

    for (unsigned int i = 0; i != guestName.length(); ++i) {
        ++guestHostArr[guestName[i] - 'A'];
    }

    for (unsigned int i = 0; i != hostName.length(); ++i) {
        ++guestHostArr[hostName[i] - 'A'];
    }

    for (unsigned int i = 0; i != lettersPile.length(); ++i) {
        ++lettersPileArr[lettersPile[i] - 'A'];
    }

    // Compare
    bool isAbleToPermuted = true;
    for (unsigned int i = 0; i != 26; ++i) {
        if (guestHostArr[i] != lettersPileArr[i]) {
            isAbleToPermuted = false;
            break;
        }
    }

    if (isAbleToPermuted) {
        std::cout << "YES";
    }

    else {
        std::cout << "NO";
    }

    return 0;
}
