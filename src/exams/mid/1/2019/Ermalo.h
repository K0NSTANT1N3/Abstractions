//
// Created by konstantine on 5/11/24.
//

#ifndef ABSTRACTIONS_ERMALO_H
#define ABSTRACTIONS_ERMALO_H

#include <iostream>
#include "hashmap.h"

using namespace std;

class Ermalo {
private:
    string password = "dbadcdb";
    string generateRandomPasswordHelper(HashMap<char, int>& members, string curPass, int size);
public:
    bool isCorrectPassword(string s);
    string generatePassword(HashMap<char, int> &members);
};

#endif //ABSTRACTIONS_ERMALO_H