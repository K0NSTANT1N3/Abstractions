//
// Created by konstantine on 5/4/24.
//

#include "Solutions.h"

/* private */
void Solutions::lengthenVec(Vector<string> &base, Vector<string> &extended, string member) {
    for (int i = 0; i < base.size(); i++) {
        extended.push_back(member + base[i]);
    }
}

void Solutions::lengthenSequence(Vector<int> &base, Vector<int> &extended, int k) {
    for (int i = 0; i < base.size(); i++) {
        int cur = base[i];
        if (cur % 10 + k <= 9) {
            extended.add(cur * 10 + cur % 10 + k);
        }
        if (cur % 10 - k >= 0) {
            extended.add(cur * 10 + cur % 10 - k);
        }
    }
}

/* public */
Vector<string> Solutions::generateCodes(int n, string symbols) {
    Vector<string> result;

    // Base Case
    if (n == 0)return result;
    if (n == 1) {
        for (int i = 0; i < symbols.length(); i++) {
            result.push_back(string(1, symbols[i]));
        }
    }

    // Inductive Step
    Vector<string> base = generateCodes(n - 1, symbols);
    for (int i = 0; i < symbols.length(); i++) {
        string member = string(1, symbols[i]);
        lengthenVec(base, result, member);
    }
    return result;
}

Vector<int> Solutions::numsSameConsecDiff(int n, int k) {
    // Base Case
    Vector<int> ans;
    if (n == 0 || k >= 9) return ans;
    if (n == 1) {
        for (int i = 1; i <= 9; i++) {
            ans.add(i);
        }
    }

    // Recursive Case
    Vector<int> base = numsSameConsecDiff(n - 1, k);
    lengthenSequence(base, ans, k);
    return ans;
}
