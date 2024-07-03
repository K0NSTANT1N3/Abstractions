//
// Created by konstantine on 7/1/24.
//

#ifndef ABSTRACTIONS_TRANSLATE_H
#define ABSTRACTIONS_TRANSLATE_H

#include<iostream>
#include "vector.h"
#include <algorithm>

using namespace std;


class translate {
private:
    void calcTranslTimeRec(Vector<int> &times, int itr, Vector<int> &translators, int &ans);
public:
    int calcTranslTime(Vector<int> times, int k = 3);
};


#endif //ABSTRACTIONS_TRANSLATE_H
