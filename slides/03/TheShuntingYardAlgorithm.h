//
// Created by konstantine on 3/18/24.
//

#ifndef ABSTRACTIONS_THESHUNTINGYARDALGORITHM_H
#define ABSTRACTIONS_THESHUNTINGYARDALGORITHM_H

#include<iostream>
#include <tokenscanner.h>
#include<stack>
#include <utility>
#include "../../2016 practice problems/problem2/StringManipulation.h"

using namespace std;

class TheShuntingYardAlgorithm {
public:
    int shuntingYard(string expression);

private:
    string operands = "*/+-";

    struct tokenContainer {
        int index;
        string token;
        tokenContainer(){
            token = "";
            index = 0;
        }
    };

    string parseExpression(string expression);
    bool isNumber(char c);
    tokenContainer tokenCutter(string expression, int curIndex);


};

#endif //ABSTRACTIONS_THESHUNTINGYARDALGORITHM_H