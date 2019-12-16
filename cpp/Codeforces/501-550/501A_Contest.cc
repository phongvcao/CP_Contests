#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main(int argc, char **argv) {
    double a = 0;
    double b = 0;
    double c = 0;
    double d = 0;

    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> a >> b >> c >> d;
    }

    // Logic starts here
    // First calculate Misha
    double mishaFirstPoint = 3 * a / 10;
    double mishaSecondPoint = a - a / 250 * c;
    double mishaPoint = (mishaFirstPoint > mishaSecondPoint) ? mishaFirstPoint : mishaSecondPoint;

    double vasyaFirstPoint = 3 * b / 10;
    double vasyaSecondPoint = b - b / 250 * d;
    double vasyaPoint = (vasyaFirstPoint > vasyaSecondPoint) ? vasyaFirstPoint : vasyaSecondPoint;

    if (vasyaPoint > mishaPoint) {
        std::cout << "Vasya";
    }

    else if (vasyaPoint < mishaPoint) {
        std::cout << "Misha";
    }

    else {
        std::cout << "Tie";
    }

    return 0;
}


