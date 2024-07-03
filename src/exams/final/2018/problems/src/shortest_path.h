#include "grid.h"

struct coordT {
    int row;
    int col;

    coordT(int row, int col) {
        this->row = row;
        this->col = col;
    }

    coordT(){
        this->row = -1;
        this->col = -1;
    }

    bool operator==(const coordT& other) const{
        return row == other.row && col == other.col;
    }

    bool operator<(const coordT& other) const {
        return row < other.row || (row == other.row && col < other.col);
    }

    bool operator>(const coordT& other) const {
        return row > other.row || (row == other.row && col > other.col);
    }
};

int getShortestPath(Grid<int> &table);