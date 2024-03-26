/*******************************************************************
 * File: FleschKincaid.cpp
 *
 * A program that approximates the Flesch-Kincaid grade level of a
 * piece of text.
 */

#include "FleschKincaid.h"

using namespace std;

double FleschKincaid::gradeFormula(int word, int syllabel, int sentence) {
    return c0 + c1 * (word / sentence) + c2 * (syllabel / word);
}

//counts words, syllables and sentences
FleschKincaid::counts FleschKincaid::count(string text) {
    counts result;
    TokenScanner scanner(text);
    scanner.ignoreWhitespace();
    scanner.addWordCharacters("'");

    string prevToken = "";

    while (scanner.hasMoreTokens()) {
        string token = scanner.nextToken();
        if (token == "." && prevToken[prevToken.size() - 1] - '0' >= 0 && prevToken[prevToken.size() - 1] - '0' <= 9) {
            prevToken = token;
            continue;
        }
        prevToken = token;

        //counting words and syllables
        if (((token[0] >= 'A' && token[0] <= 'Z') || (token[0] >= 'a' && token[0] <= 'z')) && token.size() > 1) {
            result.wordCount++;
            result.syllableCount += countSyllables(token);
        }
        //counting single letter words
        if (token == "a" || token == "i" || token == "A" || token == "I") {
            result.syllableCount++;
            result.wordCount++;
        }
        //counting sentences
        if (token == "!" || token == "?" || token == "." || token == "..." || token == "!?" || token == "?!") {
            result.sentenceCount++;
            cout << token << endl;
        }
    }

    if (result.sentenceCount == 0) result.sentenceCount = 1;
    if (result.wordCount == 0) result.wordCount = 1;

    return result;
}

// counts syllables in a word
int FleschKincaid::countSyllables(string word) {
    int count = 0;
    if (isVowel(word[0]))count++;
    for (int i = 1; i < word.size(); i++) {
        if (!isVowel(word[i - 1]) && isVowel(word[i])) {
            count++;
        }
    }
    if (word[word.size() - 1] == 'e') {
        count--;
    }
    return count;
}

//checks if a character is a vowel
int FleschKincaid::isVowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y';
}

//checks if filename is valid
string FleschKincaid::getFileName() {
    string fileName;

    while (true) {
        cout << "Enter the file name: ";
        cin >> fileName;

        string line = "";
        ifstream file(fileName);
        if (file.is_open()) {
            getline(file, line);
            if (line.size() > 0) {
                break;
            }
        }
    }
    return fileName;
}

//reads file to string
string FleschKincaid::fileToString(string name) {
    ifstream file(name);
    string txt, ln;
    while (getline(file, ln)) {
        txt += ln + "\n";
    }
    return txt;
}