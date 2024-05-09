//
// Created by konstantine on 4/23/24.
//

#include <iostream>
#include <string>

void dostuff(int anInt);

using namespace std;

void printPermutations(int n, string ans = " ", int depth = 0) {
    if (depth >= n) {
        ans = ans.substr(0, ans.size() - 1);
        int ansInt = stoi(ans);
        dostuff(ansInt);
        return;
    }

    for (int i = 0; i < ans.size(); i++) {
        string left = ans.substr(0, i);
        string right = ans.substr(i);
        string newAns = left + to_string(depth) + right;
        printPermutations(n, newAns, depth + 1);
    }
}

void dostuff(int anInt) {

}

int main() {
    printPermutations(4);
    return 0;
}