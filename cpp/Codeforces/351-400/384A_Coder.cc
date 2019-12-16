#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    int n = 0;
    std::cin >> n;

    int codersCount = 0;
    if (n % 2 == 1) {
        codersCount += (n / 2 + 1) * (n / 2 + 1);
        codersCount += (n / 2) * (n / 2);
    }

    else {
        codersCount += (n / 2) * (n / 2);
        codersCount += (n / 2) * (n / 2);
    }
    std::cout << codersCount << std::endl;

    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            if (i % 2 == 1) {
                if (j % 2 == 0) {
                    std::cout << ".";
                }

                else {
                    std::cout << "C";
                }
            }

            else {
                if (j % 2 == 0) {
                    std::cout << "C";
                }

                else {
                    std::cout << ".";
                }
            }
        }

        if (i != n - 1) {
            std::cout << std::endl;
        }
    }

    return 0;
}
