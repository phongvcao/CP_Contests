#include <iostream>

bool isEvenParts(long long int w) {
    long long int quotient = w;
    long long int remainder = 0;

    if (quotient == 1) return false;
    if (quotient == 2) return false;
    if (quotient == 0) return false;

    if (quotient % 2 == 0) return true;

    return false;

    /* while (quotient > 1) {
        quotient = w / 2;
        remainder = w % 2;
        w /= 2; */

        /* std::cout << "Quotient: " << quotient << std::endl;
        std::cout << "Remainder: " << remainder << std::endl;
        std::cout << "W: " << w << std::endl; */

    /* if (remainder == 1) return false;
    }

    return true; */
}

/* bool isEvenParts(int w) {
    int quotient = w;
    int remainder = 0;

    while (quotient > 0) {
        quotient = w / 2;
        remainder = w % 2;
        w /= 2;

        if (remainder == 1) return false;
    }

    return true;
    } */

int main() {
    // long long int w;
    long long int w;

    std::cin >> w;

    if (isEvenParts(w)) {
        std::cout << "YES";
    }

    else {
        std::cout << "NO";
    }

    return 0;
}
