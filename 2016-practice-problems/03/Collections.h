//
// Created by konstantine on 3/21/24.
//

#ifndef ABSTRACTIONS_COLLECTIONS_H
#define ABSTRACTIONS_COLLECTIONS_H

#include<iostream>
#include<stack>
using namespace std;

class Collections {
private:
    struct intPair{
        int first;
        int second;
    };
    intPair fibPair(int n);

public:
    int fib(int n);
};

#endif //ABSTRACTIONS_COLLECTIONS_H