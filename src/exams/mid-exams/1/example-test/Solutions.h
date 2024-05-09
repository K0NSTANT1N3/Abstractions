//
// Created by konstantine on 4/26/24.
//

#ifndef ABSTRACTIONS_SOLUTIONS_H
#define ABSTRACTIONS_SOLUTIONS_H

#include <iostream>
#include "set.h"

using namespace std;

class Solutions {
private:
    bool divideBoxes(int n, Vector<int>& weights, Vector<int>& boxes, int index = 0);
public:
    Set<string> getAllPossiblePasswords(int n, string digits);
    bool canDivideBoxes(int n, Vector<int> weights);
};


#endif //ABSTRACTIONS_SOLUTIONS_H
