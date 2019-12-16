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


int compareStrCaseInsensitive(std::string str1, std::string str2) {
    for (unsigned int i = 0; i != str1.length(); ++i) {
        if (toLowerCase(str1[i]) < toLowerCase(str2[i])) {
            return -1;
        }

        else if (toLowerCase(str1[i]) > toLowerCase(str2[i])) {
            return 1;
        }
    }

    return 0;
}


int main(int argc, char **argv) {
    std::string str1 = "";
    std::string str2 = "";

    // Read the first line
    if (std::getline(std::cin, str1)) {

    }

    // Read the second line
    if (std::getline(std::cin, str2)) {

    }

    std::cout << compareStrCaseInsensitive(str1, str2);

    return 0;
}
