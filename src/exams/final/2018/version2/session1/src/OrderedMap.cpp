//
// Created by konstantine on 7/4/24.
//

#include "OrderedMap.h"

OrderedMap::OrderedMap() {
    logLen = iterator = 0;
    lastElemIndex = -1;
    allocLen = 4;
    root = nullptr;
    cont = new Pair[allocLen];
}

void OrderedMap::put(int key, int value) {
    if (logLen == 0) {
        root = new Node(Pair(key, value), 0);
        cont[0] = Pair(key, value);
        logLen = 1;
        lastElemIndex = 0;
        return;
    }

    if (logLen == allocLen || lastElemIndex + 2 == allocLen) {
        allocLen *= 2;
        Pair *newCont = new Pair[allocLen];
        for (int i = 0; i < lastElemIndex + 1; i++) {
            newCont[i] = cont[i];
        }
        delete[] cont;
        cont = newCont;
    }
    lastElemIndex++;
    cont[lastElemIndex] = Pair(key, value);
    Node *cur = root;
    Node *parent = root;
    while (cur != nullptr) {
        parent = cur;
        if (key < cur->pair.key) {
            cur = cur->left;
        } else if (key > cur->pair.key) {
            cur = cur->right;
        } else if (key == cur->pair.key) {
            cur->pair.value = value;
            return;
        }
    }

    if (key < parent->pair.key) {
        parent->left = new Node(Pair(key, value), lastElemIndex);
    } else if (key > parent->pair.key) {
        parent->right = new Node(Pair(key, value), lastElemIndex);
    }
    logLen++;
}

int OrderedMap::get(int key) {
    Node *cur = root;
    while (cur->pair.key != key) {
        if (key < cur->pair.key) {
            cur = cur->left;
        } else if (key > cur->pair.key) {
            cur = cur->right;
        }
    }
    return cur->pair.value;
}

int OrderedMap::size() {
    return logLen;
}

OrderedMap::Node *OrderedMap::leftMostParent(OrderedMap::Node *head) {
    Node *cur = head;
    Node *parent = head;
    while (cur->left != nullptr || cur->right != nullptr) {
        parent = cur;
        if (cur->left == nullptr) {
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }
    return parent;
}

void OrderedMap::swapNode(OrderedMap::Node *node1, OrderedMap::Node * node2) {
    Pair tempPr = node1->pair;
    int tempIx = node1->index;

    node1->pair = node2->pair;
    node1->index = node2->index;

    node2->pair = tempPr;
    node2->index = tempIx;
}


void OrderedMap::correctPosition(OrderedMap::Node *curr) {
    if(curr == nullptr)return;

    if(curr->left != nullptr && curr->pair.key < curr->left->pair.key){
        swapNode(curr, curr->left);
        correctPosition(curr->left);
    }
    if(curr->right != nullptr && curr->pair.key > curr->right->pair.key){
        swapNode(curr, curr->right);
        correctPosition(curr->right);
    }
}

void OrderedMap::remove(int key) {
    Node *cur = root;
    Node *parent = nullptr;
    while (cur->pair.key != key) {
        parent = cur;
        if (key < cur->pair.key) {
            cur = cur->left;
        } else if (key > cur->pair.key) {
            cur = cur->right;
        }
    }
    int ix = cur->index;
    cont[ix] = Pair(-1, -1);
    if(ix == lastElemIndex){
        lastElemIndex--;
    }

    if (cur->left == nullptr && cur->right == nullptr) {
        if (parent->left->pair.key == cur->pair.key) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        delete cur;
        logLen--;
        return;
    }

    if (cur->left == nullptr) {
        if (parent->left->pair.key == cur->pair.key) {
            parent->left = cur->right;
        } else {
            parent->right = cur->right;
        }
        delete cur;
        logLen--;
        return;
    }

    if (cur->right == nullptr) {
        if (parent->left->pair.key == cur->pair.key) {
            parent->left = cur->left;
        } else {
            parent->right = cur->left;
        }
        delete cur;
        logLen--;
        return;
    }

    Node *leftMost = leftMostParent(cur);
    Node *leftest;
    if (leftMost->left != nullptr) {
        leftest = leftMost->left;
        leftMost->left = nullptr;
    } else {
        leftest = leftMost->right;
        leftMost->right = nullptr;
    }

    swapNode(cur, leftest);
    delete leftest;

    correctPosition(cur);
    logLen--;
}

bool OrderedMap::containsKey(int key) {
    Node *cur = root;
    Node *parent = root;
    while (cur != nullptr) {
        parent = cur;
        if (key < cur->pair.key) {
            cur = cur->left;
        } else if (key > cur->pair.key) {
            cur = cur->right;
        } else if (key == cur->pair.key) {
            return true;
        }
    }
    return false;
}

void OrderedMap::resetIterator() {
    iterator = 0;
}

bool OrderedMap::hasNext() {
    if(lastElemIndex == -1)return false;
    return iterator <= lastElemIndex;
}

int OrderedMap::next() {
    while(lastElemIndex >= iterator && cont[iterator].key == -1){
        iterator++;
    }
    int ans = cont[iterator].key;
    iterator++;
    return ans;
}

