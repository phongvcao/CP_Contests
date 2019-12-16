#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    long long int n;
    // Read the first line
    std::string line;
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> n;
    }

    // Read the second line
    long long int onesCount = 0;
    long long int twosCount = 0;
    long long int threesCount = 0;
    long long int foursCount = 0;

    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        int curInt = 0;

        while (ss >> curInt) {
            if (curInt == 1) ++onesCount;
            else if (curInt == 2) ++twosCount;
            else if (curInt == 3) ++threesCount;
            else if (curInt == 4) ++foursCount;
            else std::cout << "Wrong input values" << std::endl;

            --n;
            if (n == 0) break;
        }

        /* std::cout << "foursCount: " << foursCount << std::endl;
        std::cout << "threesCount: " << threesCount << std::endl;
        std::cout << "twosCount: " << twosCount << std::endl;
        std::cout << "onesCount: " << onesCount << std::endl; */


        long long int taxisCount = foursCount;

        // Combine threes and ones
        if (threesCount > onesCount) {
            taxisCount += onesCount;
            threesCount -= onesCount;
            onesCount = 0;
        }

        else if (threesCount < onesCount) {
            taxisCount += threesCount;
            onesCount -= threesCount;
            threesCount = 0;
        }

        else {
            taxisCount += threesCount;
            threesCount = 0;
            onesCount = 0;
        }

        taxisCount += threesCount;

        taxisCount += (onesCount + twosCount * 2) / 4;
        if ((onesCount + twosCount * 2) % 4 != 0) {
            taxisCount += 1;
        }

        std::cout << taxisCount;
    }

    return 0;
}
