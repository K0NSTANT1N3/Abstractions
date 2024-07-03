//
// Created by konstantine on 5/11/24.
//

#include "Ermalo.h"

bool Ermalo::isCorrectPassword(string s) {
    return s == password;
}

string Ermalo::generateRandomPasswordHelper(HashMap<char, int> &members, string curPass, int size) {
    if (isCorrectPassword(curPass)) {
        return curPass;
    }
    if (curPass.size() >= size) {
        return "";
    }

    string res = "";
    for (char c: members) {
        if (members[c] < 0)continue;
        members[c]--;
        string temp = generateRandomPasswordHelper(members, curPass + c, size);
        members[c]++;
        if (temp != "") {
            res = temp;
            break;
        }
    }
    return res;
}


string Ermalo::generatePassword(HashMap<char, int> &members) {
    int size = 0;
    for (char c: members) {
        size += members[c];
    }
    return generateRandomPasswordHelper(members, "", size);
}

