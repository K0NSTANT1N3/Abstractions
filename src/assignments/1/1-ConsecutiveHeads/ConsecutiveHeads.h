//
// Created by konstantine on 3/22/24.
//

#ifndef ABSTRACTIONS_CONSECUTIVEHEADS_H
#define ABSTRACTIONS_CONSECUTIVEHEADS_H

#include<random>
#include<iostream>

class ConsecutiveHeads {
private:
    int getRandomNumber(int lower_bound, int upper_bound);

    int flipCount(int n);

public:
    int reps(int n, int consecutive);
};


#endif //ABSTRACTIONS_CONSECUTIVEHEADS_H
