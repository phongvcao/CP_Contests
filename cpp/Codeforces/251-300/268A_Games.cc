#include <iostream>
#include <string>
#include <sstream>
#include <vector>


class TeamUniform {
    public:
        TeamUniform();
        TeamUniform(int h, int a);
        int h;
        int a;
};


TeamUniform::TeamUniform() :
    h(0),
    a(0)
{

}


TeamUniform::TeamUniform(int h, int a) :
    h(h),
    a(a)
{

}


int main(int argc, char **argv) {
    int n = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> n;
    }

    std::vector<TeamUniform> teamUnisVector;
    // Read the next n lines
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        TeamUniform teamUniform;
        ss >> teamUniform.h >> teamUniform.a;
        teamUnisVector.push_back(teamUniform);

        --n;

        if (n == 0) break;
    }

    int hostsInGuestUniCount = 0;
    // Logic starts here
    for (unsigned int i = 0; i != teamUnisVector.size(); ++i) {
        for (unsigned int j = 0; j != teamUnisVector.size(); ++j) {
            if (i != j) {
                if (teamUnisVector[i].h == teamUnisVector[j].a) {
                    ++hostsInGuestUniCount;
                }
            }
        }
    }

    std::cout << hostsInGuestUniCount;

    return 0;
}
