/*************************************************************
 * File: pqueue-doublylinkedlist.cpp
 *
 * Implementation file for the DoublyLinkedListPriorityQueue
 * class.
 */

#include "pqueue-doublylinkedlist.h"
#include "error.h"

DoublyLinkedListPriorityQueue::DoublyLinkedListPriorityQueue() {
    this->head = nullptr;
    this->locLength = 0;
}

DoublyLinkedListPriorityQueue::~DoublyLinkedListPriorityQueue() {
    while (this->head != nullptr) {
        Node *tmp = this->head;
        this->head = this->head->next;
        delete tmp;
    }
    locLength = 0;
}

int DoublyLinkedListPriorityQueue::size() {
    return locLength;
}

bool DoublyLinkedListPriorityQueue::isEmpty() {
    return locLength == 0;
}

void DoublyLinkedListPriorityQueue::enqueue(string value) {
    Node *tmp = new Node(value, head, nullptr);
    if (head != nullptr) {
        head->prev = tmp;
    }
    head = tmp;
    locLength++;
}

string DoublyLinkedListPriorityQueue::peek() {
    if (this->head == nullptr) {
        error("Attempting to peek from an empty queue");
    }

    string minVal = this->head->value;
    for (Node *itr = this->head->next; itr != nullptr; itr = itr->next) {
        if (itr->value < minVal) {
            minVal = itr->value;
        }
    }
    return minVal;
}

string DoublyLinkedListPriorityQueue::dequeueMin() {
    if (this->head == nullptr) {
        error("Attempting to dequeue from an empty queue");
    }

    Node *minNode = head;
    for (Node *itr = this->head->next; itr != nullptr; itr = itr->next) {
        if (itr->value < minNode->value) {
            minNode = itr;
        }
    }

    if (minNode->prev != nullptr) {
        minNode->prev->next = minNode->next;
    }
    if (minNode->next != nullptr) {
        minNode->next->prev = minNode->prev;
    }
    if (minNode == head) {
        head = minNode->next;
    }
    string ans = minNode->value;
    delete minNode;
    locLength--;

    return ans;
}

