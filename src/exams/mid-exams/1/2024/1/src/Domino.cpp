//
// Created by konstantine on 5/15/24.
//

#include "Domino.h"

/** public */
int Domino::maxDominoScore(Vector<rockT>& rocks) {
    return maxDominoFirstIteration(rocks);
}

/** private */

void Domino::maxDominoScoreHelper(Vector<rockT>& rocks, Domino::rockT cur, int &maxScore, int curScore) {
    maxDominoBaseCase(rocks, cur, maxScore, curScore);
    maxDominoInductiveStep(rocks, cur, maxScore, curScore);
}

void Domino::insertSingleDomino(Vector<rockT>& rocks, rockT cur, int& maxScore, int curScore, rockT tmp) {
    if (tmp.right == cur.right) {
        rockT newCur = {cur.left, tmp.left};
        int increment = cur.left + cur.right % 5 == 0 ? cur.left + cur.right : 0;
        maxDominoScoreHelper(rocks, newCur, maxScore, curScore + increment);
    }
    if (tmp.left == cur.right) {
        rockT newCur = {cur.left, tmp.right};
        int increment = cur.left + cur.right % 5 == 0 ? cur.left + cur.right : 0;
        maxDominoScoreHelper(rocks, newCur, maxScore, curScore + increment);
    }
    if (tmp.right == cur.left) {
        rockT newCur = {tmp.left, cur.right};
        int increment = cur.left + cur.right % 5 == 0 ? cur.left + cur.right : 0;
        maxDominoScoreHelper(rocks, newCur, maxScore, curScore + increment);
    }
    if (tmp.left == cur.left) {
        rockT newCur = {tmp.right, cur.right};
        int increment = cur.left + cur.right % 5 == 0 ? cur.left + cur.right : 0;
        maxDominoScoreHelper(rocks, newCur, maxScore, curScore + increment);;
    }
}

int Domino::maxDominoFirstIteration(Vector<rockT>& rocks) {
    int maxScore = 0;
    for (int i = 0; i < rocks.size(); i++) {
        rockT tmp = rocks[i];
        rocks.remove(i);
        maxDominoScoreHelper(rocks, tmp, maxScore, 0);
        rocks.insert(i, tmp);
    }
    return maxScore;
}

void Domino::maxDominoBaseCase(Vector<rockT>& rocks, Domino::rockT cur, int &maxScore, int& curScore) {
    int increment = cur.left + cur.right;
    curScore += increment % 5 == 0 ? increment : 0;
    if (curScore > maxScore) maxScore = curScore;
}

void Domino::maxDominoInductiveStep(Vector<rockT>& rocks, Domino::rockT cur, int &maxScore, int curScore) {
    for (int i = 0; i < rocks.size(); i++) {
        rockT tmp = rocks[i];
        rocks.remove(i);
        insertSingleDomino(rocks, cur, maxScore, curScore, tmp);
        rocks.insert(i, tmp);
    }
}