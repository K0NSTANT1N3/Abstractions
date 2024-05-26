/*************************************************************
 * File: pqueue-vector.cpp
 *
 * Implementation file for the VectorPriorityQueue
 * class.
 */

#include "pqueue-vector.h"
//#include "error.h"

VectorPriorityQueue::VectorPriorityQueue() { // O(1)
    this->elems = new vector<string>();
}

VectorPriorityQueue::VectorPriorityQueue(const VectorPriorityQueue &other) {
    this->elems = new vector<string>(*other.elems);
}

VectorPriorityQueue::~VectorPriorityQueue() { // O(1)
    delete this->elems;
}

int VectorPriorityQueue::size() { // O(1)
    return this->elems->size();
}

bool VectorPriorityQueue::isEmpty() { // O(1)
    return this->elems->size() == 0;
}

void VectorPriorityQueue::enqueue(string value) { // O(1)
    this->elems->push_back(value);
}

string VectorPriorityQueue::peek() { // O(n)
    if (isEmpty()) {
//        error("queue is empty");
        return NULL;
    }
    return this->elems->at(indexOfMinimal());
}

string VectorPriorityQueue::dequeueMin() { // O(n)
    if (isEmpty()) {
//        error("queue is empty");
        return NULL;
    }
    string ans = this->elems->at(indexOfMinimal());
    this->elems->erase(this->elems->begin() + indexOfMinimal());
    return ans;
}

/** private */
int VectorPriorityQueue::indexOfMinimal() { // O(n)
    int minimal = 0;
    for (int i = 1; i < this->elems->size(); i++) {
        if (this->elems->at(i) < this->elems->at(minimal)) {
            minimal = i;
        }
    }
    return minimal;
}

