/*************************************************************
 * File: pqueue-linkedlist.cpp
 *
 * Implementation file for the LinkedListPriorityQueue
 * class.
 */

#include "pqueue-linkedlist.h"
#include "error.h"

LinkedListPriorityQueue::LinkedListPriorityQueue() {
    this->head = nullptr;
    locLength = 0;
}

LinkedListPriorityQueue::LinkedListPriorityQueue(const LinkedListPriorityQueue &other) {
    if (other.head == nullptr) {
        head = nullptr;
        return;
    }

    head = new Node(other.head->value, nullptr);
    Node *cur = head;
    for (Node *iter = other.head->next; iter != nullptr; iter = iter->next) {
        cur->next = new Node(iter->value, nullptr);
        cur = cur->next;
    }
    locLength = other.locLength;
}

LinkedListPriorityQueue::~LinkedListPriorityQueue() {
    for (Node *iter = this->head; iter != nullptr;) {
        Node *tmp = iter;
        iter = iter->next;
        delete tmp;
    }
    locLength = 0;
}

int LinkedListPriorityQueue::size() {
    return locLength;
}

bool LinkedListPriorityQueue::isEmpty() {
    return locLength == 0;
}

void LinkedListPriorityQueue::enqueue(string value) {
    locLength++;
    if(head== nullptr){
       head = new Node(value, nullptr);
       return;
   }

    Node *newNode;
    if (value < this->head->value) {
        newNode = new Node(value, head);
        head = newNode;
        return;
    }

    for (Node *iter = head; iter != nullptr; iter = iter->next) {
        if (iter->next == nullptr || value < iter->next->value) {
            newNode = new Node(value, iter->next);
            iter->next = newNode;
            return;
        }
    }
}

string LinkedListPriorityQueue::peek() {
    if (head == nullptr)return nullptr;
    return this->head->value;
}

string LinkedListPriorityQueue::dequeueMin() {
    if (head == nullptr)return nullptr;

    locLength --;
    Node *tmp = head;
    head = head->next;
    string ans = tmp->value;
    delete tmp;
    return ans;
}



