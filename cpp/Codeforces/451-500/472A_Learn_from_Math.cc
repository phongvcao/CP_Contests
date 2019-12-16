#include <iostream>
#include <string>
#include <sstream>
#include <vector>


void fillSieveOfEratosthenes(bool *arr, int size) {
    int i = 2;
    while (i * i < size) {
        // Mark out all multiples of i
        for (int j = i + i; j <= size; j += i) {
            arr[j] = false;
        }

        // Find the next i
        for (int j = i + 1; j <= size; ++j) {
            if (arr[j]) {
                i = j;
                break;
            }
        }
        // std::cout << "Next i: " << i << std::endl;
    }
}


int main(int argc, char **argv) {
    int primeArrSize = 1000001;
    bool primeArr[primeArrSize];
    for (int i = 0; i != primeArrSize; ++i) {
        primeArr[i] = true;
    }

    fillSieveOfEratosthenes(primeArr, primeArrSize);

    /* for (int i = 2; i != 20; ++i) {
        if (primeArr[i]) {
            std::cout << i << " ";
        }
        } */

    int n;
    std::cin >> n;

    for (int i = 4; i != n + 1; ++i) {
        if ((!primeArr[i]) && (!primeArr[n - i])) {
            std::cout << i << " " << n - i;
            break;
        }
    }

    return 0;
}
