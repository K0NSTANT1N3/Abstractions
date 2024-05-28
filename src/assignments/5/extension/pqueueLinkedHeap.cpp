//
// Created by konstantine on 5/28/24.
//

#include "pqueueLinkedHeap.h"

/** public */
pqueueLinkedHeap::pqueueLinkedHeap() {
    this->head = nullptr;
    this->locLength = 0;
}

pqueueLinkedHeap::~pqueueLinkedHeap() {
    removeRecursion(this->head);
    locLength = 0;
}

int pqueueLinkedHeap::size() {
    return locLength;
}

bool pqueueLinkedHeap::isEmpty() {
    return locLength == 0;
}

string pqueueLinkedHeap::peek() {
    if (head == nullptr) {
        return "";
    }
    return head->value;
}

void pqueueLinkedHeap::enqueue(string value) {
    if(value == "")return;
    if (head == nullptr) {
        head = new Node(value, nullptr, nullptr);
        locLength = 1;
        return;
    }
    Node *leaf = new Node(value, nullptr, nullptr);
    enqueueRecursion(locLength, this->head, leaf);
    locLength++;
}

string pqueueLinkedHeap::dequeueMin() {
    if (head == nullptr || locLength <= 0) {
        return "";
    }

    string tmp = head->value;
    if (locLength == 1) {
        delete head;
        head = nullptr;
        locLength--;
        return tmp;
    }

    getLastElem(head, locLength);
    locLength--;
    bubbleDown(head);
    return tmp;
}

string pqueueLinkedHeap::toString() {
    if (head == nullptr) {
        return "";
    }

    return toStringRecursion(head);
}

/** private */
void pqueueLinkedHeap::enqueueRecursion(int elNums, pqueueLinkedHeap::Node *root, pqueueLinkedHeap::Node *leaf) {
    /* Base Case */
    if (root == nullptr) {
        return;
    }

    if (root->value > leaf->value) {
        swapValues(leaf, root);
    }

    if (root->left == nullptr) {
        root->left = leaf;
        return;
    }
    if (root->right == nullptr) {
        root->right = leaf;
        return;
    }

    /* Variable Initializing */
    int filledDepth = (lowerBoundLog2(elNums + 1));
    int filledTree = (1 << filledDepth) - 1;
    int rem = elNums - filledTree;
    int lowerFilled = filledTree - ((1 << (filledDepth - 1)) - 1);

    /* Inductive Step */
    if (lowerFilled > rem) {
        return enqueueRecursion(rem + filledTree / 2, root->left, leaf);
    } else {
        return enqueueRecursion(rem - lowerFilled + filledTree / 2, root->right, leaf);
    }
}

int pqueueLinkedHeap::lowerBoundLog2(int n) {
    if (n <= 0) {
        return -1;
    }

    int ans = 0;
    while ((1 << ans) <= n) {
        ans++;
    }

    return --ans;
}

void pqueueLinkedHeap::swapValues(pqueueLinkedHeap::Node *&first, pqueueLinkedHeap::Node *&second) {
    if (first == nullptr || second == nullptr)return;

    string tmp = first->value;
    first->value = second->value;
    second->value = tmp;
}

void pqueueLinkedHeap::removeRecursion(pqueueLinkedHeap::Node *&root) {
    if (root == nullptr)return;

    removeRecursion(root->left);
    removeRecursion(root->right);
    delete root;
}

void pqueueLinkedHeap::getLastElem(pqueueLinkedHeap::Node *root, int elNums) {
    /* Base Case */
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr) {
        swapValues(root, head);
        root->value = "";
        root = nullptr;
        delete root;
        return;
    }
    if (root->right == nullptr) {
        swapValues(root->left, head); // Swap values of the last element and the head node
        root->left->value = "";
        root->left = nullptr; // Set the left child to nullptr after deletion
        delete root->left; // Delete the last node
        return;
    }

    /* Variable Initializing */
    int filledDepth = (lowerBoundLog2(elNums + 1));
    int filledTree = (1 << filledDepth) - 1;
    int rem = elNums - filledTree;
    int lowerFilled = filledTree - ((1 << (filledDepth - 1)) - 1);

    if (lowerFilled >= rem && rem != 0) {
        getLastElem(root->left, rem + filledTree / 2);
        Node* leftLeafe = root->left;
        string tmp = leftLeafe->value;
        if(root ->left->value == ""){
            root->left = nullptr;
            delete root->left;
        }
    } else {
        getLastElem(root->right, rem - lowerFilled + filledTree / 2);
        Node* rightLeaf = root->right;
        string tmp = rightLeaf->value;
        if(root ->right->value == ""){
            root->right = nullptr;
            delete root->right;
        }
    }
}

void pqueueLinkedHeap::bubbleDown(pqueueLinkedHeap::Node *root) {
    /* Base Case */
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr) {
        return;
    }

    Node *minLeaf = root->left;
    if (root->right != nullptr) {
        if (minLeaf->value > root->right->value) {
            minLeaf = root->right;
        }
    }

    if (root->value < minLeaf->value) {
        return;
    }

    swapValues(root, minLeaf);
    bubbleDown(minLeaf);
}

string pqueueLinkedHeap::toStringRecursion(pqueueLinkedHeap::Node *root) {
    if (root == nullptr) return "";

    return root->value +
           " [ " + toStringRecursion(root->left) + " ] " +
           " [ " + toStringRecursion(root->right) + " ] ";
}

