//
// Created by konstantine on 3/22/24.
//

#include "Combinations.h"

int Combinations:: calculateCombination(int n, int k) {
    if (n == 0 || n == 1 || k == 0 || k == n)return 1;
    return calculateCombination(n - 1, k - 1) + calculateCombination(n - 1, k);
}