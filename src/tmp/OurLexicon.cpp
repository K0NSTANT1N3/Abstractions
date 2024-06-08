//
// Created by konstantine on 6/3/24.
//

#include <cstring>
#include "OurLexicon.h"

OurLexicon::Node *OurLexicon::recFindNode(OurLexicon::Node *root, string word) {
    if (root == nullptr)return nullptr;
    if (word == "")return root;

    int index = word[0] - 'a';
    return recFindNode(root->elems[index], word.substr(1));
}

void OurLexicon::recAddWord(Node *&root, string word) {
    if (root == nullptr) {
        root = new Node;
    }
    if (word == "") {
        root->isWord = true;
        return;
    }
    int index = word[0] - 'a';
    recAddWord(root->elems[index], word.substr(1));
}

void OurLexicon::addWord(string word) {
    recAddWord(root, word);
}

void OurLexicon::recRemoveWord(OurLexicon::Node *&root, string word) {
    if (root == nullptr) return;
    if (word == "") {
        root->isWord = false;
    }
    else{
        int index = word[0] - 'a';
        recRemoveWord(root->elems[index], word.substr(1));
    }
    if(root->isWord)return;
    bool hasNodes = false;
    for (int i = 0; i < 26; i++) {
        if(root->elems[i] != nullptr){
            hasNodes = true;
            break;
        }
    }
    if(!hasNodes){
        delete root;
        root = nullptr;
    }
}



