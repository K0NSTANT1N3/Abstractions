//
// Created by konstantine on 3/29/24.
//

#ifndef ABSTRACTIONS_MINESWEAPER_H
#define ABSTRACTIONS_MINESWEAPER_H

#include<iostream>
#include <vector>
#include "random.h"

using namespace std;

class Minesweaper {
private:
    vector<vector<bool> > mineField;
    vector<vector<bool> > hints;

    int getSingleHint(vector<vector<bool> > &mines, int x, int y);

    int getSum(vector<vector<int>> &sums, int x, int y);

public:
    void createMineFieldWithProbability(vector<vector<bool> > &result, double probability);

    void createMineFieldWithCount(vector<vector<bool> > &result, int numMines);

    void calculateHints(vector<vector<int> > &hints, vector<vector<bool> > &mines);

    void getTopLeftRectangleSums(vector<vector<int> > &rectangleSums, vector<vector<int> > &mines);

    int getBombsInRectangle(vector<vector<int>> &rectangleSums, int x1, int y1, int x2, int y2);
};


#endif //ABSTRACTIONS_MINESWEAPER_H
