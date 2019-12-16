#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include <cmath>


using namespace std;
typedef int64_t Int;
typedef uint64_t UInt;


class Person {
    public:
        Person();
        Person(string first, string last);
        virtual ~Person();

        string first;
        string last;
};


Person::Person() :
    first(""),
    last("")
{

}


Person::Person(string first, string last) :
    first(first),
    last(last)
{

}


Person::~Person() {

}


int main(int argc, char **argv) {
    UInt n = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n;
    }

    vector<Person> ppVector;
    UInt lineIdx = 0;
    // Read the next n lines
    while (getline(cin, line)) {
        stringstream ss(line);

        Person person;
        ss >> person.first >> person.last;
        ppVector.push_back(person);

        ++lineIdx;
        if (lineIdx == n) break;
    }

    UInt indexArr[n];
    UInt indexArrIdx = 0;
    // Read the next line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (indexArrIdx < n) {
            ss >> indexArr[indexArrIdx++];
            --indexArr[indexArrIdx - 1];
        }
    }

    vector<string> trueHandles;
    string smallestName = "";


    // Logic starts here
    for (UInt i = 0; i != n; ++i) {
        string first = ppVector[indexArr[i]].first;
        string last = ppVector[indexArr[i]].last;

        if (i > 0) {
            Int compareResult = first.compare(last);
            compareResult /= abs(compareResult);

            switch (compareResult) {
                case -1:
                    {
                        Int compareFirstPrev = first.compare(trueHandles[i - 1]);
                        compareFirstPrev /= abs(compareFirstPrev);

                        if (compareFirstPrev == 1) {
                            trueHandles.push_back(first);
                        }

                        else {
                            Int compareLastPrev = last.compare(trueHandles[i - 1]);
                            compareLastPrev /= abs(compareLastPrev);

                            if (compareLastPrev == 1) {
                                trueHandles.push_back(last);
                            }

                            else {
                                cout << "NO";
                                return 0;
                            }
                        }

                        break;
                    }

                case 1:
                    {
                        Int compareLastPrev = last.compare(trueHandles[i - 1]);
                        compareLastPrev /= abs(compareLastPrev);

                        if (compareLastPrev == 1) {
                            trueHandles.push_back(last);
                        }

                        else {
                            Int compareFirstPrev = first.compare(trueHandles[i - 1]);
                            compareFirstPrev /= abs(compareFirstPrev);

                            if (compareFirstPrev == 1) {
                                trueHandles.push_back(first);
                            }

                            else {
                                cout << "NO";
                                return 0;
                            }
                        }

                        break;
                    }

                case 0:
                    {
                        break;
                    }

                default:
                    {
                        break;
                    }
            }
        }

        else {
            Int compareResult = first.compare(last);
            compareResult /= abs(compareResult);

            switch (compareResult) {
                case -1:
                    {
                        trueHandles.push_back(first);
                        break;
                    }

                case 1:
                    {
                        trueHandles.push_back(last);
                        break;
                    }

                case 0:
                    {
                        break;
                    }

                default:
                    {
                        break;
                    }

            }
        }

    }

    cout << "YES";

    return 0;
}
