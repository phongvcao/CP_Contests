#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <tr1/memory>


class Magnet {
    public:
        Magnet();
        Magnet(int left, int right);
        int left;
        int right;
};


Magnet::Magnet() :
    left(0),
    right(0)
{

}


Magnet::Magnet(int left, int right) :
    left(left),
    right(right)
{

}


int main(int argc, char **argv) {
    long long int n = 0;

    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> n;
    }

    std::vector<std::tr1::shared_ptr<Magnet> > magnetsVector;
    // Read the next n lines
    while (std::getline(std::cin, line)) {
        int left = line[0] - '0';
        int right = line[1] - '0';

        std::tr1::shared_ptr<Magnet> ptr(new Magnet(left, right));
        magnetsVector.push_back(ptr);

        --n;
        if (n == 0) break;
    }

    long long int blocksCount = 0;
    // Logic starts here
    for (unsigned int i = 0; i != magnetsVector.size() - 1; ++i) {
        if (magnetsVector[i]->right == magnetsVector[i + 1]->left) {
            ++blocksCount;
        }
    }

    std::cout << ++blocksCount;

    return 0;
}
