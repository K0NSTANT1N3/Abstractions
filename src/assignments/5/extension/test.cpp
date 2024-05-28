#include <iostream>
#include "pqueueLinkedHeap.h"

using namespace std;

int main() {
    // Test constructor and size
    pqueueLinkedHeap pq;
    cout << "Initial size: " << pq.size() << endl;

    // Test isEmpty
    cout << "Is empty? " << (pq.isEmpty() ? "Yes" : "No") << endl;

    // Test enqueue
    pq.enqueue("C");
    pq.enqueue("A");
    pq.enqueue("D");
    pq.enqueue("B");
    cout << "Size after enqueue: " << pq.size() << endl;

    // Test peek
    cout << "Peek: " << pq.peek() << endl;

    cout << "toString " << pq.toString();
    // Test dequeueMin
    cout << "Dequeue min: " << pq.dequeueMin() << endl;

    cout << "Size after dequeue: ";
    cout << pq.size();
    cout << endl;

    // Test dequeueMin when queue is empty
    while (!pq.isEmpty()) {
        cout << "Dequeue min: " << pq.dequeueMin() << endl;
        cout << "Size after dequeue: " << pq.size() << endl;
    }


    // Test peek when queue is empty
    cout << "Peek: " << pq.peek() << endl;

    return 0;
}
