//
// Created by konstantine on 3/26/24.
//

#include "ReptoreDefence.h"

/** private functions **/

bool ReptoreDefence::safeDirection(vector<vector<bool>> &reptors, int &x, int &y, int dx, int dy) {
    int i, j;
    for (i = x, j = y; i >= 0 && j >= 0 && i < reptors.size() && j < reptors[i].size(); i+=dx, j+=dy) {
        if (reptors[i][j]) return false;
    }
    return true;
}

bool ReptoreDefence::isSafe(vector<vector<bool> > &reptors, int &x, int &y) {
    return safeDirection(reptors, x, y, 1, 0) && safeDirection(reptors, x, y, 0, 1) &&
           safeDirection(reptors, x, y, -1, 0) && safeDirection(reptors, x, y, 0, -1) &&
           safeDirection(reptors, x, y, 1, 1) && safeDirection(reptors, x, y, -1, -1) &&
           safeDirection(reptors, x, y, 1, -1) && safeDirection(reptors, x, y, -1, 1);
}

/** public functions **/
pair<int, int> ReptoreDefence::reptorPresents(vector<vector<bool> > &reptors) {
    for (int i = 0; i < reptors.size(); i++) {
        for (int j = 0; j < reptors[i].size(); j++) {
            if (!reptors[i][j] && isSafe(reptors, i, j)) {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}