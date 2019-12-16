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

bool isVowel( char c ) {
    if ( ( c == 'U' ) || ( c == 'E' ) || ( c == 'O' ) || ( c == 'A' ) || ( c == 'I' ) || ( c == 'Y' ) ) {
        return true;
    }
    return false;
}

int main(int argc, char **argv) {
    Int index = 0;
    Int prevVowelIdx = -1;
    Int maxDist = -1;
    Int leftMostVowelIdx = -1;

    string line = "";

    if ( getline( cin, line ) ) {
        if ( line.size() == 1 ) {
            if ( isVowel( line[ 0 ] ) ) {
                maxDist = 1;
            }
        } else {

            while ( index < line.size() ) {
                if ( isVowel( line[ index ] ) ) {
                    if ( prevVowelIdx == -1 ) {
                        prevVowelIdx = index;
                        leftMostVowelIdx = index;
                    } else {
                        if ( maxDist == -1 ) {
                            maxDist = index - prevVowelIdx;
                        } else {
                            if ( maxDist < index - prevVowelIdx ) {
                                maxDist = index - prevVowelIdx;
                            }
                        }
                    }
                    prevVowelIdx = index;
                }

                ++index;
            }
        }
    }

    if ( leftMostVowelIdx != -1 ) {
        if ( maxDist < leftMostVowelIdx + 1 ) {
            maxDist = leftMostVowelIdx + 1;
        }
    }

    if ( prevVowelIdx != -1 ) {
        if ( maxDist < line.size() - prevVowelIdx ) {
            maxDist = line.size() - prevVowelIdx;
        }
    }
    
    if ( maxDist == -1 ) {
        maxDist = line.size() + 1;
    }

    cout << maxDist;

    return 0;
}
