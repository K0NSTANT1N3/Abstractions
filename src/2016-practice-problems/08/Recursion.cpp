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
        if (canSumUpWithUnits(ammount - cur, units)) {
            return true;
        }
    }
    return false;
}

bool Recursion::canSumUpWitUniqueUnits(int amount, vector<int> &units, int index) {
    if (amount == 0) return true;
    if (amount < 0 || index == units.size()) return false;
    int curUnit = units[index];
    return canSumUpWitUniqueUnits(amount - curUnit, units, index + 1) ||
           canSumUpWitUniqueUnits(amount, units, index + 1);
}

int Recursion::minDifference(vector<int> &vec, int startIndex, int d) {
    if (startIndex >= vec.size()) {
        d = abs(d);
    }
    if (startIndex == vec.size() - 1) {
        return min(abs(d + vec[startIndex]), abs(d - vec[startIndex]));
    }
    return min(minDifference(vec, startIndex + 1, d + vec[startIndex]),
               minDifference(vec, startIndex + 1, d - vec[startIndex]));
}

vector<string> Recursion::grayCode(int n) {
    vector<string> res;
    if(n ==1){
        res.emplace_back("0");
        res.emplace_back("1");
        return res;
    }
    vector<string> last = grayCode(n-1);
    for(int i = 0; i < last.size(); i++){
        res.push_back("0" + last[i]);
    }
    for(int i = last.size() - 1; i >= 0; i--){
        res.push_back("1" + last[i]);
    }
    return res;
}
