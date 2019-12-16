#include <iostream>
#include <string>
#include <sstream>
#include <vector>


bool isUpperCase(char c) {
    return ((c >= 'A') && (c <= 'Z'));
}


char toLowerCase(char c) {
    if ((c >= 'A') && (c <= 'Z')) {
        return c + ('a' - 'A');
    }

    return c;
}


char toUpperCase(char c) {
    if ((c >= 'a') && (c <= 'z')) {
        return c - ('a' - 'A');
    }

    return c;
}


int main(int argc, char **argv) {
    // Read the word
    std::string word;
    std::cin >> word;
    std::string newWord = "";

    if (isUpperCase(word[0])) {
        if (word.length() == 1) {
            newWord += toLowerCase(word[0]);
        }

        else {
            // Test if word falls into first case
            for (unsigned int i = 1; i != word.length(); ++i) {
                if (!isUpperCase(word[i])) {
                    newWord = word;
                    break;
                }
            }

            // If newWord is empty it means the word is in the first case
            // Now we need to convert it to the final answer
            if (newWord.empty()) {
                newWord += toLowerCase(word[0]);

                for (unsigned int i = 1; i != word.length(); ++i) {
                    newWord += toLowerCase(word[i]);
                }
            }
        }
    }

    else {
        if (word.length() == 1) {
            newWord += toUpperCase(word[0]);
        }

        else {
            // Test if the word falls into the second case
            for (unsigned int i = 1; i != word.length(); ++i) {
                if (!isUpperCase(word[i])) {
                    newWord = word;
                    break;
                }
            }

            if (newWord.empty()) {
                newWord += toUpperCase(word[0]);

                for (unsigned int i = 1; i != word.length(); ++i) {
                    newWord += toLowerCase(word[i]);
                }
            }
        }
    }

    // Test if the word is in the first case
    std::cout << newWord;

    return 0;
}
