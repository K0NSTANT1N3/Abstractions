//
// Created by konstantine on 5/15/24.
//

#ifndef ABSTRACTIONS_DOMINO_H
#define ABSTRACTIONS_DOMINO_H

#include <iostream>
#include "vector.h"

using namespace std;

class Domino {
public:
    struct rockT {
        int left;
        int right;
    };
private:
    void maxDominoScoreHelper(Vector<rockT>& rocks, rockT cur, int &maxScore, int curScore);
    void insertSingleDomino(Vector<rockT>& rocks, rockT cur, int &maxScore, int curScore, rockT tmp);
    int maxDominoFirstIteration(Vector<rockT>& rocks);
    void maxDominoBaseCase(Vector<rockT>& rocks, rockT cur, int &maxScore, int& curScore);
    void maxDominoInductiveStep(Vector<rockT>& rocks, rockT cur, int &maxScore, int curScore);

public:
    int maxDominoScore(Vector<rockT>& rocks);

};


#endif //ABSTRACTIONS_DOMINO_H
