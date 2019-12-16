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


int main(int argc, char **argv) {
    string line = "";
    UInt n = 0;
    UInt k = 0;

    if ( getline( cin, line ) ) {
        stringstream ss( line );

        ss >> n >> k;
    }

    if ( getline( cin, line ) ) {
        stringstream ss( line );

        // if ( k == 150000 ) {
        //     cout << "DEBUG: STEP 0" << endl;
        // }

        UInt intArr[ n ];

        // if ( k == 150000 ) {
        //     cout << "DEBUG: STEP 1" << endl;
        // }

        UInt sumArr[ n - k + 1 ];

        // if ( k == 150000 ) {
        //     cout << "DEBUG: STEP 2" << endl;
        // }


        UInt sum = 0;
        UInt minSum = 0;
        UInt minSumIdx = 0;

        // if ( k == 150000 ) {
        //     cout << "DEBUG: STEP 3" << endl;
        // }

        for ( int i = 0; i < n; ++i ) {
            UInt curNum = 0;
            ss >> curNum;
            intArr[ i ] = curNum;
            sum += curNum;

            if ( i >= k ) {

                // if ( k == 150000 ) {
                //     cout << "DEBUG: STEP 3.1" << endl;
                // }

                sumArr[ i - ( k - 1 ) ] = sumArr[ i - ( k - 1 ) - 1 ] + curNum - intArr[ i - ( k - 1 ) - 1 ];
            } else if ( i == k - 1 ) {

                // if ( k == 150000 ) {
                //     cout << "DEBUG: STEP 3.2" << endl;
                // }

                sumArr[ i - ( k - 1 ) ] = sum;
            }
            
            if ( i >= k - 1 ) {
                if ( ( sumArr[ i - ( k - 1 ) ] < minSum ) || ( minSum == 0 ) ) {
                    minSum = sumArr[ i - ( k - 1 ) ];
                    minSumIdx = i - ( k - 1 );
                }
            }
        }

        // if ( k == 150000 ) {
        //     cout << "DEBUG: STEP 4" << endl;
        // }


        // // DEBUG
        // for ( int i = 0; i < n - k; ++i ) {
        //     cout << "DEBUG: sumArr[ " << i << " ]: " << sumArr[ i ] << "; minSum: " << minSum << "; minSumIdx: " << minSumIdx << endl;
        // }
        // // END OF DEBUG
        cout << minSumIdx + 1;
    }




    // if ( getline( cin, line ) ) {
    //     stringstream ss( line );
    //     UInt intArr[ n ];
    //
    //     for ( int i = 0; i < n; ++i ) {
    //         ss >> intArr[ i ];
    //     }
    //
    //     UInt minSum = 0;
    //     UInt minSumIdx = 0;
    //     for ( int i = 0; i < n - k; ++i ) {
    //         UInt sum = 0;
    //         for ( int j = i; j < i + k; ++j ) {
    //             sum += intArr[ j ];
    //         }
    //
    //         if ( ( sum < minSum ) || ( minSum == 0 ) ) {
    //             minSum = sum;
    //             minSumIdx = i;
    //         }
    //
    //         // // DEBUG
    //         // cout << "DEBUG: sum: " << sum << "; i: " << i << "; minSum: " << minSum << "; minSumIdx: " << minSumIdx << endl;
    //         // // END OF DEBUG
    //     }
    //
    //     cout << minSumIdx + 1;
    // }

    return 0;
}
