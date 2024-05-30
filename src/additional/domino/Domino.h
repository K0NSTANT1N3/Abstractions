//
// Created by konstantine on 5/29/24.
//

#ifndef ABSTRACTIONS_DOMINO_H
#define ABSTRACTIONS_DOMINO_H

#include<iostream>
#include<vector>

using namespace std;

class Domino {
public:
    struct rockT {
        int left;
        int right;

        rockT() {
            left = right = -1;
        }

        rockT(int left, int right) {
            this->left = left;
            this->right = right;
        }
    };

private:
//    struct rockT {
//        int left;
//        int right;
//    };

    int winnerOfDominoHelper(vector<rockT> &rocks1, vector<rockT> &rocks2, rockT curPos, int myTurn);

    int sumOf(vector<rockT> &rocks);

    int greaterWithSign(int a, int b, int myTurn);

public:

    int winnerOfDomino(vector<rockT> &rocks1, vector<rockT> &rocks2);
};


#endif //ABSTRACTIONS_DOMINO_H
