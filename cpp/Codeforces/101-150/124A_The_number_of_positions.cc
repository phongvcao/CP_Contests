#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    int n = 0;
    int a = 0;
    int b = 0;

    std::cin >> n >> a >> b;

    // front >= a
    // behind <= b
    int positionsCount = 0;
    for (int i = 0; i != b + 1; ++i) {
        if (n - i - 1 >= a) {
            ++positionsCount;
        }
    }

    std::cout << positionsCount;

    return 0;
}
