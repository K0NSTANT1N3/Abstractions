//
// Created by konstantine on 3/14/24.
//

#ifndef ABSTRACTIONS_RECURSION_H
#define ABSTRACTIONS_RECURSION_H

#include<iostream>

using namespace std;

class Recursion {
public:
    int digitalRoot(int n);
    int factorial(int n);
    int fibonacci(int n);
private:
    int sumOfDigits(int n);
};

#endif //ABSTRACTIONS_RECURSION_H
