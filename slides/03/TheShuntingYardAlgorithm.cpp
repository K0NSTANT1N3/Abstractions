//
// Created by konstantine on 3/18/24.
//

#include "TheShuntingYardAlgorithm.h"

int TheShuntingYardAlgorithm::shuntingYard(string expression) {
    int ans = 0;
    stack<int> numbers;
    stack<char> operations;

    string newExpr = parseExpression(std::move(expression));
    for (int i = 0; i < newExpr.length(); i++) {
        tokenContainer tokCont = tokenCutter(newExpr, i);
        StringManipulation strMan;

        if (strMan.isInteger(tokCont.token)) {
            int num = strMan.convertToInteger(tokCont.token);
            numbers.push(num);
        } else {
            operations.push(tokCont.token[0]);
        }
    }
}

string TheShuntingYardAlgorithm::parseExpression(string expression) {
    string res = "";
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];
        if ((c >= '0' && c <= '9') || operands.find(c) != string::npos) {
            res += c;
        }
    }
    return res;
}

bool TheShuntingYardAlgorithm::isNumber(char c) {
    return c - '0' >= 0 && c - '0' <= 9;
}

TheShuntingYardAlgorithm::tokenContainer TheShuntingYardAlgorithm::tokenCutter(string expression, int curIndex) {
    tokenContainer tokCont;

    if (!isNumber(expression[curIndex])) {
        tokCont.token = expression[curIndex];
        tokCont.index = curIndex;
        return tokCont;
    }

    for (int i = curIndex; i < expression.length() && isNumber(expression[i]); i++) {
        tokCont.token += expression[i];
        tokCont.index = i;
    }
    return tokCont;
}


