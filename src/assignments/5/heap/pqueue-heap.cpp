/**
 * File: pqueue-heap.cpp
 *
 * Implementation file for the HeapPriorityQueue
 * class.
 */

#include "pqueue-heap.h"
#include "error.h"

HeapPriorityQueue::HeapPriorityQueue() {
    this->locLength = 0;
    this->allocLength = 2;
    this->head = new string[allocLength];
}

HeapPriorityQueue::~HeapPriorityQueue() {
    delete[] head;
    locLength = allocLength = 0;
}

int HeapPriorityQueue::size() {
    return locLength;
}

bool HeapPriorityQueue::isEmpty() {
    return locLength == 0;
}

void HeapPriorityQueue::enqueue(string value) {
    lengthenSize();

    head[locLength] = value;
    locLength++;

    bubbleUp(locLength - 1);
}

string HeapPriorityQueue::peek() {
    if (locLength == 0) {
        error("No element");
        return NULL;
    }
    return this->head[0];
}

string HeapPriorityQueue::dequeueMin() {
    if (locLength == 0) {
        error("No element");
        return NULL;
    }

    string tmp = this->head[0];
    this->head[0] = this->head[locLength - 1];
    locLength--;
    bubbleDown(0);
    return tmp;
}

/** private */
void HeapPriorityQueue::bubbleUp(int index) {
    if (index == 0)return;

    int parentIndex = (index + 1) / 2 - 1;

    if (this->head[parentIndex] <= this->head[index]) {
        return;
    }

    std::swap(head[parentIndex], head[index]);
    bubbleUp(parentIndex);
}

void HeapPriorityQueue::bubbleDown(int index) {
    /* Initialising */
    int rightSonIndex = (index + 1) * 2;
    int leftSonIndex = rightSonIndex - 1;
    int smallest = index;

    /* Base Case */
    if (leftSonIndex < locLength && head[leftSonIndex] < head[smallest]) {
        smallest = leftSonIndex;
    }
    if (rightSonIndex < locLength && head[rightSonIndex] < head[smallest]) {
        smallest = rightSonIndex;
    }

    if (smallest != index) {
        std::swap(head[index], head[smallest]);
        bubbleDown(smallest);
    }
}

void HeapPriorityQueue::lengthenSize() {
    if (locLength >= allocLength) {
        allocLength *= 2;
        auto *newHead = new string[allocLength];
        for (int i = 0; i < locLength; i++) {
            newHead[i] = head[i];
        }
        delete[] head;
        head = newHead;
    }
}

