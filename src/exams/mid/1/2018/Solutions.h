//
// Created by konstantine on 4/29/24.
//

#ifndef ABSTRACTIONS_SOLUTIONS_H
#define ABSTRACTIONS_SOLUTIONS_H

#include <iostream>
#include <grid.h>
#include <vector.h>
#include <vector>

using namespace std;

class Solutions {
private:
    bool debtOrPay(Vector<int>& secondary, Vector<int>& mainVec, int price, int customer);
    bool giveChangeHelper(Vector<int>& cshBills, Vector<int>& cstBills, int price);
    void matchingGreed(Grid<bool>& likes);
    int maxPairsRecursion(Grid<bool>& likes, int rowIndex, vector<bool> used);
public:
    bool giveChange(Vector<int> &cshBills, Vector<int> &cstBills, int price);
    int maxPairs(Grid<bool> &likes);
};


#endif //ABSTRACTIONS_SOLUTIONS_H
