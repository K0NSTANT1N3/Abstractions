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
    bool canSumUpWitUniqueUnits(int amount, vector<int> &units, int index);
};


#endif //ABSTRACTIONS_RECURSION_H
