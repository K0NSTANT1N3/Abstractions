//
// Created by konstantine on 7/1/24.
//

#include "translate.h"

int translate::calcTranslTime(Vector<int> times, int k) {
    int ans = 0;
    Vector<int> translators(k, 0);
    calcTranslTimeRec(times, 0, translators, ans);
    return ans;
}

void translate::calcTranslTimeRec(Vector<int> &times, int itr, Vector<int> &translators, int &ans) {
    if (itr >= times.size()) {
        int maximal = *max_element(translators.begin(), translators.end());
        if (maximal < ans || ans == 0)ans = maximal;
        return;
    }

    int task = times[itr];
    for (int i = 0; i < translators.size(); i++) {
        translators[i] += task;
        calcTranslTimeRec(times, itr + 1, translators, ans);
        translators[i] -= task;
    }
}

