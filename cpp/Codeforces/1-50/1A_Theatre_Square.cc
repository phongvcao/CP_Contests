#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    long long int n = 0;
    long long int m = 0;
    long long int a = 0;

    std::cin >> n >> m >> a;

    std::cout << ((n + a - 1) / a) * ((m + a - 1) / a);

    return 0;
}
