#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include <cmath>


using namespace std;
typedef int64_t Int;
typedef uint64_t UInt;


int main(int argc, char **argv) {
    double x = 0;
    double y = 0;
    cin >> x >> y;

    // Solve the problem using y = a * x + b
    // If (x, y) belongs to Quadrant I & III
    if (x * y > 0) {
        double a = -1;

        // Find b
        double b = y - a * x;

        // Find (x, 0)
        double x0 = (0 - b) / a;
        // Find (0, y)
        double y0 = a * 0 + b;

        if (x0 != (Int)x0) {
            Int newX1 = (Int)x0 + 1;
            Int newY1 = 0;
            Int newX2 = 0;
            Int newY2 = ((Int)x0) * ((Int)a) + (Int)b;

            if (newX1 < newX2) {
                cout << newX1 << " " << newY1 << " " << newX2 << " " << newY2;
            }

            else {
                cout << newX2 << " " << newY2 << " " << newX1 << " " << newY1;
            }

        }

        else {
            Int newX1 = (Int)x0;
            Int newY1 = 0;
            Int newX2 = 0;
            Int newY2 = (Int)y0;

            if (newX1 < newX2) {
                cout << newX1 << " " << newY1 << " " << newX2 << " " << newY2;
            }

            else {
                cout << newX2 << " " << newY2 << " " << newX1 << " " << newY1;
            }

        }
    }

    // If (x, y) belongs to Quadrant II & IV
    else {
        double a = 1;

        // Find b
        double b = y - a * x;

        // Find (x, 0)
        double x0 = (0 - b) / a;
        // Find (0, y)
        double y0 = a * 0 + b;

        if (x0 != (Int)x0) {
            Int newX1 = (Int)x0 + 1;
            Int newY1 = 0;
            Int newX2 = 0;
            Int newY2 = ((Int)x0) * ((Int)a) + (Int)b;

            if (newX1 < newX2) {
                cout << newX1 << " " << newY1 << " " << newX2 << " " << newY2;
            }

            else {
                cout << newX2 << " " << newY2 << " " << newX1 << " " << newY1;
            }
        }

        else {
            Int newX1 = (Int)x0;
            Int newY1 = 0;
            Int newX2 = 0;
            Int newY2 = (Int)y0;

            if (newX1 < newX2) {
                cout << newX1 << " " << newY1 << " " << newX2 << " " << newY2;
            }

            else {
                cout << newX2 << " " << newY2 << " " << newX1 << " " << newY1;
            }
        }
    }


    return 0;
}
