#include <iostream>
#include <string>
#include <sstream>
#include <vector>


void fillArr(bool *arr, int size, bool value) {
    for (int i = 0; i != size; ++i) {
        arr[i] = value;
    }
}


int skipChar(std::string str, char c, int curIdx) {
    while (str[curIdx] != c) {
        ++curIdx;
    }

    return curIdx;
}


int main(int argc, char **argv) {
    std::string s;
    std::cin >> s;

    // Loop through the string
    // - If found h
    //   + Mark helloMatches[0] = true
    //   + Skip all h
    // - Next if found e
    //   + Mark helloMatches[1] = true
    //   + Skip all e
    // - Next if found ll
    //   + Mark helloMatches[2-3] = true
    //   + Skip all l
    // - Next if found o
    //   + Mark helloMatches[4] = true
    //   + Skip all o
    //   + Return true
    //

    bool isFound = false;
    for (unsigned int i = 0; i != s.length(); ++i) {
        if (s[i] == 'h') {
            // std::cout << "h found at i = " << i << std::endl;
            i = skipChar(s, 'e', i);

            if (i < s.length()) {
                // std::cout << "e found at i = " << i << std::endl;
                i = skipChar(s, 'l', i);

                if (i < s.length()) {
                    // std::cout << "l found at i = " << i << std::endl;
                    i = skipChar(s, 'l', ++i);

                    if (i < s.length()) {
                        // std::cout << "l found at i = " << i << std::endl;
                        i = skipChar(s, 'o', i);

                        if (i < s.length()) {
                            // std::cout << "o found at i = " << i << std::endl;
                            isFound = true;
                            break;
                        }

                        else {
                            // if (s[i - 1] == 'o') {
                                // isFound = true;
                                // break;
                                // }
                        }
                    }

                    else {
                        break;
                    }
                }

                else {
                    break;
                }
            }

            else {
                break;
            }
        }
    }

    if (isFound) {
        std::cout << "YES";
    }

    else {
        std::cout << "NO";
    }

    return 0;
}
