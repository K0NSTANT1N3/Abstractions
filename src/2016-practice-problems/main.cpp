//
// Created by konstantine on 3/15/24.
//

#include "09/TickTackToe.h"

#include<iostream>

using namespace std;

int main() {
    //test ticktacktoe
    vector<vector<int> > board = {
        {1, 0, 0},
        {0, 0, -1},
        {0, 0, 0}
    };
    TickTackToe game;
    cout << game.determineWinner(board, -1) << endl;


    return 0;
}
