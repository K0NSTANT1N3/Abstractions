/*
 * File: WordLadder.cpp
 * --------------------------
 * Name: Konstantine Endeladze
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Word Ladder problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
//#include "console.h" // You may need to include this header if it's required by your code.
#include <set>
#include <queue>
#include <stack>
#include <fstream>

using namespace std;

// Function to generate all possible single-character modifications of a string
stack<string> oneStep(string s, set<string> english) {
    stack<string> modified;
    for (int i = 0; i < s.size(); i++) {
        char curChar = s[i];

        for (char c = 'a'; c <= 'z'; c++) {
            if (curChar == c)continue;// Skip if the character is the same
            s[i] = c;
            if (english.find(s) != english.end()) {
                modified.push(s);
            }
            s[i] = curChar;
        }
    }
    return modified;
}

// Function to create a set of strings from a file
set<string> createLexicon(string path){
    set<string> lexicon;
    ifstream file(path);

    // Check if the file is opened successfully
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << path << endl;
        return lexicon;
    }

    string word;
    while(file >> word){
        lexicon.insert(word);
    }

    return lexicon;
}

// Function to find the shortest word ladder between two words
stack<string> wordLadder(string start, string dest) {
    set<string> english = createLexicon("/home/konstantine/CLionProjects/Abstractions/src/assignments/02/random-writer/TomSawyer.txt");

    queue<stack<string> > ladder;
    set<string> used;
    stack<string> path;

    path.push(start);
    ladder.push(path);
    used.insert(start);

    while (!ladder.empty()) {
        path = ladder.front();
        string cur = path.top();
        if (cur == dest)return path;
        ladder.pop();

        stack<string> newStrings = oneStep(start, english);
        while(!newStrings.empty()){
            string potentialMember = newStrings.top();
            newStrings.pop();

            if(used.find(potentialMember) != used.end()){
                used.insert(potentialMember);
                stack<string> newPath = path;
                newPath.push(potentialMember);
                ladder.push(newPath);
            }
        }
    }

    return stack<string>();
}

int main() {
    string st1, st2;
    st1 = "woman", st2 = "women";
    stack<string> ladder = wordLadder(st1, st2);
    while(!ladder.empty()){
        cout << ladder.top() << endl;
        ladder.pop();
    }

    set<string> lexicon = createLexicon("/home/konstantine/CLionProjects/Abstractions/src/assignments/02/random-writer/TomSawyer.txt");
    for(auto &i : lexicon){
        cout << i << endl;
    }

//    Lexicon lexicon;
//    lexicon.addWordsFromFile("/home/konstantine/CLionProjects/Abstractions/src/assignments/02/EnglishWords.dat");
//    for(string word : lexicon){
//        cout << word << endl;
//    }

    return 0;
}
