//
// Created by konstantine on 3/26/24.
//

#ifndef ABSTRACTIONS_BUYINGCELLTOWERS_H
#define ABSTRACTIONS_BUYINGCELLTOWERS_H

#include<iostream>
#include <vector>

using namespace std;

class BuyingCellTowers {
private:
    int buyTowersRecursionHelper(vector<int> &towers, int index);
    int max(int a, int b);

public:
    int buyTowersRecursion(vector<int> &towers);
    int buyTowersArray(vector<int> &towers);
};


#endif //ABSTRACTIONS_BUYINGCELLTOWERS_H
