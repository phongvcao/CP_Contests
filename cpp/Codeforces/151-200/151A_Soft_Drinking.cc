#include <iostream>
#include <string>
#include <sstream>
#include <vector>


int main(int argc, char **argv) {
    int n = 0;
    int k = 0;
    int l = 0;
    int c = 0;
    int d = 0;
    int p = 0;
    int nl = 0;
    int np = 0;
    // Read the first line
    std::cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int totalDrink = k * l;
    int totalLimeSlices = c * d;
    int maxToastsDrinkWise = totalDrink / nl;
    int maxToastsLimeWise = totalLimeSlices;
    int maxToastsSaltWise = p / np;

    int intArr[3] = { maxToastsDrinkWise, maxToastsLimeWise, maxToastsSaltWise };

    int minToasts = intArr[0];
    for (int i = 1; i != 3; ++i) {
        if (intArr[i] < minToasts) {
            minToasts = intArr[i];
        }
    }

    std::cout << minToasts / n;

    return 0;
}
