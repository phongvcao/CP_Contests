#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>


int main(int argc, char **argv) {
    long long int n = 0;
    std::cin >> n;
    long long int sum = 0;

    sum += n / 2;

    if (n % 2 != 0) {
        sum += -1 * n;
    }

    /* for (long long int i = 1; i != n + 1; ++i) {
        sum += ((long long int)pow(-1, i)) * i;
        } */

    std::cout << sum;

    return 0;
}
