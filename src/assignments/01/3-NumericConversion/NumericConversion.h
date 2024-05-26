//
// Created by konstantine on 3/22/24.
//

#ifndef ABSTRACTIONS_NUMERICCONVERSION_H
#define ABSTRACTIONS_NUMERICCONVERSION_H

#include<iostream>
#include<string>

using namespace std;

class NumericConversion {
private:
    //coonverts positive int to string
    string intToStringPositive(int n);

public:
    //main function that converts int to string
    string intToString(int n);

    // converts string(it must be legally integer format or program crashes) into int
    int stringToInt(string str);
};

#endif //ABSTRACTIONS_NUMERICCONVERSION_H