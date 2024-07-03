//
// Created by konstantine on 4/29/24.
//

#include "Solutions.h"

/* private */
bool Solutions::debtOrPay(Vector<int> &cshBills, Vector<int> &cstBills, int price, int customer) {
    Vector<int> *mainVec, secondary;
    if (customer == 1) {
        mainVec = &cshBills;
        secondary = cstBills;
    } else {
        mainVec = &cstBills;
        secondary = cshBills;
    }
    /* Base Case */
    if (mainVec->isEmpty()) return false;

    /* Inductive Step */
    int pay = (*mainVec)[mainVec->size() - 1] * customer;

    mainVec->remove(mainVec->size() - 1);

    bool res = giveChangeHelper(cshBills, cstBills, price);
    if (res) {
        mainVec->add(pay * customer);
        return true;
    }
    res = giveChangeHelper(cshBills, cstBills, price + pay);
    mainVec->add(pay * customer);

    if (res) {
        return true;
    }

    return false;
}

bool Solutions::giveChangeHelper(Vector<int> &cshBills, Vector<int> &cstBills, int price) {
    //print the state of the vectors
    std::cout << "cshBills: " << cshBills << std::endl;
    std::cout << "cstBills: " << cstBills << std::endl;
    std::cout << "price: " << price << std::endl;

    if (price == 0) return true;
    if ((cshBills.isEmpty() && price < 0) || (cstBills.isEmpty() && price > 0))return false;

    bool ans = false;
    if (price > 0) { //client is paying
        ans = ans || debtOrPay(cshBills, cstBills, price, -1);
    } else if (price < 0) { //cashier is paying
        ans = ans || debtOrPay(cshBills, cstBills, price, 1);
    }
    return ans;
}

void Solutions::matchingGreed(Grid<bool> &likes) {
    for (int i = 0; i < likes.nCols; i++) {
        for (int j = 0; j < likes.nRows; j++) {
            if (!likes[i][j]) {
                likes[j][i] = false;
            }
        }
    }
}

int Solutions::maxPairsRecursion(Grid<bool> &likes, int rowIndex, vector<bool> used) {
    int ans = 0;
    if (used[rowIndex])rowIndex++;
    if (rowIndex > likes.nRows)return ans;

    ans = maxPairsRecursion(likes, rowIndex + 1, used);
    for (int i = rowIndex + 1; i < likes.nCols; i++) {
        if (likes[rowIndex][i]) {
            int cur = 1;
            used[rowIndex] = true;
            used[i] = true;
            cur += maxPairsRecursion(likes, rowIndex + 1, used);
            ans = max(ans, cur);
            used[rowIndex] = false;
            used[i] = false;
        }
    }
    return ans;
}

/* public */
bool Solutions::giveChange(Vector<int> &cshBills, Vector<int> &cstBills, int price) {
    return giveChangeHelper(cshBills, cstBills, price);
}

int Solutions::maxPairs(Grid<bool> &likes) {
    matchingGreed(likes);
    vector<bool> used(likes.numRows(), false);
    return maxPairsRecursion(likes, 0, used);
}
