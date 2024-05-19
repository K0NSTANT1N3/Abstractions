#include <iostream>
#include <string>
#include "2024/1/Domino.h"
#include "vector"

using namespace std;

int main() {
    //test case 1
    Vector<Domino::rockT> rocks;
    rocks.add({6, 6});
    rocks.add({5, 5});
    rocks.add({4, 6});

    Domino domino;
    cout << domino.maxDominoScore(rocks) << endl; // 22


    return 0;
}