//
// Created by konstantine on 5/4/24.
//

#ifndef ABSTRACTIONS_SOLUTIONS_H
#define ABSTRACTIONS_SOLUTIONS_H

#include <iostream>
#include "vector.h"

class Solutions {
private:
    void lengthenVec(Vector<string> &base, Vector<string> &extended, string member);
    void lengthenSequence(Vector<int> &base, Vector<int> &extended, int k);
public:
    Vector<string> generateCodes(int n, string symbols);
    Vector<int> numsSameConsecDiff(int n, int k);

};

#endif //ABSTRACTIONS_SOLUTIONS_H