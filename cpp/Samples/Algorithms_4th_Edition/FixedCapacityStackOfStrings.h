#ifndef FIXEDCAPACITYSTACKOFSTRINGS_H
#define FIXEDCAPACITYSTACKOFSTRINGS_H

#include <iostream>

class FixedCapacityStackOfStrings
{
 public:
    FixedCapacityStackOfStrings();
    FixedCapacityStackOfStrings( int cap );
    virtual ~FixedCapacityStackOfStrings();

    bool isEmpty();
    int size();
    void push( std::string item );
    std::string pop();

 private:
    std::string* a;
    int N;
};

#endif // FIXEDCAPACITYSTACKOFSTRINGS_H
