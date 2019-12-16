#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    std::string firstRow = "qwertyuiop";
    std::string secondRow = "asdfghjkl;";
    std::string thirdRow = "zxcvbnm,./";

    std::string direction = "";
    if (std::getline(std::cin, direction)) {

    }

    std::string inputStr = "";
    if (std::getline(std::cin, inputStr)) {

    }

    int offset = 0;
    if (direction[0] == 'R') {
        offset = -1;
    }

    else if (direction[0] == 'L') {
        offset = 1;
    }

    std::string finalStr = "";

    for (unsigned int i = 0; i != inputStr.length(); ++i) {
        int firstRowIdx = firstRow.find(inputStr[i]);
        int secondRowIdx = secondRow.find(inputStr[i]);
        int thirdRowIdx = thirdRow.find(inputStr[i]);

        if (firstRowIdx != -1) {
            finalStr += firstRow[firstRowIdx + offset];
        }

        else {
            if (secondRowIdx != -1) {
                finalStr += secondRow[secondRowIdx + offset];
            }

            else {
                if (thirdRowIdx != -1) {
                    finalStr += thirdRow[thirdRowIdx + offset];
                }
            }
        }
    }

    std::cout << finalStr;

    return 0;
}
