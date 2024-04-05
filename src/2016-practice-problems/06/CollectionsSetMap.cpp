//
// Created by konstantine on 4/2/24.
//

#include "CollectionsSetMap.h"

/** private */
set<char> CollectionsSetMap::characterSet(string &str) {
    set<char> result;
    for (char c: str) {
        result.insert(c);
    }
    return result;
}

set<char> CollectionsSetMap::setSubstract(set<char> &st1, set<char> &st2) {
    set<char> ans;

    for (char c: st1) {
        if (st2.find(c) == st2.end()) {
            ans.insert(c);
        }
    }
    return ans;
}

set<string> CollectionsSetMap::setMultiply(set<string> &st1, set<string> &st2) {
    set<string> intersection;
    for (string s: st2) {
        if (st1.find(s) != st1.end())
            intersection.insert(s);
    }
    return intersection;
}

set<string> CollectionsSetMap::setAddition(set<string> &st1, set<string> &st2) {
    set<string> sum = st1;
    for (string s: st2) {
        if (st1.find(s) == st1.end())
            sum.insert(s);
    }
    return sum;
}

string CollectionsSetMap::swapChars(string s, int x1, int x2) {
    string res = s;
    res[x1] = s[x2];
    res[x2] = s[x1];
    return res;
}

set<string> CollectionsSetMap::charSwapper(string str) {
    set<string> res;

    for (int i = 0; i < str.size() - 1; i++) {
        for (int j = i + 1; j < str.size(); j++) {
            res.insert(swapChars(str, i, j));
        }
    }
    return res;
}

set<string> CollectionsSetMap::swapCharsInDepth(string s, int steps) {
    if(steps == 0)return {s};
    set<string> res = swapCharsInDepth(s, steps - 1);
    for(string str: res){
        set<string> tmp = charSwapper(str);
        res = setAddition(res, tmp);
    }

    return res;
}


/** public */
CollectionsSetMap::setEntry CollectionsSetMap::compareStrings(string &str1, string &str2) {
    setEntry result;
    result.str1chars = characterSet(str1);
    result.str2chars = characterSet(str2);

    result.str1only = setSubstract(result.str1chars, result.str2chars);
    result.str2only = setSubstract(result.str2chars, result.str1chars);

    return result;
}

map<string, int> CollectionsSetMap::countWordsFromFile(string fileSrc) {
    ifstream inputFIle;
    inputFIle.open(fileSrc);

    TokenScanner scanner(inputFIle);
    scanner.ignoreWhitespace();

    map<string, int> words;

    while (scanner.hasMoreTokens()) {
        string curWord = scanner.nextToken();

        if (words.find(curWord) == words.end()) words[curWord] = 1;
        else words[curWord]++;
    }

    inputFIle.close();

    return words;
}

bool CollectionsSetMap::similarStrings(string str1, string str2, int steps) {
    set<string> swaped1 = swapCharsInDepth(str1, steps / 2);
    set<string> swaped2 = swapCharsInDepth(str2, steps - steps / 2);

    return setMultiply(swaped1, swaped2).size() > 0;
}

