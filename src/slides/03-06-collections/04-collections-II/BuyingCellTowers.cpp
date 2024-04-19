//
// Created by konstantine on 3/26/24.
//

#include "BuyingCellTowers.h"

/** private functions **/
int BuyingCellTowers::buyTowersRecursionHelper(vector<int> &towers, int index) {
    if(index >= towers.size()){
        return 0;
    }
    if(index == towers.size() - 1){
        return towers[index];
    }
    if(index == towers.size() - 2){
        return towers[index] >= towers[index + 1] ? towers[index] : towers[index + 1];
    }

    int sum1 = towers[index] + buyTowersRecursionHelper(towers, index + 2);
    int sum2 = towers[index + 1] + buyTowersRecursionHelper(towers, index + 3);

    return sum1 >= sum2 ? sum1 : sum2;
}

int BuyingCellTowers::max(int a, int b) {
    return a >= b ? a : b;
}


/** public functions **/
int BuyingCellTowers::buyTowersRecursion(vector<int> &towers) {
    return buyTowersRecursionHelper(towers, 0);
}

int BuyingCellTowers::buyTowersArray(vector<int> &towers) {
    vector<int> ans = vector<int>(towers.size(), 0);
    ans[0] = towers[0];
    ans[1] = towers[0] >= towers[1] ? towers[0] : towers[1];

    for(int i = 2; i < towers.size(); i++){
        ans[i] = max(towers[i] + ans[i - 2], ans[i - 1]);
    }
    return ans[towers.size() - 1];
}


