/*
 * File: Subsequences.cpp
 * ----------------------
 * Name: Konstantine Endeladze
 * This file is the starter project for the Subsequences problem
 * on Assignment #3.
 */

#include <iostream>
#include <string>
#include "console.h"

using namespace std;

/* Given two strings, returns whether the second string is a
 * subsequence of the first string.
 */
bool isSubsequence(string text, string subsequence);

int main() {
    //test here
    string text, subsequence;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter subsequence: ";
    cin >> subsequence;
    cout << isSubsequence(text, subsequence);
    return 0;
}

bool isSubsequence(string text, string subsequence) {
    /* base case */
    if (text.empty())return true;
    if (subsequence.empty())return false;

    /* recursive case */
    if (text[0] == subsequence[0]) {
        return isSubsequence(text.substr(1), subsequence.substr(1));
    }
    else {
        return isSubsequence(text, subsequence.substr(1));
    }
}
