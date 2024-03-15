//
// Created by konstantine on 3/15/24.
//

#ifndef ABSTRACTIONS_STRINGMANIPULATION_H
#define ABSTRACTIONS_STRINGMANIPULATION_H

#include<iostream>
using namespace std;


class StringManipulation : public error_code {
public:
    string swapMinWithFirst(string s);
    bool isInteger(string s);
    int convertToInteger(string s);
    int remainderMod7(string s);
};


#endif //ABSTRACTIONS_STRINGMANIPULATION_H
