#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    int resultCount = 0;
    int loops = (n < m) ? n : m;
    int other = (n >= m) ? n : m;

    for (int i = 0; i != loops + 1; ++i) {
        if (loops - i * i >= 0) {
            if (i + (loops - i * i) * (loops - i * i) == other) {
                ++resultCount;
            }
        }
    }

    std::cout << resultCount;

    return 0;
}
