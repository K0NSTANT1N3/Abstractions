//
// Created by konstantine on 3/21/24.
//

#include "Collections.h"

Collections::intPair Collections::fibPair(int n) {
    if(n == 0){
        intPair res;
        res.first = 0;
        res.second = 1;
        return res;
    }

    intPair prev = fibPair(n - 1);
    intPair res;
    res.first = prev.second;
    res.second = prev.second + prev.first;
    return res;
}

int Collections::fib(int n) {
    return fibPair(n).second;
}