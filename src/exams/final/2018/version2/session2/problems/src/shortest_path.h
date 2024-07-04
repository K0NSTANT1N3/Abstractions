#include "grid.h"

struct coordT {
    int row, col;
    coordT(int r, int c) : row(r), col(c) {}
    coordT(){row=col=-1;}
    bool operator==(const coordT &other) const {
        return row == other.row && col == other.col;
    }
    bool operator<(const coordT &other) const {
        return row < other.row || (row == other.row && col < other.col);
    }
};

int getShortestPath(Grid<int> &table);