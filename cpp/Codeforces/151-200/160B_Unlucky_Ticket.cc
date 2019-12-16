#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include <cstdlib>


using namespace std;
typedef int64_t Int;
typedef uint64_t UInt;


void quickSort(string& str, Int first, Int last) {
    Int left = first;
    Int right = last;
    char pivot = str[(left + right) / 2];

    if (first >= last) return;

    do {
        while (str[left] < pivot) ++left;
        while (str[right] > pivot) --right;

        if (left <= right) {
            char temp = str[left];
            str[left] = str[right];
            str[right] = temp;

            ++left;
            --right;
        }

    } while (left <= right);

    quickSort(str, first, right);
    quickSort(str, left, last);
}


int main(int argc, char **argv) {
    Int n = 0;
    // Read the first line
    string line = "";
    if (getline(cin, line)) {
        stringstream ss(line);

        ss >> n;
    }

    string numStr = "";
    string firstHalf = "";
    string secondHalf = "";
    // Read the second line
    if (getline(cin, numStr)) {
        firstHalf = numStr.substr(0, n);
        secondHalf = numStr.substr(n);
    }

    quickSort(firstHalf, 0, n - 1);
    quickSort(secondHalf, 0, n - 1);

    if (firstHalf[0] > secondHalf[0]) {
        for (Int i = 0; i != n; ++i) {
            if (firstHalf[i] <= secondHalf[i]) {
                cout << "NO";
                return 0;
            }
        }
    }

    else if (firstHalf[0] < secondHalf[0]) {
        for (Int i = 0; i != n; ++i) {
            if (secondHalf[i] <= firstHalf[i]) {
                cout << "NO";
                return 0;
            }
        }

    }

    else {
        cout << "NO";
        return 0;
    }

    cout << "YES";

    return 0;
}
