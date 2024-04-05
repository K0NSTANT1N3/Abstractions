//
// Created by konstantine on 3/14/24.
//

#include <iostream>
#include "03-6-collections/04-collections-II/ReptoreDefence.h"

using namespace std;

int main() {
    ReptoreDefence reptoreDefence;
    vector<vector<bool>> reptors = {
            {false, false, true, false, false},
            {false, true, false, false, false},
            {false, false, false, false, false},
            {true, false, false, false, false},
            {false, false, false, false, true}
    };
    pair<int, int> result = reptoreDefence.reptorPresents(reptors);
    cout << result.first << " " << result.second << endl;
    return 0;
}
