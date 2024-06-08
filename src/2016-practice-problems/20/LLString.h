//
// Created by konstantine on 6/7/24.
//

#ifndef ABSTRACTIONS_LLSTRING_H
#define ABSTRACTIONS_LLSTRING_H

#include<iostream>

using namespace std;

class LLString {
private:
    struct Node{
        char value;
        Node* next;

        Node(){
            this -> next = nullptr;
        }
    };

    Node* head;
public:
    explicit LLString(string other = "");
    LLString(LLString &other);
    ~LLString();
    string toString();
    LLString grow(LLString& other);
};


#endif //ABSTRACTIONS_LLSTRING_H
