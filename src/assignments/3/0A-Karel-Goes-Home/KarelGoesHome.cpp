/*
 * File: KarelGoesHome.cpp
 * ----------------------
 * Name: Konstantine Endeladze
 * This file is the starter project for the Karel Goes Home
 * warmup problem for Assignment #3.
 */

#include <iostream>
//#include "console.h"
using namespace std;

/* Given a street number and avenue number, which are 1-indexed,
 * returns the number of paths Karel can take back home that only
 * moves left or down.
 */
int numPathsHome(int street, int avenue);

int main() {
    // test code here
    int street, avenue;
    cin >> street >> avenue;
    cout << numPathsHome(street, avenue);
    return 0;
}

int numPathsHome(int street, int avenue){
    if(street == 0 || avenue == 0)return 1;
    return numPathsHome(street - 1, avenue) + numPathsHome(street, avenue - 1);
}
