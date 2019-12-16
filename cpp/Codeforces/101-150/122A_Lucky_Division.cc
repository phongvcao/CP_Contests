#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>


int stringToInt(std::string str) {
    std::stringstream ss(str);
    int returnInt = 0;
    ss >> returnInt;
    return returnInt;
}


void generateAllPermutationsSet(std::set<std::string>& set, std::string str1, std::string str2) {
    for (unsigned int i = 0; i != str1.length(); ++i) {
        std::string newStr1 = str1.substr(0, i) + str1.substr(i + 1, str1.length());
        std::string newStr2 = str2 + str1[i];
        set.insert(newStr2);
        generateAllPermutationsSet(set, newStr1, newStr2);
    }
}


void generateAllPermutationsVector(std::vector<std::string>& vector, std::string str1, std::string str2) {
    for (unsigned int i = 0; i != str1.length(); ++i) {
        std::string newStr1 = str1.substr(0, i) + str1.substr(i + 1, str1.length());
        std::string newStr2 = str2 + str1[i];
        vector.push_back(newStr2);
        generateAllPermutationsVector(vector, newStr1, newStr2);
    }
}


void generatePermutations(std::vector<std::string>& vector, std::string str1, std::string str2) {
    if (str1.empty()) vector.push_back(str2);

    for (unsigned int i = 0; i != str1.length(); ++i) {
        std::string newStr1 = str1.substr(0, i) + str1.substr(i + 1, str1.length());
        std::string newStr2 = str2 + str1[i];
        vector.push_back(newStr2);
        generateAllPermutationsVector(vector, newStr1, newStr2);
    }
}


void testGeneratePermutations() {
    std::cout << "testGeneratePermutations(): " << std::endl;
    std::vector<std::string> strVector;
    generatePermutations(strVector, "abc", "");
    for (unsigned int i = 0; i != strVector.size(); ++i) {
        std::cout << strVector[i] << std::endl;
    }
}


void testGenerateAllPermutationsSet() {
    std::cout << "testGenerateAllPermutationsSet(): " << std::endl;
    std::set<std::string> strSet;
    generateAllPermutationsSet(strSet, "abc", "");
    for (std::set<std::string>::iterator iter = strSet.begin(); iter != strSet.end(); ++iter) {
        std::cout << *iter << std::endl;
    }
}


void testGenerateAllPermutationsVector() {
    std::cout << "testGenerateAllPermutationsVector(): " << std::endl;
    std::vector<std::string> anotherStrVector;
    generateAllPermutationsVector(anotherStrVector, "abc", "");
    for (unsigned int i = 0; i != anotherStrVector.size(); ++i) {
        std::cout << anotherStrVector[i] << std::endl;
    }
}


int main(int argc, char **argv) {
    /* testGeneratePermutations();
    testGenerateAllPermutationsSet();
    testGenerateAllPermutationsVector(); */

    std::set<std::string> luckyNumbersSet;

    generateAllPermutationsSet(luckyNumbersSet, "444", "");
    generateAllPermutationsSet(luckyNumbersSet, "447", "");
    generateAllPermutationsSet(luckyNumbersSet, "477", "");
    generateAllPermutationsSet(luckyNumbersSet, "777", "");

    int n = 0;
    std::cin >> n;
    bool isFound = false;

    for (std::set<std::string>::iterator iter = luckyNumbersSet.begin(); iter != luckyNumbersSet.end(); ++iter) {
        if (n % stringToInt(*iter) == 0) {
            isFound = true;
            break;
        }
    }

    if (isFound) {
        std::cout << "YES";
    }

    else {
        std::cout << "NO";
    }

    return 0;
}
