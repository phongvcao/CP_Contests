#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>


int main(int argc, char **argv) {
    std::map <std::string, std::string> langMap;

    int n = 0;
    int m = 0;
    // Read the first line
    std::string line;
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n >> m;
    }

    // Read the next m lines
    std::string firstLang = "";
    std::string secondLang = "";
    std::map<std::string, std::string>::iterator iter = langMap.begin();
    while (std::getline(std::cin , line)) {
        std::stringstream ss(line);

        ss >> firstLang >> secondLang;
        langMap.insert(iter, std::pair<std::string, std::string>(firstLang, secondLang));

        --m;
        if (m == 0) break;
    }

    // Read the last line
    std::string lectureWords[n];
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        int lectureWordsIdx = 0;
        std::string lectureWord = "";
        // Logic starts here
        while (n > 0) {
            ss >> lectureWord;

            if (lectureWord.length() <= langMap[lectureWord].length()) {
                lectureWords[lectureWordsIdx++] = lectureWord;
            }

            else {
                lectureWords[lectureWordsIdx++] = langMap[lectureWord];
            }

            if (lectureWordsIdx == n) break;
        }
    }

    for (int i = 0; i != n; ++i) {
        std::cout << lectureWords[i];

        if (i != n - 1) {
            std::cout << " ";
        }
    }

    return 0;
}
