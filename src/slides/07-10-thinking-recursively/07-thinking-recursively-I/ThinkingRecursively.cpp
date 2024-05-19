//
// Created by konstantine on 5/11/24.
//

#include "ThinkingRecursively.h"

/** Hanoi */

/* private */
void ThinkingRecursively::moveSingleBlock(stack<int> &from, stack<int> &to) {
    to.push(from.top());
    from.pop();
}

/* public */
void ThinkingRecursively::moveTower(int n, stack<int> &from, stack<int> &tmp, stack<int> &to) {
    if (n <= 0) return;

    if (n == 1) {
        moveSingleBlock(from, to);
        return;
    }

    moveTower(n - 1, from, to, tmp);
    moveSingleBlock(from, to);
    moveTower(n - 1, tmp, from, to);
}

/** Parking Randomly */

/* private */
int ThinkingRecursively::approximatelyParkedCars(double left, double right) {
    if (left + 1.0 > right)return 0;
    double x = randomReal(left, right - 1.0);
    return 1 + approximatelyParkedCars(left, x) + approximatelyParkedCars(x + 1.0, right);
}

/* public */
int ThinkingRecursively::parkingRandomly(int n) {
    double ans = 0;
    for (int i = 0; i < tryParking; i++) {
        ans += approximatelyParkedCars(0.0, (double) n);
    }
    return ans / tryParking;
}


