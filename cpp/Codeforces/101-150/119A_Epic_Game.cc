#include <iostream>
#include <string>
#include <sstream>
#include <vector>


long long int gcd(long long int a, long long int b) {
    if (b == 0) return a;

    return gcd(b, a % b);
}


long long int gcd2(long long int a, long long int b) {
    while (b != 0) {
        long long int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}


long long int lcm(long long int a, long long int b) {
    return (a * b) / gcd2(a, b);
}


int main(int argc, char **argv) {
    long long int a = 0;
    long long int b = 0;
    long long int n = 0;

    std::cin >> a >> b >> n;

    int turnCount = 0;
    while (n >= 0) {
        if (turnCount % 2 == 0) {
            n -= gcd2(n, a);

            if (n < gcd2(n, b)) {
                break;
            }
        }

        else {
            n -= gcd2(n, b);

            if (n < gcd2(n, a)) {
                break;
            }
        }

        ++turnCount;
    }

    std::cout << turnCount % 2;

    return 0;
}
