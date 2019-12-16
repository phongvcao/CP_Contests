#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    int n = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n;
    }

    int intArr[n];
    int readingIdx = 0;
    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        while (readingIdx < n) {
            ss >> intArr[readingIdx++];
        }
    }

    int walletArr[3] = { 0, 0, 0 };
    // Logic starts here
    for (int i = 0; i != n; ++i) {
        switch (intArr[i]) {
            case 25:
                {
                    ++walletArr[0];
                    break;
                }

            case 50:
                {
                    if (walletArr[0] == 0) {
                        std::cout << "NO";
                        return 0;
                    }

                    ++walletArr[1];
                    --walletArr[0];
                    break;
                }

            case 100:
                {
                    if (walletArr[0] == 0) {
                        std::cout << "NO";
                        return 0;
                    }

                    else {
                        if (walletArr[1] > 0) {
                            if (walletArr[0] > 0) {
                                --walletArr[0];
                                --walletArr[1];
                                ++walletArr[2];
                            }

                            else {
                                std::cout << "NO";
                                return 0;
                            }
                        }

                        else {
                            if (walletArr[0] >= 3) {
                                walletArr[0] -= 3;
                                ++walletArr[2];
                            }

                            else {
                                std::cout << "NO";
                                return 0;
                            }
                        }

                    }

                    break;
                }

            default:
                break;
        }
    }

    std::cout << "YES";

    return 0;
}
