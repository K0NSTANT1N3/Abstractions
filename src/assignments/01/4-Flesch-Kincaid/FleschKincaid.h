//
// Created by konstantine on 3/24/24.
//
#ifndef ABSTRACTIONS_FLESCHKINCAID_H
#define ABSTRACTIONS_FLESCHKINCAID_H

#include <iostream>
#include <fstream>
#include "tokenscanner.h"
using namespace std;

class FleschKincaid {
private:
    const double c0 = -15.59;
    const double c1 = 0.39;
    const double c2 = 11.8;

    struct counts {
        int wordCount;
        int syllableCount;
        int sentenceCount;

        counts() {
            wordCount = 0;
            syllableCount = 0;
            sentenceCount = 0;
        }
    };

    double gradeFormula(int word, int syllabel, int sentence);

    counts count(string text);

    int countSyllables(string word);

    int isVowel(char ch);

    string getFileName();

    string fileToString(string name);
};

#endif //ABSTRACTIONS_FLESCHKINCAID_H