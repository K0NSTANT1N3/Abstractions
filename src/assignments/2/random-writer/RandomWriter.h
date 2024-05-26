//
// Created by konstantine on 4/7/24.
//

#ifndef ABSTRACTIONS_RANDOMWRITER_H
#define ABSTRACTIONS_RANDOMWRITER_H

#include <iostream>
#include <fstream>
#include <map>
#include "random.h"

using namespace std;

class RandomWriter {
private:
    static const int charNum = 2000;

    static char generateRandomChar(const map<char, double> &probability);

    static map<string, map<char, double>> createProbabilityList(const map<string, map<char, int>> &model);

    static void updateModel(int k, const string &line, map<string, map<char, int>> &model);

    static string calculateStarter(const map<string, map<char, int>> &model);

    static void readModelFromFile(int k, const string &src, map<string, map<char, int>> &model);

    static void generateText(const map<string, map<char, double>> &probability, const string &starter, int charNum);

public:
    static void markovModel(int k, string src);
};

#endif //ABSTRACTIONS_RANDOMWRITER_H
