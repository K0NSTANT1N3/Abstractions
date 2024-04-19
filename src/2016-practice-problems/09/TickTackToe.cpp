//
// Created by konstantine on 4/16/24.
//

#include "TickTackToe.h"

/** private */
bool TickTackToe::gameWon(vector<vector<int> > &board, int player) {
    bool column, row, diagonal1, diagonal2;
    row = column = diagonal1 = diagonal2 = true;

    for (int i = 0; i < 3; i++) {
        column = row = true;
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != player)row = false;
            if (board[j][i] != player)column = false;
        }
        if (column || row)return true;
        /* check diagonals */
        if (board[i][i] != player)diagonal1 = false;
        if (board[2 - i][i] != player)diagonal2 = false;
    }
    return diagonal1 || diagonal2;
}

TickTackToe::position TickTackToe::gameStatus(vector<vector<int>> &board) {
    if (gameWon(board, cross)) return cross;
    if (gameWon(board, nought)) return nought;
    return neither;
}

bool TickTackToe::isBoardFull(vector<vector<int>> &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == neither) return false;
        }
    }
    return true;
}

/** public */
int TickTackToe::determineWinner(vector<vector<int>> &board, int player) {
    /* Base Case */
    position pos = gameStatus(board);
    if (pos != neither) return pos;
    if (isBoardFull(board)) return neither;

    /* Inductive Step */
    int result, otherPlayer;
    result = otherPlayer = player == cross ? nought : cross;
    for (int i = 0; i < board.size(); i++) { // Iterate entire board
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == neither) { // Find empty square
                board[i][j] = player;
                int winner = determineWinner(board, otherPlayer); // Winner of following game
                board[i][j] = neither;

                if (winner == player) { // Opponent loses following game
                    return player; // Current player wins
                }
                if (winner == neither) { // Draw is achievable
                    result = neither;
                }
            }
        }
    }

    return result;
}


