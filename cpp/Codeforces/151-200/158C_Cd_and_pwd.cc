#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>


using namespace std;
typedef int64_t Int;


int main(int argc, char **argv) {
    Int n = 0;
    // Read first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n;
    }

    vector<string> trackingVector;
    vector<string> outputVector;
    Int lineIdx = 0;
    // Read the next n lines
    while (getline(cin, line)) {
        if (line[0] == 'c') {
            string argStr = line.substr(3, line.length());

            if (argStr[0] == '/') {
                if (argStr.length() == 1) {
                    argStr = argStr.substr(1, argStr.length());
                }

                else {
                    trackingVector.clear();
                    argStr = argStr.substr(1, argStr.length());
                }
            }

            stringstream ss(argStr);
            string token = "";

            while (getline(ss, token, '/')) {
                if (token.compare("..") == 0) {
                    if (trackingVector.size() > 0) {
                        trackingVector.erase(trackingVector.end() - 1);
                    }
                }

                else {
                    trackingVector.push_back(token);
                }
            }
        }

        else {
            string output = "/";
            for (Int i = 0; i != trackingVector.size(); ++i) {
                output += trackingVector[i] + "/";

                // if (i < trackingVector.size() - 1) {
                //     output += "/";
                // }
            }
            outputVector.push_back(output);
        }

        ++lineIdx;
        if (lineIdx == n) break;
    }

    for (int i = 0; i != outputVector.size(); ++i) {
        cout << outputVector[i];

        if (i < outputVector.size() - 1) {
            cout << endl;
        }
    }

    return 0;
}
