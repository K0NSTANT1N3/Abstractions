//
// Created by konstantine on 5/29/24.
//

#include "Domino.h"

/** public */
int Domino::winnerOfDomino(vector<rockT> &rocks1, vector<rockT> &rocks2) {
    int maxAns = 0;
    for (int i = 0; i < rocks1.size(); i++) {
        rockT rock = rocks1[i];
        rocks1.erase(rocks1.begin() + i);
        //print rock
        int bonusScore = (rock.right + rock.left) % 5 == 0 ? rock.right + rock.left : 0;
        bonusScore+=winnerOfDominoHelper(rocks2, rocks1, rock, -1);
        maxAns = max(maxAns, bonusScore);

        rocks1.insert(rocks1.begin() + i, rock);
    }
    return maxAns;
}

/** private */

int Domino::winnerOfDominoHelper(vector<rockT> &rocks1, vector<rockT> &rocks2, Domino::rockT curPos, int myTurn) {
    if (rocks2.empty()) {
        return sumOf(rocks1) * myTurn * -1;
    }
    if (rocks1.empty()) {
        return sumOf(rocks2) * myTurn;
    }

    int maxAns = NULL;

    for (int i = 0; i < rocks1.size(); i++) {
        rockT rock = rocks1[i];
        rocks1.erase(rocks1.begin() + i);

        if (rock.left == curPos.left) {
            rockT newRock(rock.right, curPos.right);

            int bonusScore = (newRock.left + newRock.right) % 5 == 0 ? (newRock.left + newRock.right) * myTurn: 0;
            bonusScore += winnerOfDominoHelper(rocks2, rocks1, newRock, -myTurn);

            if(maxAns == NULL) {
                maxAns = bonusScore;
            } else {
                maxAns = greaterWithSign(maxAns, bonusScore, myTurn);
            }
        }
        if (rock.right == curPos.left) {
            rockT newRock(rock.left, curPos.right);

            int bonusScore = (newRock.left + newRock.right) % 5 == 0 ? (newRock.left + newRock.right) * myTurn: 0;
            bonusScore += winnerOfDominoHelper(rocks2, rocks1, newRock, -myTurn);
            if(maxAns == NULL) {
                maxAns = bonusScore;
            } else {
                maxAns = greaterWithSign(maxAns, bonusScore, myTurn);
            }
        }
        if (rock.left == curPos.right) {
            rockT newRock(curPos.left, rock.right);
            int bonusScore = (newRock.left + newRock.right) % 5 == 0 ? (newRock.left + newRock.right) * myTurn: 0;

            bonusScore += winnerOfDominoHelper(rocks2, rocks1, newRock, -myTurn);
            if(maxAns == NULL) {
                maxAns = bonusScore;
            } else {
                maxAns = greaterWithSign(maxAns, bonusScore, myTurn);
            }
        }
        if (rock.right == curPos.right) {
            rockT newRock(curPos.left, rock.left);

            int bonusScore = (newRock.left + newRock.right) % 5 == 0 ? (newRock.left + newRock.right) * myTurn: 0;
            bonusScore += winnerOfDominoHelper(rocks2, rocks1, newRock, -myTurn);
            if(maxAns == NULL) {
                maxAns = bonusScore;
            } else {
                maxAns = greaterWithSign(maxAns, bonusScore, myTurn);
            }
        }

        rocks1.insert(rocks1.begin() + i, rock);
    }
    return maxAns;
}

int Domino::sumOf(vector<rockT> &rocks) {
    int ans = 0;
    for (int i = 0; i < rocks.size(); i++) {
        ans += rocks[i].right + rocks[i].left;
    }
    return ans;
}

int Domino::greaterWithSign(int a, int b, int myTurn) {
    if (myTurn > 0) {
        return max(a, b);
    } else {
        return min(a, b);
    }
}
