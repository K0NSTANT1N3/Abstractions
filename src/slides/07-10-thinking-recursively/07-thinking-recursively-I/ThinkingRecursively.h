//
// Created by konstantine on 5/11/24.
//

#ifndef ABSTRACTIONS_THINKINGRECURSIVELY_H
#define ABSTRACTIONS_THINKINGRECURSIVELY_H

#include <iostream>
#include <stack>
#include "random.h"

using namespace std;

class ThinkingRecursively {
private:
    int tryParking = 100;
    void moveSingleBlock(stack<int> &from, stack<int> &to);
    int approximatelyParkedCars(double left, double right);
public:
    void moveTower(int n, stack<int> &from, stack<int> &tmp, stack<int> &to);
    int parkingRandomly(int n);
};


#endif //ABSTRACTIONS_THINKINGRECURSIVELY_H
