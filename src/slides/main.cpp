//
// Created by konstantine on 3/14/24.
//

#include <iostream>
#include "03-06-collections/06-collections-IV/BruteForce.h"

using namespace std;

int main() {
  // test dfs
    BruteForce bf;
    vector<char> symbols = {'a', 'b', 'c'};
    bf.generateAllDFS(3, symbols, "");

    return 0;
}

