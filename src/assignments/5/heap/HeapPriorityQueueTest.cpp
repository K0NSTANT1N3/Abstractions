#include <iostream>
#include <cassert>
#include "pqueue-heap.h"

void testInitialState() {
    HeapPriorityQueue pq;
    assert(pq.isEmpty() == true);
    assert(pq.size() == 0);
    std::cout << "testInitialState passed!" << std::endl;
}

void testEnqueueSingleElement() {
    HeapPriorityQueue pq;
    pq.enqueue("test");
    assert(pq.isEmpty() == false);
    assert(pq.size() == 1);
    assert(pq.peek() == "test");
    std::cout << "testEnqueueSingleElement passed!" << std::endl;
}

void testEnqueueMultipleElements() {
    HeapPriorityQueue pq;
    pq.enqueue("c");
    pq.enqueue("a");
    pq.enqueue("b");
    assert(pq.isEmpty() == false);
    assert(pq.size() == 3);
    assert(pq.peek() == "a"); // "a" should be the smallest element
    std::cout << "testEnqueueMultipleElements passed!" << std::endl;
}

void testDequeueMinSingleElement() {
    HeapPriorityQueue pq;
    pq.enqueue("test");
    assert(pq.dequeueMin() == "test");
    assert(pq.isEmpty() == true);
    assert(pq.size() == 0);
    std::cout << "testDequeueMinSingleElement passed!" << std::endl;
}

void testDequeueMinMultipleElements() {
    HeapPriorityQueue pq;
    pq.enqueue("c");
    pq.enqueue("a");
    pq.enqueue("b");
    assert(pq.dequeueMin() == "a");
    assert(pq.size() == 2);
    assert(pq.peek() == "b");
    assert(pq.dequeueMin() == "b");
    assert(pq.size() == 1);
    assert(pq.peek() == "c");
    assert(pq.dequeueMin() == "c");
    assert(pq.isEmpty() == true);
    assert(pq.size() == 0);
    std::cout << "testDequeueMinMultipleElements passed!" << std::endl;
}

void testPeek() {
    HeapPriorityQueue pq;
    pq.enqueue("c");
    pq.enqueue("a");
    pq.enqueue("b");
    assert(pq.peek() == "a");
    pq.dequeueMin();
    assert(pq.peek() == "b");
    pq.dequeueMin();
    assert(pq.peek() == "c");
    std::cout << "testPeek passed!" << std::endl;
}

void testLengthenSize() {
    HeapPriorityQueue pq;
    for (int i = 0; i < 100; ++i) {
        pq.enqueue("value" + std::to_string(i));
    }
    assert(pq.size() == 100);
    assert(pq.isEmpty() == false);
    assert(pq.peek() == "value0");
    for (int i = 0; i < 100; ++i) {
        pq.dequeueMin();
    }
    assert(pq.isEmpty() == true);
    assert(pq.size() == 0);
    std::cout << "testLengthenSize passed!" << std::endl;
}

void testBubbleUp() {
    HeapPriorityQueue pq;
    pq.enqueue("d");
    pq.enqueue("c");
    pq.enqueue("b");
    pq.enqueue("a");
    assert(pq.peek() == "a");
    std::cout << "testBubbleUp passed!" << std::endl;
}

void testBubbleDown() {
    HeapPriorityQueue pq;
    pq.enqueue("a");
    pq.enqueue("b");
    pq.enqueue("c");
    pq.enqueue("d");
    assert(pq.dequeueMin() == "a");
    assert(pq.dequeueMin() == "b");
    assert(pq.dequeueMin() == "c");
    assert(pq.dequeueMin() == "d");
    std::cout << "testBubbleDown passed!" << std::endl;
}

void testStressTest() {
    HeapPriorityQueue pq;
    for (int i = 0; i < 1000; ++i) {
        pq.enqueue("value" + std::to_string(i));
    }
    for (int i = 0; i < 1000; ++i) {
        pq.dequeueMin();
    }
    assert(pq.isEmpty() == true);
    std::cout << "testStressTest passed!" << std::endl;
}

int main() {
    testInitialState();
    testEnqueueSingleElement();
    testEnqueueMultipleElements();
    testDequeueMinSingleElement();
    testDequeueMinMultipleElements();
    testPeek();
    testLengthenSize();
    testBubbleUp();
    testBubbleDown();
    testStressTest();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
