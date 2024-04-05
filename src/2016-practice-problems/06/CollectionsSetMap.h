//
// Created by konstantine on 4/2/24.
//

#ifndef ABSTRACTIONS_COLLECTIONSSETMAP_H
#define ABSTRACTIONS_COLLECTIONSSETMAP_H

#include<iostream>
#include <vector>
#include <set>
#include <map>
#include "tokenscanner.h"
#include "fstream"

using namespace std;

class CollectionsSetMap {
private:
    struct setEntry {
        set<char> str1chars;
        set<char> str2chars;
        set<char> str1only;
        set<char> str2only;
    };
    set<char> characterSet(string &str);
    set<char> setSubstract(set<char> &st1, set<char> &st2);
    set<string> setMultiply(set<string> &st1, set<string> &st2);
    set<string> setAddition(set<string> &st1, set<string> &st2);
    string swapChars(string s, int x1, int x2);
    set<string> swapCharsInDepth(string s, int steps);
    set<string> charSwapper(string str);
public:
    setEntry compareStrings(string &str1, string &str2);
    map<string, int> countWordsFromFile(string fileSrc);
    bool similarStrings(string str1, string str2, int steps);
};


#endif //ABSTRACTIONS_COLLECTIONSSETMAP_H
