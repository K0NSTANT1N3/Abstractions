//
// Created by konstantine on 3/19/24.
//

#include "Arithmetics.h"

int Arithmetics::fastExponenting(int x, int y) {
    return fastExponentingHelper(x, y, 1);
}

int Arithmetics::fastExponentingHelper(int x, int y, int c) {
    if(y == 0)return 1;
    if(y == 1)return x * c;
    return fastExponentingHelper(x * x, y / 2, c * fastExponentingHelper(x, y % 2, 1));
}
