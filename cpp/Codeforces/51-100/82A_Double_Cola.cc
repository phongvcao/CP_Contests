#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    long long int n = 0;
    std::cin >> n;

    int namesCountArr[] = { 1, 1, 1, 1, 1 };
    std::string namesArr[] = { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };
    int lastPersonIdx = 0;

    while (n > 0) {
        for (unsigned int i = 0; i != sizeof(namesCountArr)/sizeof(int); ++i) {
            n -= namesCountArr[i];
            namesCountArr[i] *= 2;

            if (n <= 0) {
                lastPersonIdx = i;
                break;
            }
        }
    }

    std::cout << namesArr[lastPersonIdx];

    return 0;
}
