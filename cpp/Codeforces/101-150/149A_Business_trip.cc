#include <iostream>
#include <string>
#include <sstream>
#include <vector>


template <typename T, typename CONT>
inline void quickSort(CONT& list, int first, int last) {
    int left = first;
    int right = last;
    T pivot = list[(left + right) / 2];

    if (first >= last) return;

    do {
        while (list[left] > pivot) ++left;
        while (list[right] < pivot) --right;

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


int main(int argc, char **argv) {
    int k = 0;
    std::string line = "";
    // Read the first line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> k;
    }

    std::vector<int> monthlyHeights;
    // Read the second line
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        for (int i = 0; i != 12; ++i) {
            int a = 0;
            ss >> a;

            monthlyHeights.push_back(a);
        }
    }

    quickSort<int, std::vector<int> >(monthlyHeights, 0, 12 - 1);

    int monthsCount = 0;
    int growthSoFar = 0;
    for (unsigned int i = 0; i != monthlyHeights.size(); ++i) {
        if (growthSoFar < k) {
            growthSoFar += monthlyHeights[i];
            ++monthsCount;
        }

        else {
            break;
        }
    }

    if (growthSoFar >= k) {
        std::cout << monthsCount;
    }

    else {
        std::cout << -1;
    }

    return 0;
}
