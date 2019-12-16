#include <iostream>
#include <string>
#include <sstream>
#include <vector>


class Sugar {
    public:
        Sugar();
        Sugar(int x, int y);
        virtual ~Sugar();

        int x;
        int y;
};


Sugar::Sugar() :
    x(0),
    y(0)
{

}


Sugar::Sugar(int x, int y) :
    x(x),
    y(y)
{

}


Sugar::~Sugar() {

}


int main(int argc, char **argv) {
    int n = 0;
    int s = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n >> s;
    }

    Sugar sugarArr[n];
    int sugarArrIdx = 0;
    // Read the next n lines
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        Sugar sugar;
        sugarArr[sugarArrIdx] = sugar;

        ss >> sugarArr[sugarArrIdx].x >> sugarArr[sugarArrIdx].y;
        ++sugarArrIdx;

        if (sugarArrIdx == n) break;
    }

    int maxChange = -1;
    bool tempMaxChange = false;
    // Logic starts here
    for (int i = 0; i != n; ++i) {
        if (sugarArr[i].x < s) {
            if (sugarArr[i].y != 0) {
                int change = 100 - sugarArr[i].y;

                if (change > maxChange) {
                    maxChange = change;
                }
            }

            else {
                tempMaxChange = true;
            }
        }

        else if (sugarArr[i].x == s){
            if (sugarArr[i].y == 0) {
                tempMaxChange = true;
            }
        }

    }

    if (maxChange != -1) {
        std::cout << maxChange;
    }

    else {
        if (tempMaxChange) {
            std::cout << 0;
        }

        else {
            std::cout << -1;
        }
    }

    return 0;
}
