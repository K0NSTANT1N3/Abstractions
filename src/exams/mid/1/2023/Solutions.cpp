//
// Created by konstantine on 4/26/24.
//

#include "Solutions.h"

/** problem one **/
Set<string> Solutions::getAllPossiblePasswords(int n, string digits) {
    Set<string> ans;
    ans.insert("");
    if (n == 0)return ans;

    Set<string> prev = getAllPossiblePasswords(n - 1, digits);
    for (int i = 0; i < digits.size(); i++) {
        string member;
        string newDig = digits.substr(0, i) + digits.substr(i + 1);
        string curDig = digits.substr(i, 1);

        for (string s: prev) {
            ans.insert(s);
            member = s + curDig;
            ans.insert(member);
        }
    }
    return ans;
}

bool Solutions::divideBoxes(int n, Vector<int> &weights, Vector<int> &boxes, int index) {
    if (index >= weights.size()) {
        for(int i = 1; i < boxes.size(); i++){
            if(boxes[i] != boxes[i - 1])return false;
        }
        return true;
    }

    for (int i = 0; i < n; i++) {
        int num = weights[index];
        boxes[i] += num;
        if(divideBoxes(n, weights, boxes, index + 1)){
            return true;
        }
        boxes[i] -= num;
    }
    return false;
}

bool Solutions::canDivideBoxes(int n, Vector<int> weights) {
    Vector<int> boxes(n, 0);
    return divideBoxes(n, weights, boxes, 0);
}


