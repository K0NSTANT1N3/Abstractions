//
// Created by konstantine on 4/8/24.
//

#include "Recursion.h"

int Recursion::findMin(vector<int> &vec, int start) {
    if (start == vec.size() - 1) {
        return vec[start];
    }
    return min(vec[start], findMin(vec, start + 1));
}

bool Recursion::canSumUpWithUnits(int ammount, vector<int> &units) {
    //base case
    if (ammount == 0) return true;
    if (ammount < 0) return false;

    //inductive step
    for (int i = 0; i < units.size(); i++) {
        int cur = units[i];
        if(canSumUpWithUnits(ammount - cur, units)) {
            return true;
        }
    }
    return false;
}

bool Recursion::canSumUpWitUniqueUnits(int amount, vector<int> &units, int index) {
    if (amount == 0) return true;
    if (amount < 0 || index == units.size()) return false;
    int curUnit = units[index];
    return canSumUpWitUniqueUnits(amount - curUnit, units, index + 1) || canSumUpWitUniqueUnits(amount, units, index + 1);
}
