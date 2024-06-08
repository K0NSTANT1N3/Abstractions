//
// Created by konstantine on 6/7/24.
//

#include "LLString.h"

LLString::LLString(string other) {
    head = new Node;
    Node *tail = head;
    for (int i = 0; i < other.size(); i++) {
        Node *tmp = new Node;
        tmp->value = other[i];
        tmp->next = nullptr;
        tail->next = tmp;
        tail = tmp;
    }
}

LLString::LLString(LLString &other) {
    this->head = new Node;
    Node *tail = head;
    for (Node *ptr = other.head->next; ptr != nullptr; ptr = ptr->next) {
        Node *tmp = new Node;
        tmp->value = ptr->value;
        tmp->next = nullptr;
        tail->next = tmp;
        tail = tmp;
    }
}

LLString::~LLString() {
    while (head != nullptr) {
        Node *tmp = head->next;
        delete head;
        head = tmp;
    }
}

string LLString::toString() {
    string res = "";
    for (Node *ptr = this->head->next; ptr != nullptr; ptr = ptr->next) {
        res += ptr->value;
    }
    return res;
}

LLString LLString::grow(LLString &other) {
    LLString otherCopy(other);
    LLString result;
    Node *tail = result.head;
    for (Node *ptr = head->next; ptr != nullptr; ptr = ptr->next) {
        Node *tmp = new Node;
        tmp->value = ptr->value;
        tmp->next = nullptr;
        tail->next = tmp;
        tail = tmp;
    }
    tail->next = otherCopy.head->next;
    return result;
}





