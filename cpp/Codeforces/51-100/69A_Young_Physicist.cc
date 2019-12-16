#include <iostream>
#include <string>
#include <sstream>
#include <vector>


class Vector {
    public:
        Vector();
        Vector(int x, int y, int z);
        virtual ~Vector();

        int x;
        int y;
        int z;
};


Vector::Vector() :
    x(0),
    y(0),
    z(0)
{

}


Vector::Vector(int x, int y, int z) :
    x(x),
    y(y),
    z(z)
{

}


Vector::~Vector() {

}


int main(int argc, char **argv) {
    int n = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> n;
    }

    Vector vectorsArr[n];
    int vectorsArrIdx = 0;
    // Read the next n lines
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        int x = 0;
        int y = 0;
        int z = 0;

        ss >> x >> y >> z;
        Vector vectorObj(x, y, z);
        vectorsArr[vectorsArrIdx++] = vectorObj;

        if (vectorsArrIdx == n) break;
    }

    int sumX = 0;
    int sumY = 0;
    int sumZ = 0;

    for (int i = 0; i != n; ++i) {
        sumX += vectorsArr[i].x;
        sumY += vectorsArr[i].y;
        sumZ += vectorsArr[i].z;
    }

    if ((sumX == 0) && (sumY == 0) && (sumZ == 0)) {
        std::cout << "YES";
    }

    else {
        std::cout << "NO";
    }

    return 0;
}
