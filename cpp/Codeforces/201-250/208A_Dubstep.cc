#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    std::string word = "";
    std::cin >> word;
    std::string orgWord = "";
    int curIdx = 0;

    if (word.length() <= 2) {
        orgWord = word;
    }

    else {

        for (unsigned int i = 0; i < word.length() - 2; ++i) {
            if (word[i] == 'W') {
                if (word[i + 1] == 'U') {
                    if (word[i + 2] == 'B') {
                        if (orgWord.empty()) {

                        }

                        else if (orgWord[orgWord.length() - 1] != ' ') {
                            orgWord += " ";
                        }

                        i += 2;
                        curIdx += 2;
                    }

                    else {
                        orgWord += word[i];
                    }
                }

                else {
                    orgWord += word[i];
                }
            }

            else {
                orgWord += word[i];
            }

            ++curIdx;
        }

        orgWord += word.substr(curIdx, word.length());

        // if (!orgWord.empty()) {
        if (orgWord[orgWord.length() - 1] == ' ') {
            unsigned int lastSpaceIdx = 0;

            for (unsigned int i = orgWord.length() - 1; i >= 0; --i) {
                if (orgWord[i] == ' ') {
                    lastSpaceIdx = i;
                }

                else {
                    break;
                }
            }

            if (lastSpaceIdx != 0) {
                orgWord = orgWord.substr(0, lastSpaceIdx);
            }
        }
    }

    std::cout << orgWord;

    // }

    // else {
    // std::cout << word.substr(curIdx);
    // }

    return 0;
}
