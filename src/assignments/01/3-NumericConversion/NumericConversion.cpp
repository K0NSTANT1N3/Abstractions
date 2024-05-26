//
// Created by konstantine on 3/22/24.
//

#include "NumericConversion.h"

int NumericConversion::stringToInt(string str) {
    if (str.size() == 1)return str[0] - '0';
    int sign = 1;
    if (str[0] == '-') {
        sign = -1;
        str = str.substr(1, str.size() - 1);
    }

    string str1 = str.substr(0, str.size() - 1);
    int last = str[str.size() - 1] - '0';

    int res = stringToInt(str1) * 10 + last;
    return res * sign;
}

string NumericConversion::intToString(int n) {
    string sign = "";
    if (n < 0) {
        n = -n;
        sign = "-";
    }

    return sign + intToStringPositive(n);
}

string NumericConversion::intToStringPositive(int n) {
    if (n < 10 && n > 0) {
        char c = n;
        char symbol = c + '0';
        string str = string(1, symbol);
        return str;
    }
    if (n == 0) {
        string res = "0";
        return res;
    }

    int left = n / 10;
    int right = n % 10;

    return intToString(left) + intToString(right);
}