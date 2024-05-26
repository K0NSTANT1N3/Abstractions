//
// Created by konstantine on 4/7/24.
//

/*
 * File: WordLadder.cpp
 * --------------------------
 * Name: Konstantine Endeladze
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Word Ladder problem.
 * [TODO: rewrite the documentation]
 */

#ifndef ABSTRACTIONS_WORDLADDER_H
#define ABSTRACTIONS_WORDLADDER_H

#include <iostream>
#include <set>
#include <queue>
#include <stack>
#include "lexicon.h"

using namespace std;

class WordLadder {
private:
    stack<string> oneStep(string s, Lexicon english);
public:
    stack<string> findLadder(string start, string dest);
};

#endif //ABSTRACTIONS_WORDLADDER_H
