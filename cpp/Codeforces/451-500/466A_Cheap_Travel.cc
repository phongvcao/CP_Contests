#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    unsigned int n = 0;
    unsigned int m = 0;
    unsigned int a = 0;
    unsigned int b = 0;

    std::cin >> n >> m >> a >> b;

    unsigned minMoney = 0;
    if (n / m * b < n * a) {
        minMoney = n / m * b;
    }

    else {
        minMoney = n * a;
    }


    if (n % m == 0) {

    }

    else if (n % m * a < b) {
        minMoney += n % m * a;
    }

    else {
        minMoney += b;
    }

    std::cout << minMoney;

    return 0;
}
