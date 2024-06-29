//
// Created by konstantine on 6/29/24.
//

#ifndef ABSTRACTIONS_FUSE_H
#define ABSTRACTIONS_FUSE_H

#include <iostream>
#include <vector>
using namespace std;

static int SENTINEL = -1;


class fuse {
private:
public:
    int add(int a, int b);
    int multiply(int a, int b);
    int xorTwo(int a, int b);
    int fold(int defaultValue, vector<int> values, int(combine)(int, int));
};


#endif //ABSTRACTIONS_FUSE_H
