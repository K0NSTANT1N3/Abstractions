//
// Created by konstantine on 4/17/24.
//

#ifndef ABSTRACTIONS_BRUTEFORCE_H
#define ABSTRACTIONS_BRUTEFORCE_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class BruteForce {
public:
    queue<string> generateAllBFS(int n, vector<char>& symbols);
    void generateAllDFS(int n, vector<char>& symbols, string soFar);
};


#endif //ABSTRACTIONS_BRUTEFORCE_H