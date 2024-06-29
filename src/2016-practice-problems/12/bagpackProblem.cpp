//
// Created by konstantine on 6/29/24.
//

#include <bits/stdc++.h>

using namespace std;

struct itemT {
    int weight;
    int value;
};

int maxValueFromItems(vector<itemT> &items, int maxWeight, vector<itemT> &selectedItems) {
    if (items.empty()){
        selectedItems.clear();
        return 0;
    }

    itemT curItem = items.back();
    items.pop_back();

    vector<itemT> withoutItemSelected;
    int ansWithout = maxValueFromItems(items, maxWeight, withoutItemSelected);

    if (curItem.weight > maxWeight) {
        selectedItems = withoutItemSelected;
        return ansWithout;
    }

    vector<itemT> withItemSelected;
    int ansWith = maxValueFromItems(items, maxWeight - curItem.weight, withItemSelected);
    ansWith += curItem.value;
    withItemSelected.push_back(curItem);

    if (ansWithout > ansWith) {
        selectedItems = withoutItemSelected;
        return ansWithout;
    } else {
        selectedItems = withItemSelected;
        return ansWith;
    }

}
