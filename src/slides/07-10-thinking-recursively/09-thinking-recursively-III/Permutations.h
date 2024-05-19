//
// Created by konstantine on 5/18/24.
//

#ifndef ABSTRACTIONS_PERMUTATIONS_H
#define ABSTRACTIONS_PERMUTATIONS_H

#include <iostream>

using namespace std;

class Permutations {
private:
    void doSomething(string s);
    void permuteStringHelper(string s, string chosen);
public:
    void permuteString(string s);

};


#endif //ABSTRACTIONS_PERMUTATIONS_H
