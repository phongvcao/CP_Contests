#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdint.h>


class Laptop {
    public:
        Laptop();
        Laptop(int64_t price, int64_t quality);
        virtual ~Laptop();

        int64_t price;
        int64_t quality;
};


Laptop::Laptop() :
    price(0),
    quality(0)
{

}


Laptop::Laptop(int64_t price, int64_t quality) :
    price(price),
    quality(quality)
{

}


Laptop::~Laptop() {

}


void quickSort(std::vector<Laptop>& laptopVector, int64_t first, int64_t last) {
    int64_t left = first;
    int64_t right = last;
    Laptop pivot = laptopVector[(left + right) / 2];

    if (first >= last) return;

    do {
        while (laptopVector[left].price < pivot.price) ++left;
        while (laptopVector[right].price > pivot.price) --right;

        if (left <= right) {
            Laptop temp = laptopVector[left];
            laptopVector[left] = laptopVector[right];
            laptopVector[right] = temp;

            ++left;
            --right;
        }

    } while (left <= right);

    quickSort(laptopVector, first, right);
    quickSort(laptopVector, left, last);
}


int main(int argc, char **argv) {
    int64_t n = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n;
    }

    std::vector<Laptop> laptopVector;
    int64_t laptopVectorIdx = 0;
    // Read the next n lines
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        int64_t price = 0;
        int64_t quality = 0;

        ss >> price >> quality;

        Laptop laptop(price, quality);

        laptopVector.push_back(laptop);

        ++laptopVectorIdx;

        if (laptopVectorIdx == n) break;
    }

    // Logic starts here
    quickSort(laptopVector, 0, n - 1);

    for (int64_t i = 0; i != n - 1; ++i) {
        if (laptopVector[i].quality > laptopVector[i + 1].quality) {
            std::cout << "Happy Alex";
            return 0;
        }
    }

    std::cout << "Poor Alex";

    return 0;
}
