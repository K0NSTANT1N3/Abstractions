//
// Created by konstantine on 3/17/24.
//

#include "StringManipulation.h"

string StringManipulation::reverseString(string s) {
    if (s.size() <= 1) return s;
    return reverseString(s.substr(1)) + s[0];
}

bool StringManipulation::isPalindrome(string s) {
    if (s.size() <= 1)return true;
    return s[0] == s[s.size() - 1] &&
           isPalindrome(s.substr(1, s.length() - 2));
}
