#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    int n = 0;
    std::cin >> n;

    for (int i = 0; i != n + 1; ++i) {
        int spacesCount = n - i;
        // Print the front spaces
        for (int j = 0; j != spacesCount; ++j) {
            std::cout << "  ";
        }

        // Print the left numbers
        for (int j = 0; j != i + 1; ++j) {
            std::cout << j;

            if (i != 0) {
                std::cout << " ";
            }
        }

        // Print the right numbers
        if (i > 0) {
            for (int j = i - 1; j >= 0; --j) {
                std::cout << j;

                if (j != 0) {
                    std::cout << " ";
                }
            }
        }

        // Print newline
        if (n > 0) {
            std::cout << std::endl;
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        int spacesCount = n - i;
        // Print the front spaces
        for (int j = 0; j != spacesCount; ++j) {
            std::cout << "  ";
        }

        // Print the left numbers
        for (int j = 0; j != i + 1; ++j) {
            std::cout << j;

            if (i != 0) {
                std::cout << " ";
            }
        }

        // Print the right numbers
        if (i > 0) {
            for (int j = i - 1; j >= 0; --j) {
                std::cout << j;

                if (j != 0) {
                    std::cout << " ";
                }
            }
        }

        // Print newline
        if (i > 0) {
            std::cout << std::endl;
        }
    }


    return 0;
}
