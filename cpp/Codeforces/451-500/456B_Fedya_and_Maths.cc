#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include <cstdlib>


using namespace std;
typedef int64_t Int;
typedef uint64_t UInt;


int main(int argc, char **argv) {
    // Read the first line
    string numStr = "";
    if (getline(cin, numStr)) {

    }

    if ((numStr.length() == 1) && (numStr[0] == '0')) {
        cout << 4;
    }

    else {
        UInt lastTwoDigits = 0;

        if (numStr.length() == 1) {
            lastTwoDigits = numStr[numStr.length() - 1] - '0';
        }

        else {
            lastTwoDigits = 10 * (numStr[numStr.length() - 2] - '0');
            lastTwoDigits += numStr[numStr.length() - 1] - '0';
        }

        UInt end1 = 1;
        UInt end2 = 0;
        UInt end3 = 0;
        UInt end4 = 0;

        switch (lastTwoDigits % 4) {
            case 0:
                {
                    end2 = 6;
                    end3 = 1;
                    break;
                }

            case 1:
                {
                    end2 = 2;
                    end3 = 3;
                    break;
                }

            case 2:
                {
                    end2 = 4;
                    end3 = 9;
                    break;
                }

            case 3:
                {
                    end2 = 8;
                    end3 = 7;
                    break;
                }

            default:
                {
                    break;
                }
        }

        switch (lastTwoDigits % 2) {
            case 0:
                {
                    end4 = 6;
                    break;
                }

            case 1:
                {
                    end4 = 4;
                    break;
                }

            default:
                {
                    break;
                }
        }
        cout << (end1 + end2 + end3 + end4) % 5;
    }

    return 0;
}
