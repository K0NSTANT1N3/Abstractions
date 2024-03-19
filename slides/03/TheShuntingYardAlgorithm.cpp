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
            calculateRemaining(numbers, operations, tokCont.token[0]);
        }
        i = tokCont.index;
    }
    calculateRemaining(numbers, operations, '0');
    operations.pop();
    ans = numbers.top();
    return ans;
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

bool TheShuntingYardAlgorithm::isDigit(char c) {
    return c - '0' >= 0 && c - '0' <= 9;
}

TheShuntingYardAlgorithm::tokenContainer TheShuntingYardAlgorithm::tokenCutter(string expression, int curIndex) {
    tokenContainer tokCont;

    if (!isDigit(expression[curIndex])) {
        tokCont.token = expression[curIndex];
        tokCont.index = curIndex;
        return tokCont;
    }

    for (int i = curIndex; i < expression.length() && isDigit(expression[i]); i++) {
        tokCont.token += expression[i];
        tokCont.index = i;
    }
    return tokCont;
}

void TheShuntingYardAlgorithm::calculateRemaining(stack<int> &numbers, stack<char> &operations, char symbol) {
    while (!operations.empty() && (symbol == '0' || !hasGreaterRank(symbol, operations.top()))) {
        int b = numbers.top();
        numbers.pop();
        int a = numbers.top();
        numbers.pop();
        char c = operations.top();
        operations.pop();

        int ans = evaluateTwo(a, b, c);
        numbers.push(ans);
    }
    operations.push(symbol);
}

int TheShuntingYardAlgorithm::operationRank(char c) {
    if (c == '+' || c == '-')return 1;
    if (c == '*' || c == '/')return 2;
    if (c == '^')return 3;
    return 0;
}

bool TheShuntingYardAlgorithm::hasGreaterRank(char a, char b) {
    return operationRank(a) > operationRank(b);
}

int TheShuntingYardAlgorithm::evaluateTwo(int num1, int num2, char symbol) {
    if (symbol == '^') {
        Arithmetics aritm;
        return aritm.fastExponenting(num1, num2);
    }
    if (symbol == '+') return num1 + num2;
    if (symbol == '-') return num1 - num2;
    if (symbol == '*') return num1 * num2;
    if (symbol == '/') return num1 / num2;
    return 0;
}
