//
// Created by konstantine on 4/15/24.
//

#ifndef ABSTRACTIONS_ANAGRAMCLUSTERS_H
#define ABSTRACTIONS_ANAGRAMCLUSTERS_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "lexicon.h"

using namespace std;

class AnagramClusters {
private:
    map<char, int> getCharFrequency(string str);
    string sortString(string str);
public:
    map<string, set<string> > getAnagramClusters(Lexicon lex);
};

#endif //ABSTRACTIONS_ANAGRAMCLUSTERS_H