//
// Created by konstantine on 4/5/24.
//

/*
 * File: RandomWriter.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Random Writer problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "console.h"
#include <fstream>
#include <vector>
#include <map>
#include "random"

using namespace std;

const int generatedTextLength = 2000;

void markovModel(int k, string src) {
    ifstream file(src);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << src << endl;
        return;
    }
    map<string, map<char, int> > model;

    string line;
    string starter = "";
    int popularity = 0;
    //classify models and their following characters
    while (getline(file, line)) {
        for (int i = 0; i < line.size() - k; i++) {
            string key = line.substr(i, k);
            char nextChar = line[i + k];
            if(model.find(key) == model.end()){
                model[key] = map<char, int>();
            }
            if(model[key].find(nextChar) == model[key].end()){
                model[key][nextChar] = 0;
            }
            model[key][nextChar]++;

            int newPopularity = 0;
            for (auto &i : model[key]) {
                newPopularity += i.second;
            }
            starter = newPopularity > popularity ? key : starter;
            popularity = newPopularity > popularity ? newPopularity : popularity;
        }
    }

    //create probability list
    map<string, map<char, double> > probability;
    for(auto &i : model){

    }

    //create new text file for output
    ofstream output("output.txt");
    if (!output.is_open()) {
        cerr << "Error: Unable to open file output.txt" << endl;
        return;
    }

    //generate random text
    int charCount = 0;
    while(charCount < generatedTextLength) {
        char nextChar;
        for(auto &i : model[starter]){

        }
    }


}


int main() {
    // [TODO: fill with your code]
    return 0;
}


