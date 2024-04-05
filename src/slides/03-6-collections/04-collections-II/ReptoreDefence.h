//
// Created by konstantine on 3/26/24.
//

#ifndef ABSTRACTIONS_REPTOREDEFENCE_H
#define ABSTRACTIONS_REPTOREDEFENCE_H

#include <iostream>
#include <vector>

using namespace std;

class ReptoreDefence {
private:
    bool safeDirection(vector<vector<bool>> &reptors, int &x, int &y, int dx, int dy);
    bool isSafe(vector<vector<bool>> &reptors, int &x, int &y);
public:
    pair<int, int> reptorPresents(vector<vector<bool> > &reptors);
};

#endif //ABSTRACTIONS_REPTOREDEFENCE_H