#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int getNextRoundParticipantsCount(long long int n, long long int k, std::vector<long long int>& scoresVector) {
    int count = 0;
    long long int min = scoresVector[k - 1];


    for (unsigned int i = 0; i != scoresVector.size(); ++i) {
        if ((scoresVector[i] >= min) && (scoresVector[i] > 0)) {
            ++count;
        }

        else {
            break;
        }
    }

    return count;
}


int main(int argc, char **argv) {
    long long int n = 0;
    long long int k = 0;

    // Read the first line
    std::string line;
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        long long int i = 0;

        if (ss >> i) {
            n = i;
        }

        if (ss >> i) {
            k = i;
        }
    }

    // Read the second line
    std::vector<long long int> intVector;
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        long long int curInt = 0;

        while (ss >> curInt) {
            intVector.push_back(curInt);
        }
    }

    std::cout << getNextRoundParticipantsCount(n, k, intVector);

    return 0;
}
