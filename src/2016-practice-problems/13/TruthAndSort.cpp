//
// Created by konstantine on 5/7/24.
//

#include "TruthAndSort.h"

/* private */
void TruthAndSort::swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int TruthAndSort::countTautologyDP(int n, map<int, int> &storedValues) {
    if (storedValues.find(n) != storedValues.end()) {
        return storedValues[n];
    }

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans += (1 << (2 * n - 2 * i + 1));
        ans += ((1 << i) - 1) * countTautologyDP(n - i, storedValues);
    }
    storedValues[n] = ans;
    return ans;
}


/* public */
int TruthAndSort::countTautology(int n) {
    map<int, int> storedValue;
    return countTautologyDP(n, storedValue);
}

int TruthAndSort::selectionSortWithCompareCount(vector<int> &vec) {
    int result = 0;

    for (int i = 0; i < vec.size(); i++) {
        int minimal = i;
        for (int j = i; j < vec.size(); j++) {
            if (vec[minimal] > vec[j]) {
                minimal = j;
            }
            result++;
        }
        swap(vec[minimal], vec[i]);
    }
    return result;
}

int TruthAndSort::insertionSortWithCompareCount(vector<int> &vec) {
    int result = 0;
    for (int i = 1; i < vec.size(); i++) {
        for (int j = i; j > 0; j--) {
            result++;
            if (vec[j] < vec[j - 1]) {
                swap(vec[j], vec[j - 1]);
            } else {
                break;
            }
        }
    }
    return result;
}

