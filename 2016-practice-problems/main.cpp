//
// Created by konstantine on 3/15/24.
//

#include "problem2/StringManipulation.h"

#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    StringManipulation sm;
    cout << (sm.remainderMod7(s));
}
