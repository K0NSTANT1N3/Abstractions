#include "WordLadder.h"

/** private */
stack<string> WordLadder::oneStep(string s, Lexicon english) {
    stack<string> modified;
    for (int i = 0; i < s.size(); i++) {
        char curChar = s[i];

        for (char c = 'a'; c <= 'z'; c++) {
            if (curChar == c) continue; // Skip if the character is the same
            s[i] = c;
            if (english.contains(s)) {
                modified.push(s);
            }
            s[i] = curChar;
        }
    }
    return modified;
}

/** public */
stack<string> WordLadder::findLadder(string start, string dest) {
    Lexicon english("/home/konstantine/CLionProjects/Abstractions/src/assignments/2/word-ladder/EnglishWords.dat");

    queue<stack<string>> ladder;
    set<string> used;
    stack<string> path;

    path.push(start);
    ladder.push(path);
    used.insert(start);

    // Continue until the ladder queue is empty
    while (!ladder.empty()) {
        path = ladder.front();
        string cur = path.top();
        if (cur == dest)
            return path;
        ladder.pop();

        stack<string> newStrings = oneStep(cur, english);
        while (!newStrings.empty()) {
            string potentialMember = newStrings.top();
            newStrings.pop();

            if (used.find(potentialMember) == used.end()) {
                used.insert(potentialMember);
                stack<string> newPath = path;
                newPath.push(potentialMember);
                ladder.push(newPath);
            }
        }
    }
    return stack<string>();
}
// Path: src/assignments/2/word-ladder/WordLadder.h