//
// Created by konstantine on 4/16/24.
//

#ifndef ABSTRACTIONS_TICKTACKTOE_H
#define ABSTRACTIONS_TICKTACKTOE_H

#include <vector>
#include <iostream>

using namespace std;


class TickTackToe {
private:
    enum position {
        cross = 1,
        neither = 0,
        nought = -1
    };
    bool gameWon(vector<vector<int> > &board, int player);
    position gameStatus(vector<vector<int> > &board);
    bool isBoardFull(vector<vector<int> > &board);
public:
    int determineWinner(vector<vector<int> > &board, int player);
};


#endif //ABSTRACTIONS_TICKTACKTOE_H
