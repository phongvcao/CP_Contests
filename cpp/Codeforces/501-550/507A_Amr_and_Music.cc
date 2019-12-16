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


class Instrument {
    public:
        Instrument();
        Instrument(Int index, Int value);
        virtual ~Instrument();

        Int index;
        Int value;
};


Instrument::Instrument() :
    index(-1),
    value(0)
{

}


Instrument::Instrument(Int index, Int value) :
    index(index),
    value(value)
{

}


Instrument::~Instrument() {

}


void quickSort(vector<Instrument>& instruVector, Int first, Int last) {
    Int left = first;
    Int right = last;
    Instrument pivot = instruVector[(left + right) / 2];

    if (first >= last) return;

    do {
        while (instruVector[left].value < pivot.value) ++left;
        while (instruVector[right].value > pivot.value) --right;

        if (left <= right) {
            Instrument temp = instruVector[left];
            instruVector[left] = instruVector[right];
            instruVector[right] = temp;

            ++left;
            --right;
        }

    } while (left <= right);

    quickSort(instruVector, first, right);
    quickSort(instruVector, left, last);
}


int main(int argc, char **argv) {
    Int n = 0;
    Int k = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);
        ss >> n >> k;
    }

    vector<Instrument> instruVector;
    Int instruIdx = 0;
    // Read the second line
    if (getline(cin, line)) {
        stringstream ss(line);

        while (instruIdx < n) {
            Instrument instru;
            instru.index = instruIdx;

            ss >> instru.value;

            instruVector.push_back(instru);

            ++instruIdx;
            if (instruIdx == n) break;
        }
    }

    // Logic starts here
    quickSort(instruVector, 0, n - 1);
    vector<Int> finalVector;

    for (Int i = 0; i < instruVector.size(); ++i) {
        if (k >= instruVector[i].value) {
            k -= instruVector[i].value;
            finalVector.push_back(instruVector[i].index);
        }

        else {
            break;
        }
    }

    if (finalVector.size() == 0) {
        cout << 0;
    }

    else {
        cout << finalVector.size() << endl;

        for (Int i = 0; i != finalVector.size(); ++i) {
            cout << finalVector[i] + 1;

            if (i < finalVector.size() - 1) {
                cout << " ";
            }
        }
    }


    return 0;
}
