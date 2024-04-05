//
// Created by konstantine on 3/29/24.
//

#include "Minesweaper.h"

/** private functions **/
int Minesweaper::getSingleHint(vector<vector<bool>> &mines, int x, int y) {
    if (mines[x][y])return -1;

    int mineCount = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i >= 0 && j >= 0 && i < mines.size() && j < mines[i].size()) {
                if (mines[i][j]) mineCount++;
            }
        }
    }
    return mineCount;
}

int Minesweaper::getSum(vector<vector<int>> &sums, int x, int y) {
    return (x >= 0 && y >= 0 && x < sums.size() && y < sums[x].size()) ? sums[x][y] : 0;
}

/** public functions **/
void Minesweaper::createMineFieldWithProbability(vector<vector<bool>> &result, double probability) {
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            result[i][j] = randomChance(probability);
        }
    }
}

void Minesweaper::createMineFieldWithCount(vector<vector<bool>> &result, int numMines) {
    vector<pair<int, int> > coordinates;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            pair<int, int> dot;
            dot.first = i;
            dot.second = j;
            coordinates.push_back(dot);
        }
    }
    for (int k = 0; k < numMines; k++) {
        int index = randomInteger(k, coordinates.size() - 1);
        pair<int, int> dot = coordinates[index];
        result[dot.first][dot.second] = true;
        swap(coordinates[k], coordinates[index]);
    }
}

void Minesweaper::calculateHints(vector<vector<int>> &hints, vector<vector<bool>> &mines) {
    for (int i = 0; i < mines.size(); i++) {
        for (int j = 0; j < mines[i].size(); j++) {
            hints[i][j] = getSingleHint(mines, i, j);
        }
    }
}

void Minesweaper::getTopLeftRectangleSums(vector<vector<int>> &rectangleSums, vector<vector<int>> &mines) {
    for (int i = 0; i < mines.size(); i++) {
        for (int j = 0; j < mines[i].size(); j++) {
            rectangleSums[i][j] = getSum(rectangleSums, i, j - 1)
                                  + getSum(rectangleSums, i - 1, j)
                                  - getSum(rectangleSums, i - 1, j - 1);
            if (mines[i][j]) rectangleSums[i][j]++;
        }
    }
}

int Minesweaper::getBombsInRectangle(vector<vector<int>> &rectangleSums, int x1, int y1, int x2, int y2) {
    return getSum(rectangleSums, x2, y2) - getSum(rectangleSums, x1 - 1, y2) - getSum(rectangleSums, x2, y1 - 1) +
           getSum(rectangleSums, x1 - 1, y1 - 1);
}
