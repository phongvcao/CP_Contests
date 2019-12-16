#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>


typedef struct Moment Moment;

struct Moment {
    long long int start;
    long long int end;
};


int main(int argc, char **argv) {
    long long int n = 0;
    long long int x = 0;

    // Read the first line
    std::string line;
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n >> x;
    }

    Moment* momentArr[n];
    int momentArrIdx = 0;
    // Read the next n lines
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        momentArr[momentArrIdx] = (Moment*)malloc(sizeof(Moment));
        ss >> momentArr[momentArrIdx]->start >> momentArr[momentArrIdx]->end;

        ++momentArrIdx;
        if (momentArrIdx == n) break;
    }

    long long int minutesCount = 0;
    long long int curPos = 1;
    for (unsigned int i = 0; i != n; ++i) {
        while (curPos + x <= momentArr[i]->start) {
            curPos += x;
        }

        minutesCount += momentArr[i]->end + 1 - curPos;
        curPos = momentArr[i]->end + 1;

        // std::cout << "curPos: " << curPos << std::endl;
        // std::cout << "momentArr[i]->end: " << momentArr[i]->end << std::endl;
        // std::cout << "minutesCount: " << minutesCount << std::endl;
    }

    std::cout << minutesCount;

    return 0;
}
