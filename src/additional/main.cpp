//
// Created by konstantine on 3/21/24.
//

#include <iostream>
#include "domino/Domino.h"

using namespace std;


int main() {
   //test iterVec

    Domino domino;
    vector<Domino::rockT> rocks1 = {{5, 5}, {1, 4}};
    vector<Domino::rockT> rocks2 = {{5, 4}, {1, 0}};

    cout << domino.winnerOfDomino(rocks1, rocks2) << endl;
}