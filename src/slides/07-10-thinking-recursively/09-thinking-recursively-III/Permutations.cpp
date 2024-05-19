//
// Created by konstantine on 5/18/24.
//

#include "Permutations.h"

void Permutations::doSomething(string s) {
    cout << s << endl;
}

void Permutations::permuteStringHelper(string s, string chosen) {
    if(s.empty()){
        doSomething(chosen);
        return;
    }

    for(int i = 0; i < s.size(); i++) {
        // Choose
        char c = s[i];
        s.erase(i, 1);
        chosen += c;

        // Explore
        permuteStringHelper(s, chosen);

        // Unchoose
        s.insert(i, 1, c);
        chosen.pop_back();
    }
}

void Permutations::permuteString(string s) {
    permuteStringHelper(s, "");
}
