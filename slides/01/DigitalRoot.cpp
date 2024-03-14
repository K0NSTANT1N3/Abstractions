//
// Created by konstantine on 3/14/24.
//

#include "DigitalRoot.h"

int digitalRoot(int n);

int sumOfDigits(int n);

int main() {
    int n;
    cin >> n;
    cout << digitalRoot(n);
}

int digitalRoot(int n) {
    if(n < 10) return n;

    return digitalRoot(sumOfDigits(n));
}

int sumOfDigits(int n) {
    if(n < 10) return n;

    return (n % 10) + sumOfDigits(n / 10);
}