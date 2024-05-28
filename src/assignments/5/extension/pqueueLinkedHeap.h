//
// Created by konstantine on 5/28/24.
//

#ifndef ABSTRACTIONS_PQUEUELINKEDHEAP_H
#define ABSTRACTIONS_PQUEUELINKEDHEAP_H

#include <iostream>

using namespace std;

class pqueueLinkedHeap {
public:
    /* Constructs a new, empty priority queue backed by a binary heap. */
    pqueueLinkedHeap();

    /* Cleans up all memory allocated by this priority queue. */
    ~pqueueLinkedHeap();

    /* Returns the number of elements in the priority queue. */
    int size();

    /* Returns whether or not the priority queue is empty. */
    bool isEmpty();

    /* Enqueues a new string into the priority queue. */
    void enqueue(string value);

    /* Returns, but does not remove, the lexicographically first string in the
     * priority queue.
     */
    string peek();

    /* Returns and removes the lexicographically first string in the
     * priority queue.
     */
    string dequeueMin();

    string toString();
private:
    struct Node {
        string value;
        Node *left;
        Node *right;

        Node() {
            value = "";
            left = right = nullptr;
        }

        Node(string value, Node *left, Node *right) {
            this->value = value;
            this->right = right;
            this->left = left;
        }
    };

    Node *head;
    int locLength;

    void enqueueRecursion(int elNums, Node *root, Node *leaf);

    int lowerBoundLog2(int n);

    void swapValues(Node *&first, Node *&second);

    void removeRecursion(Node *&root);

    void getLastElem(Node* root, int elNums);

    void bubbleDown(Node* root);

    string toStringRecursion(Node* root);

};


#endif //ABSTRACTIONS_PQUEUELINKEDHEAP_H
