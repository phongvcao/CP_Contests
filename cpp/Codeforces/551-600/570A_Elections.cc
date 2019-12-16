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
    // m is number of cities, n is number of candidates
    UInt n = 0, m = 0;

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> n >> m;
    }

    UInt intArr[ n ];
    fill_n( intArr, n, 0 );
    for ( int i = 0; i < m; ++i ) {
        if ( getline( cin, line ) ) {
            stringstream ss( line );
            UInt max = 0;
            UInt maxIdx = 0;

            for ( int j = 0; j < n; ++j ) {
                UInt vote = 0;
                ss >> vote;

                if ( vote > max ) {
                    max = vote;
                    maxIdx = j;
                }
            }

            // // DEBUG
            // cout << "DEBUG: i: " << i << "; maxIdx: " << maxIdx << endl;
            // // END OF DEBUG

            // Candidate maxIdx won the election of city i.
            ++intArr[ maxIdx ];
        
        }
    }

    UInt winnerVote = intArr[ 0 ];
    UInt winnerIdx = 0;
    for ( int i = 0; i < n; ++i ) {
        if ( intArr[ i ] > winnerVote ) {
            winnerIdx = i;
            winnerVote = intArr[ winnerIdx ];
        }
    }

    cout << winnerIdx + 1;

    return 0;
}
