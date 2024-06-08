//
// Created by konstantine on 6/3/24.
//

#ifndef ABSTRACTIONS_OURLEXICON_H
#define ABSTRACTIONS_OURLEXICON_H

#include <iostream>

using namespace std;

class OurLexicon {
private:
    struct Node {
        bool isWord;
        Node *elems[26];

        Node() {
            isWord = false;
            for (int i = 0; i < 26; i++) {
                this->elems[i] = nullptr;
            }
        }
    };

    Node *root;

    int recCountWords(Node *node);

    void checkWordIsValid(string word);

    void recAddWord(Node *&root, string word);

    void recRemoveWord(Node*& root, string word);

public:
    OurLexicon();

    ~OurLexicon();

    void recDeleteTrie(Node *root);

    bool isEmpty();

    int size();

    Node *recFindNode(Node *root, string word);

    bool containsPrefix(string prefix);

    void addWord(string word);

    void removeWord(string word);

};


#endif //ABSTRACTIONS_OURLEXICON_H
