#include <iostream>
#include "pqueue-linkedlist.h"

using namespace std;

void testInsertion(LinkedListPriorityQueue& pq) {
    pq.enqueue("C");
    pq.enqueue("A");
    pq.enqueue("B");

    cout << "After insertion, the priority queue should be A, B, C in priority order." << endl;
    cout << "Peek: " << pq.peek() << " (Expected: A)" << endl;
}

void testDeletion(LinkedListPriorityQueue& pq) {
    pq.dequeueMin();
    cout << "After deleting one element, the priority queue should be B, C." << endl;
    cout << "Peek: " << pq.peek() << " (Expected: B)" << endl;
}

void testCopyConstructor() {
    LinkedListPriorityQueue original;
    original.enqueue("C");
    original.enqueue("A");
    original.enqueue("B");

    LinkedListPriorityQueue copy = original;

    cout << "Testing copy constructor:" << endl;
    cout << "Original Peek: " << original.peek() << " (Expected: A)" << endl;
    cout << "Copy Peek: " << copy.peek() << " (Expected: A)" << endl;

    original.dequeueMin();
    cout << "After modifying original, copy should remain the same." << endl;
    cout << "Original Peek after dequeue: " << original.peek() << " (Expected: B)" << endl;
    cout << "Copy Peek: " << copy.peek() << " (Expected: A)" << endl;
}

void testIsEmptyAndSize(LinkedListPriorityQueue& pq) {
    cout << "Size: " << pq.size() << " (Expected: 2)" << endl;
    pq.dequeueMin();
    pq.dequeueMin();
    cout << "Size after removing all elements: " << pq.size() << " (Expected: 0)" << endl;
    cout << "Is Empty: " << pq.isEmpty() << " (Expected: true)" << endl;
}

int main() {
    LinkedListPriorityQueue pq;

    cout << "Testing Insertion:" << endl;
    testInsertion(pq);

    cout << "\nTesting Deletion:" << endl;
    testDeletion(pq);

    cout << "\nTesting Copy Constructor:" << endl;
    testCopyConstructor();

    cout << "\nTesting isEmpty and Size:" << endl;
    testIsEmptyAndSize(pq);

    return 0;
}
