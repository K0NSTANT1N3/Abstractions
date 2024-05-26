/*
 * File: RandomSubsets.cpp
 * ----------------------
 * Name: Konstantine Endeladze
 * This file is the starter project for the Random Subsets problem
 * on Assignment #3.
 */

#include <iostream>
#include <set>
#include "random.h"
#include "console.h"

using namespace std;

/*
 * Given a set of integers, returns a uniformly-random subset of that
 * set.
 */

set<int> randomSubsetOf(set<int> &s);

int main() {
    //test code here
    set<int> s = {1, 2, 3, 4, 5};
    set<int> sub = randomSubsetOf(s);
    for (int num: sub) {
        cout << num << " ";
    }

    return 0;
}

set<int> randomSubsetOf(set<int> &s) {
    /* base case */
    if (s.empty())return {};

    /* recursive case */
    auto it = s.begin();
    int num = *it;
    s.erase(it);
    //put the number in the result set with 50% chance
    set<int> res = randomSubsetOf(s);
    if (randomChance(0.5)) {
        res.insert(num);
    }
    return res;
}