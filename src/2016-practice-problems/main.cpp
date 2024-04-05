//
// Created by konstantine on 3/15/24.
//

#include "06/CollectionsSetMap.h"

#include<iostream>

using namespace std;

int main() {
    CollectionsSetMap mp;
    map<string, int> a = mp.countWordsFromFile("/home/konstantine/CLionProjects/Abstractions/src/2016-practice-problems/06/CollectionsSetMap.cpp");

    for (auto &i : a) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}
