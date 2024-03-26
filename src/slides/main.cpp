//
// Created by konstantine on 3/14/24.
//

#include <iostream>
#include "03/TheShuntingYardAlgorithm.h"

using namespace std;

int main() {
    TheShuntingYardAlgorithm shunt;
    int a = shunt.shuntingYard("1+4*3^2-2");
    cout << a;
}
