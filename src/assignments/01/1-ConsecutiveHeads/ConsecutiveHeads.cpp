//
// Created by konstantine on 3/22/24.
//

#include "ConsecutiveHeads.h"

/** private */
int ConsecutiveHeads::flipCount(int n) {
    int count = 0;
    int tails = 0;
    while (tails < n) {
        count++;
        if (getRandomNumber(0, 1) == 0) {
            tails++;
        } else {
            tails = 0;
        }
    }
    return count;
}

int ConsecutiveHeads::getRandomNumber(int lower_bound, int upper_bound) {
    std::random_device randomer;
    std::mt19937 gen(randomer());
    std::uniform_int_distribution<> distr(lower_bound, upper_bound);
    return distr(gen);
}

/** public */
int ConsecutiveHeads::reps(int n, int consecutive) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += flipCount(consecutive);
    }
    return sum / n;
}
