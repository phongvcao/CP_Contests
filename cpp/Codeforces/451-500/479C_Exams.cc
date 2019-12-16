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


class Exam {
    public:
        Exam();
        Exam(UInt a, UInt b);
        virtual ~Exam();

        int compare(const Exam& exam);

        UInt a;
        UInt b;
};


Exam::Exam() :
    a(0),
    b(0)
{

}


Exam::Exam(UInt a, UInt b) :
    a(a),
    b(b)
{

}


Exam::~Exam() {

}


int Exam::compare(const Exam& exam) {
    if (this->a < exam.a) {
        return -1;
    }

    else if (this->a > exam.a) {
        return 1;
    }

    else {
        if (this->b < exam.b) {
            return -1;
        }

        else if (this->b > exam.b) {
            return 1;
        }

        else {
            return 0;
        }
    }
}


void quickSort(std::vector<Exam>& examsVector, Int first, Int last) {
    Int left = first;
    Int right = last;
    Exam pivot = examsVector[(left + right) / 2];

    if (first >= last) return;

    do {
        while (examsVector[left].compare(pivot) == -1) ++left;
        while (examsVector[right].compare(pivot) == 1) --right;

        if (left <= right) {
            Exam temp = examsVector[left];
            examsVector[left] = examsVector[right];
            examsVector[right] = temp;

            ++left;
            --right;
        }

    } while (left <= right);

    quickSort(examsVector, first, right);
    quickSort(examsVector, left, last);
}


int main(int argc, char **argv) {
    Int n = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n;
    }

    vector<Exam> examsVector;
    Int examsIdx = 0;
    // Read the next n lines
    while (getline(cin, line)) {
        stringstream ss(line);

        Exam exam;
        ss >> exam.a >> exam.b;

        examsVector.push_back(exam);

        ++examsIdx;
        if (examsIdx == n) break;
    }

    // Logic starts here
    quickSort(examsVector, 0, n - 1);

    UInt smallestExamDate = (examsVector[0].a > examsVector[0].b) ? examsVector[0].b : examsVector[0].a;
    if (examsVector.size() > 1) {
        for (Int i = 1; i < n; ++i) {
            if ((smallestExamDate <= examsVector[i].a) && (smallestExamDate <= examsVector[i].b)) {
                smallestExamDate = (examsVector[i].a <= examsVector[i].b) ? examsVector[i].a : examsVector[i].b;
            }

            else {
                if (smallestExamDate <= examsVector[i].a) {
                    smallestExamDate = examsVector[i].a;
                }

                else {
                    smallestExamDate = examsVector[i].b;
                }
            }
        }
    }

    cout << smallestExamDate;

    return 0;
}
