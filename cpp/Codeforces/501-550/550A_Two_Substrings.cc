#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
typedef int64_t Int;
typedef uint64_t UInt;

int main(int argc, char **argv) {
    // // vector< bool > abIndex;
    // // vector< bool > baIndex;
    // //
    // // char c;
    // // char prevC;
    //
    //
    //
    // char c;
    // bool aFound = false;
    // bool bFound = false;
    // bool abFound = false;
    // bool baFound = false;
    // while ( cin.get( c ) ) {
    //     cout << c;
    //
    //     if ( c == 'A' ) {
    //         if ( bFound ) {
    //             if ( ! baFound ) {
    //                 baFound = true;
    //             }
    //         }
    //     } else if ( c == 'B' ) {
    //         if ( aFound ) {
    //             if ( ! abFound ) {
    //                 abFound = true;
    //             }
    //         }
    //     }
    // }







    string line = "";

    if ( getline( cin, line ) ) {
        bool abIndex[ line.size() ];
        bool baIndex[ line.size() ];
        // fill_n( abIndex, line.size(), false );
        // fill_n( baIndex, line.size(), false );

        for ( int i = 0; i < line.size() - 1; ++i ) {
            if ( ( line[ i ] == 'A' ) && ( line[ i + 1 ] == 'B' ) ) {
                abIndex[ i ] = true;
            } else {
                abIndex[ i ] = false;
            }

            if ( ( line[ i ] == 'B' ) && ( line[ i + 1 ] == 'A' ) ) {
                baIndex[ i ] = true;
            } else {
                baIndex[ i ] = false;
            }
        }

        string answer = "NO";
        for ( int i = 0; i < line.size() - 1; ++i ) {
            if ( ( abIndex[ i ] ) && ( i + 3 < line.size() ) ) {
                // AB appears first
                for ( int j = i + 2; j < line.size() - 1; ++j ) {
                    if ( baIndex[ j ] ) {
                        answer = "YES";
                        break;
                    }
                }
            } else if ( baIndex[ i ] ) {
                // BA appears first
                for ( int j = i + 2; j < line.size() - 1; ++j ) {
                    if ( abIndex[ j ] ) {
                        answer = "YES";
                        break;
                    }
                }
            }

            if ( answer == "YES" ) {
                break;
            }
        }

        cout << answer;
    }

    return 0;
}
