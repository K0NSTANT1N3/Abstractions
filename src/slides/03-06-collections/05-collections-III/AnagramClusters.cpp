//
// Created by konstantine on 4/15/24.
//

#include "AnagramClusters.h"

/** private */
map<char, int> AnagramClusters::getCharFrequency(string str) {
    map<char, int> freq;
    for (char c: str) {
        freq[c]++;
    }
    return freq;
}

string AnagramClusters::sortString(string str) {
    map<char, int> freq = getCharFrequency(str);
    string sorted;
    for (auto pair: freq) {
        for (int i = 0; i < pair.second; i++) {
            sorted += pair.first;
        }
    }
    return sorted;
}

/** public */
map<string, set<string> > AnagramClusters::getAnagramClusters(Lexicon lex) {
    map<string, set<string> > clusters;
    for (string word: lex) {
        string sorted = sortString(word);
        clusters[sorted].insert(word);
    }
    return clusters;
}


