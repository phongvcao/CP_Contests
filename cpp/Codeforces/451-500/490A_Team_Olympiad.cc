#include <iostream>
#include <string>
#include <sstream>
#include <vector>


class Student {
    public:
        Student();
        Student(int index, int subject);
        virtual ~Student();

        Student& operator=(const Student& student);
        bool operator==(const Student& student);
        bool operator!=(const Student& student);
        bool operator>(const Student& student);
        bool operator<(const Student& student);
        bool operator>=(const Student& student);
        bool operator<=(const Student& student);

        int subject;
        int index;
};


Student::Student() :
    subject(1),
    index(1)
{

}


Student::Student(int index, int subject) :
    subject(subject),
    index(index)
{

}


Student::~Student() {

}


Student& Student::operator=(const Student& student) {
    this->subject = student.subject;
    this->index = student.index;

    return *this;
}

bool Student::operator==(const Student& student) {
    return (this->subject == student.subject);
}


bool Student::operator!=(const Student& student) {
    return (this->subject != student.subject);
}


bool Student::operator>(const Student& student) {
    return (this->subject > student.subject);
}


bool Student::operator<(const Student& student) {
    return (this->subject < student.subject);
}


bool Student::operator>=(const Student& student) {
    return (this->subject >= student.subject);
}


bool Student::operator<=(const Student& student) {
    return (this->subject <= student.subject);
}


void quickSort(Student *studentsArr, int first, int last) {
    int left = first;
    int right = last;
    Student pivot = studentsArr[(first + last) / 2];

    if (first >= last) return;

    do {
        while (studentsArr[left] < pivot) ++left;
        while (studentsArr[right] > pivot) --right;

        if (left <= right) {
            Student temp = studentsArr[left];
            studentsArr[left] = studentsArr[right];
            studentsArr[right] = temp;

            ++left;
            --right;
        }

    } while(left <= right);

    quickSort(studentsArr, first, right);
    quickSort(studentsArr, left, last);
}


void testQuickSort() {
    Student stud1(1, 1);
    Student stud2(2, 3);
    Student stud3(3, 1);
    Student stud4(4, 3);
    Student stud5(5, 2);
    Student stud6(6, 1);
    Student stud7(7, 2);

    Student studentsArr[7];

    studentsArr[0] = stud1;
    studentsArr[1] = stud2;
    studentsArr[2] = stud3;
    studentsArr[3] = stud4;
    studentsArr[4] = stud5;
    studentsArr[5] = stud6;
    studentsArr[6] = stud7;

    quickSort(studentsArr, 0, 6);

    for (int i = 0; i != 7; ++i) {
        std::cout << studentsArr[i].index << " " << studentsArr[i].subject << std::endl;
    }

}


int main(int argc, char **argv) {
    // testQuickSort();

    int n = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        ss >> n;
    }

    Student studentsArr[n];
    int studentsArrIdx = 0;
    int subjectsCountArr[3] = { 0, 0, 0 };
    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        while (studentsArrIdx < n) {
            int subject = 0;
            ss >> subject;
            Student stud(studentsArrIdx + 1, subject);

            studentsArr[studentsArrIdx++] = stud;

            switch (subject) {
                case 1:
                    {
                        ++subjectsCountArr[0];
                        break;
                    }

                case 2:
                    {
                        ++subjectsCountArr[1];
                        break;
                    }

                case 3:
                    {
                        ++subjectsCountArr[2];
                        break;
                    }

                default:
                    break;
            }
        }
    }

    // Logic starts here
    quickSort(studentsArr, 0, n - 1);

    int largestPossibleTeam = subjectsCountArr[0];
    for (int i = 0; i != 3; ++i) {
        if (subjectsCountArr[i] < largestPossibleTeam) {
            largestPossibleTeam = subjectsCountArr[i];
        }
    }

    std::cout << largestPossibleTeam;

    if (largestPossibleTeam != 0) {
        std::cout << std::endl;

        int curProgramsIdx = 0;
        int curMathsIdx = curProgramsIdx + subjectsCountArr[0];
        int curPEIdx = curMathsIdx + subjectsCountArr[1];
        for (int i = 0; i != largestPossibleTeam; ++i) {
            std::cout << studentsArr[curProgramsIdx++].index << " ";
            std::cout << studentsArr[curMathsIdx++].index << " ";
            std::cout << studentsArr[curPEIdx++].index;

            if (i != largestPossibleTeam - 1) {
                std::cout << std::endl;
            }
        }
    }

    return 0;
}
