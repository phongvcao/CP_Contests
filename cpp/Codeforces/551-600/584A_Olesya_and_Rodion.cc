#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include <cmath>
#include <algorithm>


using namespace std;
typedef int64_t Int;
typedef uint64_t UInt;


std::string intToString(UInt n) {
    std::stringstream ss;
    ss << n;
    return ss.str();
}


int main(int argc, char **argv) {

    UInt n = 0, t = 0;
    cin >> n >> t;

    // Divisible by 2: Last digit divisible by 2
    // Divisible by 3: Sum of digits divisible by 3
    // Divisible by 4: Number formed by last 2 digits divisible by 4
    // Divisible by 5: Last digit 5 or 0
    // Divisible by 6: Divisible by both 2 & 3
    // Divisible by 7: Reverse the digits, then multiply them successively by 
    //                 1, 3, 2, 6, 4, 5, repeating as long as necessary.
    // Divisible by 8: Number formed by last 3 digits divisible by 8
    // Divisible by 9: Sum of digits divisible by 9
    // Divisible by 10: Last digit divisible by 3

    switch ( n ) {
        case 1: 
            {
                if ( t < 10 ) {
                    cout << t;
                }

                else {
                    cout << -1;
                }
                break;
            }

        case 2:
            {
                cout << 9 * t;
                break;
            }

        default: 
            {
                string numStr = "1";
                switch ( t ) {
                    case 2:
                    case 5:
                    case 10:
                        {
                            for ( UInt i = 0; i < n - 1; ++i ) {
                                numStr += "0";
                            }
                            cout << numStr;
                            break;
                        }

                    case 3:
                    case 9:
                    case 6:
                        {
                            numStr += "8";
                            for ( UInt i = 0; i < n - 2; ++i ) {
                                numStr += "0";
                            }
                            cout << numStr;
                            break;
                        }

                    case 4:
                    case 8:
                        {
                            if ( n == 3 ) {
                                cout << "128";
                            }

                            else {
                                for ( UInt i = 0; i < n - 4; ++i ) {
                                    numStr += "0";
                                }
                                numStr += "128";
                                cout << numStr;
                            }

                            break;
                        }

                    case 7:
                        {
                            UInt divArr[] = { 1, 3, 2, 6, 4, 5 };
                            UInt lastDigit = 7 - divArr[ n % 6 - 1 ];
                            for ( UInt i = 0; i < n - 2; ++i ) {
                                numStr += "0";
                            }
                            numStr += intToString( lastDigit );
                            cout << numStr;
                            break;
                        }

                    default: 
                        {
                            cout << -1;
                            break;
                        }
                }

                break;
            }
    }

    return 0;
}
