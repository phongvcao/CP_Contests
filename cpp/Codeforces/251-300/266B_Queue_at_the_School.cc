#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    long long int n = 0;
    int t = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n >> t;
    }

    char childrenArr[n];
    long long int childrenArrIdx = 0;
    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        while (childrenArrIdx != n) {
            ss >> childrenArr[childrenArrIdx++];
        }
    }

    // Now starts the logic
    for (int i = 0; i != t; ++i) {
        long long int j = 0;

        while (j < n) {
            if ((childrenArr[j] == 'B') && (childrenArr[j + 1] == 'G')) {
                char temp = childrenArr[j];
                childrenArr[j] = childrenArr[j + 1];
                childrenArr[j + 1] = temp;
                j += 2;

                /* if (n == 10) {
                    for (long long int k = 0; k != n; ++k) {
                        std::cout << childrenArr[k];
                    }
                    std::cout << std::endl;
                    } */
            }

            else {
                ++j;
            }

            if (j > n - 2) break;
        }
    }

    // Prints out everything
    for (long long int i = 0; i != n; ++i) {
        std::cout << childrenArr[i];
    }

    return 0;
}
