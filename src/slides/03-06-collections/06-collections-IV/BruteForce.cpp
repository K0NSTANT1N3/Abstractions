//
// Created by konstantine on 4/17/24.
//

#include "BruteForce.h"

/** public */
queue<string> BruteForce::generateAllBFS(int n, vector<char>& symbols) {
    queue<string> q;
    q.push("");
    queue<string> result = q;

    while (q.front().size() < n) { // lengthen the variations
        string cur = q.front();
        q.pop();
        for (int j = 0; j < symbols.size(); j++) {
            string newStr = cur + symbols[j];
            q.push(newStr);
            result.push(newStr);
        }
    }
    return result;
}

void BruteForce::generateAllDFS(int n, vector<char> &symbols, string soFar) {
    cout << soFar << endl;
    //TODO[do something with soFar]
    if(n <= 0)return;

    for(int i = 0; i < symbols.size(); i++){
        generateAllDFS(n - 1, symbols, soFar + symbols[i]);
    }
}
