//
// Created by konstantine on 3/18/24.
//

#ifndef ABSTRACTIONS_THESHUNTINGYARDALGORITHM_H
#define ABSTRACTIONS_THESHUNTINGYARDALGORITHM_H

#include<iostream>
#include "tokenscanner.h"
#include<stack>
#include <utility>
#include "../../../2016-practice-problems/02/StringManipulation.h"
#include "../../../additional/recursion/Arithmetics.h"

using namespace std;

class TheShuntingYardAlgorithm {
public:
    int shuntingYard(string expression);

private:
    string operands = "*/+-^()";

    struct tokenContainer {
        int index;
        string token;
        tokenContainer(){
            token = "";
            index = 0;
        }
    };

    struct stackPair{
        stack<int> numbers;
        stack<char> operations;
        stackPair(){
            stack<int> numbers = stack<int>();
            stack<char> operations = stack<char>();
        }
    };

    string parseExpression(string expression);
    tokenContainer tokenCutter(string expression, int curIndex);
    void calculateRemaining(stack<int>& numbers, stack<char>& operations, char symbol);
    int evaluateTwo(int num1, int num2, char symbol);
    bool isDigit(char c);
    int operationRank(char c);
    bool hasGreaterRank(char a, char b);
};

#endif //ABSTRACTIONS_THESHUNTINGYARDALGORITHM_H