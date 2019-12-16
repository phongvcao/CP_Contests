#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    int n = 0;
    int m = 0;
    int k = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n >> m >> k;
    }

    int intArr[n];
    int intArrIdx = 0;
    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        while (intArrIdx < n) {
            ss >> intArr[intArrIdx++];
        }
    }

    // Logic starts here
    int washesCount = 0;
    int bowlsLeft   = m;
    int platesLeft  = k;

    for (int i = 0; i != n; ++i) {
        if (intArr[i] == 1) {
            if (bowlsLeft > 0) {
                --bowlsLeft;
            }

            else {
                ++washesCount;
            }
        }

        else {
            if (platesLeft > 0) {
                --platesLeft;
            }

            else {
                if (bowlsLeft > 0) {
                    --bowlsLeft;
                }

                else {
                    ++washesCount;
                }
            }
        }
    }

    std::cout << washesCount;


    return 0;
}
