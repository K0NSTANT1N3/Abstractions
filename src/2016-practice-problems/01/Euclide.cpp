//
// Created by konstantine on 3/14/24.
//

#include "Euclide.h"

int Euclide::gcd(int a, int b){
    if(b == 0)return a;
    return gcd(b, a % b);
}
