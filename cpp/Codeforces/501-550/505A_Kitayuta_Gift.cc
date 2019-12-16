#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>


bool isPalindrome(std::string s) {
    for (int i = 0; i != s.length() / 2; ++i) {
        if (s[i] != s[s.length() - 1 - i]) {
            return false;
        }
    }

    return true;
}


std::string reverseStr(std::string str) {
    std::string newStr = "";

    for (int i = str.length() - 1; i >= 0; --i) {
        newStr += str[i];
    }

    return newStr;
}


bool isCloseMatch(std::string orgStr, std::string newStr) {
    int orgCharCountArr[26];
    int newCharCountArr[26];

    for (int i = 0; i != 26; ++i) {
        orgCharCountArr[i] = 0;
        newCharCountArr[i] = 0;
    }

    for (int i = 0; i != orgStr.length(); ++i) {
        ++orgCharCountArr[orgStr[i] - 'a'];
    }

    for (int i = 0; i != newStr.length(); ++i) {
        ++newCharCountArr[newStr[i] - 'a'];
    }

    int totalDiff = 0;

    for (int i = 0; i != 26; ++i) {
        totalDiff += abs(orgCharCountArr[i] - newCharCountArr[i]);
    }

    return totalDiff == 1;
}


int main(int argc, char **argv) {
    std::string word = "";
    std::string newWord = "";

    std::cin >> word;
    int charArr[26];

    for (int i = 0; i != 26; ++i) {
        charArr[i] = 0;
    }

    if (isPalindrome(word)) {
        if (word.length() % 2 == 0) {
            for (int i = 0; i != word.length() / 2; ++i) {
                newWord += word[i];
            }

            newWord += "a";

            for (int i = word.length() / 2; i != word.length(); ++i) {
                newWord += word[i];
            }
        }

        else {
            newWord += reverseStr(word.substr(word.length() / 2, word.length()));
            newWord += word.substr(word.length() / 2, word.length());
        }
    }

    else {
        for (int i = 0; i != word.length(); ++i) {
            ++charArr[word[i] - 'a'];
        }

        int oddLettersCount = 0;

        for (int i = 0; i != 26; ++i) {
            if (charArr[i] % 2 != 0) {
                ++oddLettersCount;
            }
        }

        if (oddLettersCount >= 3) {
            newWord = "NA";
        }

        else {
            int centerLetterIdx = 0;

            // If word.length() is even
            if (word.length() % 2 == 0) {
                int firstCenterIdx = word.length() / 2;
                int secondCenterIdx = word.length() / 2 - 1;
                std::string firstNewWord = "";
                std::string secondNewWord = "";

                // First reversal case
                // Copy halfLeft to halfRight
                firstNewWord += word.substr(0, firstCenterIdx);
                firstNewWord += word[firstCenterIdx];
                firstNewWord += reverseStr(word.substr(0, firstCenterIdx));

                // Second reversal case
                // Copy halfRight to halfLeft
                // First create the halfLeft by reversing halfRight
                secondNewWord += reverseStr(word.substr(secondCenterIdx + 1, word.length()));
                secondNewWord += word[secondCenterIdx];
                secondNewWord += word.substr(secondCenterIdx + 1, word.length());

                if (isCloseMatch(word, firstNewWord)) {
                    newWord = firstNewWord;
                }

                else {
                    newWord = secondNewWord;
                }
            }

            // If word.length() is odd
            else {
                centerLetterIdx = word.length() / 2;
                std::string firstNewWord = "";
                std::string secondNewWord = "";

                // Copy halfRight to halfLeft
                firstNewWord += reverseStr(word.substr(centerLetterIdx, word.length()));
                firstNewWord += word.substr(centerLetterIdx, word.length());

                // Copy halfLeft to halfRight
                secondNewWord += word.substr(0, centerLetterIdx + 1);
                secondNewWord += reverseStr(word.substr(0, centerLetterIdx + 1));

                if (isCloseMatch(word, firstNewWord)) {
                    newWord = firstNewWord;
                }

                else {
                    newWord = secondNewWord;
                }
            }
        }
    }

    std::cout << newWord;

    return 0;
}
