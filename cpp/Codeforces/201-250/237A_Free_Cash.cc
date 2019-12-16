#include <iostream>
#include <string>
#include <sstream>
#include <vector>


class Customer {
    public:
        Customer();
        Customer(int h, int m);
        virtual ~Customer();

        int h;
        int m;

        bool equals(Customer& customer);
};


Customer::Customer() :
    h(0),
    m(0)
{

}


Customer::Customer(int h, int m) :
    h(h),
    m(m)
{

}

Customer::~Customer() {

}


bool Customer::equals(Customer& customer) {
    return (this->h == customer.h) && (this->m == customer.m);
}


int main(int argc, char **argv) {
    long long int n = 0;
    // Read the first line
    std::string line = "";
    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> n;
    }

    Customer customerArr[n];
    long long int customerArrIdx = 0;
    // Read the next n lines
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);

        int h = 0;
        int m = 0;
        ss >> h >> m;

        Customer customer(h, m);
        customerArr[customerArrIdx++] = customer;

        if (customerArrIdx == n) break;
    }

    // Logic starts here
    int minCashes = 1;
    for (int i = 0; i < n; ++i) {
        int curMinCashes = 1;

        if (customerArr[i].equals(customerArr[i + 1])) {
            ++curMinCashes;

            int j = i + 1;
            while ((j < n) && (customerArr[j].equals(customerArr[j + 1]))) {
                ++curMinCashes;
                ++j;
            }
            i = j - 1;
        }

        if (curMinCashes > minCashes) {
            minCashes = curMinCashes;
        }
    }

    std::cout << minCashes;

    return 0;
}
