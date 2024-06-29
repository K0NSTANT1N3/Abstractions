//
// Created by konstantine on 6/29/24.
//

#include "fuse.h"

int fuse::fold(int defaultValue, vector<int> values, int (*combine)(int, int)) {
    for (int i = 0; i < values.size(); i++) {
        defaultValue = combine(defaultValue, values[i]);
    }
    return defaultValue;
}

int fuse::xorTwo(int a, int b) {
    return a ^ b;
}

int fuse::multiply(int a, int b) {
    return a * b;
}

int fuse::add(int a, int b) {
    return a + b;
}

