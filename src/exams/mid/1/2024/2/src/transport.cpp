#include "transport.h"

void recItem(Vector<int> &cars, Vector<itemT> &items, int budget, int itrItem, int &maxAns, int curAns) {
    /* Base Case */
    if (curAns > maxAns) maxAns = curAns;
    if (budget <= 0) return;
    if (itrItem >= items.size())return;

    /* Inductive Step */
    recItem(cars, items, budget, itrItem + 1, maxAns, curAns);

    itemT curItem = items[itrItem];
    if (curItem.price > budget)return;

    recCar(cars, curItem, budget, 0, maxAns, curAns, items, itrItem);
}

void recCar(Vector<int> &cars, itemT curItem, int budget, int itrCar, int &maxAns, int curAns, Vector<itemT> &items,
            int itrItem) {

    /* Base Case */
    if (itrCar >= cars.size())return;

    /* Inductive Step */
    recCar(cars, curItem, budget, itrCar + 1, maxAns, curAns, items, itrItem);

    int &curCar = cars[itrCar];
    if (curCar < curItem.weight)return;

    curCar -= curItem.weight;
    budget -= curItem.price;
    curAns += curItem.weight;

    recItem(cars, items, budget, itrItem + 1, maxAns, curAns);

    /* Back Track */
    curCar += curItem.weight;
    budget += curItem.price;
    curAns -= curItem.weight;
}

int transportMax(Vector<int> &cars, Vector<itemT> &items, int budget) {
    int ans = 0;
    recItem(cars, items, budget, 0, ans, 0);
    return ans;
}
