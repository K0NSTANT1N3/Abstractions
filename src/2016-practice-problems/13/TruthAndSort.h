//
// Created by konstantine on 5/7/24.
//

#ifndef ABSTRACTIONS_TRUTHANDSORT_H
#define ABSTRACTIONS_TRUTHANDSORT_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class TruthAndSort {
private:
    void swap(int &a, int &b);
    int countTautologyDP(int n, map<int, int> &storedValues);
public:
    int countTautology(int n);
    int selectionSortWithCompareCount(vector<int>& vec);
    int insertionSortWithCompareCount(vector<int>& vec);
};


#endif //ABSTRACTIONS_TRUTHANDSORT_H
