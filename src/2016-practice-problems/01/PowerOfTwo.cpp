//
// Created by konstantine on 3/14/24.
//

#include "PowerOfTwo.h"

bool PowerOfTwo::isPowerOfTwo(int n){
    if(n % 2 != 0)return n == 1;

    return isPowerOfTwo(n / 2);
}