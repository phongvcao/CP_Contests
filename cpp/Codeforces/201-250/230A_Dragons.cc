#include <iostream>
#include <string>
#include <sstream>
#include <vector>


template <typename T>
class Dragon {
    public:
        Dragon();
        Dragon(T strength, T bonus);
        virtual ~Dragon();

        int const compare(Dragon<T> const& dragon);
        Dragon<T>& operator=(const Dragon<T>& dragon);

        T strength;
        T bonus;
};


template <typename T>
std::ostream& operator<<(std::ostream& os, const Dragon<T>& dragon);


template <typename T>
Dragon<T>::Dragon() :
    strength(),
    bonus()
{

}


template <typename T>
Dragon<T>::Dragon(T strength, T bonus) :
    strength(strength),
    bonus(bonus)
{

}


template <typename T>
Dragon<T>::~Dragon() {

}


template <typename T>
Dragon<T>& Dragon<T>::operator=(const Dragon<T>& dragon) {
    if ((void*)this == (void*)&dragon) {
        return *this;
    }

    this->strength = dragon.strength;
    this->bonus = dragon.bonus;

    return *this;
}


template <typename T>
int const Dragon<T>::compare(Dragon<T> const& dragon) {
    int compareResult = 0;

    if (this->strength < dragon.strength) {
        compareResult = -1;
    }

    else if (this->strength > dragon.strength) {
        compareResult = 1;
    }

    else {
        if (this->bonus < dragon.bonus) {
            compareResult = 1;
        }

        else if (this->bonus > dragon.bonus) {
            compareResult = -1;
        }

        else {
            compareResult = 0;
        }
    }

    return compareResult;
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const Dragon<T>& dragon) {
    os << "(" << dragon.strength << ", " << dragon.bonus << ")";
    return os;
}


template <typename T, typename CONT>
inline void quickSort(CONT& list, int first, int last) {
    int left = first;
    int right = last;
    T pivot = list[(left + right) / 2];

    if (first >= last) return;

    do {
        while (list[left].compare(pivot) == -1) ++left;
        while (list[right].compare(pivot) == 1) --right;

        if (left <= right) {
            T temp = list[left];
            list[left] = list[right];
            list[right] = temp;

            ++left;
            --right;
        }

    } while (left <= right);

    quickSort<T, CONT>(list, first, right);
    quickSort<T, CONT>(list, left, last);
}


inline void testQuickSort() {
    int intArr[] = { 1, 99, 1, 90, 3, 33, 3, 55, 1, 99, 100, 0, 10, 1, 100, 100 };
    std::vector<Dragon<int> > dragonVector;

    for (unsigned int i = 0; i + 2 <= sizeof(intArr) / sizeof(int); i += 2) {
        Dragon<int> dragon(intArr[i], intArr[i + 1]);
        dragonVector.push_back(dragon);
    }

    quickSort<Dragon<int>, std::vector<Dragon<int> > >(dragonVector, 0, dragonVector.size() - 1);

    for (unsigned int i = 0; i != dragonVector.size(); ++i) {
        std::cout << dragonVector[i] << " ";
    }

    std::cout << std::endl;
}


inline void testAssignmentOperator() {
    Dragon<int> dragon(1, 99);
    Dragon<int> newDragon = dragon;

    std::cout << "newDragon stats: " << std::endl;
    std::cout << newDragon.strength << std::endl;
    std::cout << newDragon.bonus << std::endl;
}


int main(int argc, char **argv) {
    // testQuickSort();
    // testAssignmentOperator();

    int s = 0;
    int n = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> s >> n;
    }

    std::vector<Dragon<int> > dragonVector;
    // Read the next n lines
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        int strength = 0;
        int bonus = 0;
        ss >> strength >> bonus;

        Dragon<int> dragon(strength, bonus);

        dragonVector.push_back(dragon);

        --n;
        if (n == 0) break;
    }

    // Logic starts here
    quickSort<Dragon<int>, std::vector<Dragon<int> > >(dragonVector, 0, dragonVector.size() - 1);

    bool isDefeated = false;
    for (unsigned int i = 0; i != dragonVector.size(); ++i) {
        if (s <= dragonVector[i].strength) {
            isDefeated = true;
            break;
        }

        s += dragonVector[i].bonus;
    }

    if (isDefeated) {
        std::cout << "NO";
    }

    else {
        std::cout << "YES";
    }

    return 0;
}
