//
// Created by konstantine on 4/8/24.
//

#ifndef ABSTRACTIONS_RECURSION_H
#define ABSTRACTIONS_RECURSION_H

#include <vector>
#include "iostream"

using namespace std;

class Recursion {
public:
    int findMin(vector<int> &vec, int start);
    bool canSumUpWithUnits(int ammount, vector<int>& units);
    bool canSumUpWitUniqueUnits(int amount, vector<int> &units, int index = 0);
    /* Additional */
    int minDifference(vector<int> &vec, int startIndex = 0, int d = 0);
    vector<string> grayCode(int n);
};

#endif //ABSTRACTIONS_RECURSION_H