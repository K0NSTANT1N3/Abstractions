//
// Created by konstantine on 3/15/24.
//

#include "StringManipulation.h"

string StringManipulation::swapMinWithFirst(string s) {
    if (s.size() == 0)return s;

    int minIndex = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[minIndex] > s[i]) {
            minIndex = i;
        }
    }
    string res = s;
    res[0] = s[minIndex];
    res[minIndex] = s[0];

    return res;
}

bool StringManipulation::isInteger(string s) {
    if (s.length() == 0) return true;

    return (s[0] >= '0' && s[0] <= '9') && isInteger(s.substr(1));
}

int StringManipulation::convertToInteger(string s) {
    if (s.size() == 0)return 0;

    return (convertToInteger(
            s.substr(0, s.size() - 1)) * 10
            + (s[s.size() - 1] - '0'));
}

int StringManipulation::remainderMod7(string s) {
    if(s.size() == 1)return (s[0] - '0') % 7;

    return (remainderMod7(s.substr(0, s.size() - 1)) * 3
        + (s[s.size() - 1]) - '0') % 7;
}


