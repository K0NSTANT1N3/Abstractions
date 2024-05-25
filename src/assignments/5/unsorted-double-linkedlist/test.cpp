#include <iostream>
#include "pqueue-doublylinkedlist.h"

using namespace std;

void testDoublyLinkedListPriorityQueue() {
    DoublyLinkedListPriorityQueue pq;

    // Test isEmpty on a new queue
    cout << "Testing isEmpty on a new queue: ";
    cout << (pq.isEmpty() ? "PASS" : "FAIL") << endl;

    // Test size on a new queue
    cout << "Testing size on a new queue: ";
    cout << (pq.size() == 0 ? "PASS" : "FAIL") << endl;

    // Enqueue elements
    cout << "Enqueueing elements..." << endl;
    pq.enqueue("Gamma");
    pq.enqueue("Alpha");
    pq.enqueue("Delta");
    pq.enqueue("Beta");

    // Test isEmpty after enqueue
    cout << "Testing isEmpty after enqueue: ";
    cout << (!pq.isEmpty() ? "PASS" : "FAIL") << endl;

    // Test size after enqueue
    cout << "Testing size after enqueue: ";
    cout << (pq.size() == 4 ? "PASS" : "FAIL") << endl;

    // Test peek (should be 'Alpha')
    cout << "Testing peek (should be 'Alpha'): ";
    cout << (pq.peek() == "Alpha" ? "PASS" : "FAIL") << endl;

    // Test dequeueMin (should be 'Alpha')
    cout << "Testing dequeueMin (should be 'Alpha'): ";
    cout << (pq.dequeueMin() == "Alpha" ? "PASS" : "FAIL") << endl;

    // Test size after one dequeueMin
    cout << "Testing size after one dequeueMin: ";
    cout << (pq.size() == 3 ? "PASS" : "FAIL") << endl;

    // Test peek after one dequeueMin (should be 'Beta')
    cout << "Testing peek after one dequeueMin (should be 'Beta'): ";
    cout << (pq.peek() == "Beta" ? "PASS" : "FAIL") << endl;

    // Test dequeueMin (should be 'Beta')
    cout << "Testing dequeueMin (should be 'Beta'): ";
    cout << (pq.dequeueMin() == "Beta" ? "PASS" : "FAIL") << endl;

    // Test size after two dequeueMin
    cout << "Testing size after two dequeueMin: ";
    cout << (pq.size() == 2 ? "PASS" : "FAIL") << endl;

    // Test dequeueMin (should be 'Delta')
    cout << "Testing dequeueMin (should be 'Delta'): ";
    cout << (pq.dequeueMin() == "Delta" ? "PASS" : "FAIL") << endl;

    // Test dequeueMin (should be 'Gamma')
    cout << "Testing dequeueMin (should be 'Gamma'): ";
    cout << (pq.dequeueMin() == "Gamma" ? "PASS" : "FAIL") << endl;

    // Test isEmpty after all elements dequeued
    cout << "Testing isEmpty after all elements dequeued: ";
    cout << (pq.isEmpty() ? "PASS" : "FAIL") << endl;
}

int main() {
    testDoublyLinkedListPriorityQueue();
    return 0;
}
