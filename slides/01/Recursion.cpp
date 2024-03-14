//
// Created by konstantine on 3/14/24.
//

#include "Recursion.h"

int Recursion::sumOfDigits(int n) {
    if (n < 10) return n;
    return (n % 10) + sumOfDigits(n / 10);
}

int Recursion::digitalRoot(int n) {
    if (n < 10) return n;
    return digitalRoot(sumOfDigits(n));
}

int Recursion::factorial(int n) {
    if (n == 0)return 1;
    return n * factorial(n - 1);
}

int Recursion::fibonacci(int n) {
    if(n == 1 || n == 2)return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}