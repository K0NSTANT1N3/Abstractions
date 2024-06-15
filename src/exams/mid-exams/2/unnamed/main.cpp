#include <iostream>
#include "SumOfTwoLinkedList.h"

// Function to print the linked list
void printList(SumOfTwoLinkedList::Node* node) {
    while (node != nullptr) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    // Creating first linked list: 3 -> 4 -> 2 (represents number 243)
    SumOfTwoLinkedList::Node* firstNode6 = new SumOfTwoLinkedList::Node(3, nullptr);
    SumOfTwoLinkedList::Node* firstNode5 = new SumOfTwoLinkedList::Node(2, firstNode6);
    SumOfTwoLinkedList::Node* firstNode4 = new SumOfTwoLinkedList::Node(1, firstNode5);
    SumOfTwoLinkedList::Node* firstNode3 = new SumOfTwoLinkedList::Node(9, firstNode4);
    SumOfTwoLinkedList::Node* firstNode2 = new SumOfTwoLinkedList::Node(9, firstNode3);
    SumOfTwoLinkedList::Node* firstNode1 = new SumOfTwoLinkedList::Node(9, firstNode2);

    // Creating second linked list: 9870
    SumOfTwoLinkedList::Node* secondNode4 = new SumOfTwoLinkedList::Node(0, nullptr);
    SumOfTwoLinkedList::Node* secondNode3 = new SumOfTwoLinkedList::Node(7, secondNode4);
    SumOfTwoLinkedList::Node* secondNode2 = new SumOfTwoLinkedList::Node(8, secondNode3);
    SumOfTwoLinkedList::Node* secondNode1 = new SumOfTwoLinkedList::Node(9, secondNode2);

    std::cout << "First list: ";
    printList(firstNode1);

    std::cout << "Second list: ";
    printList(secondNode1);

    SumOfTwoLinkedList solver;
    SumOfTwoLinkedList::Node* sumList = solver.sumOfTwoList(firstNode1, secondNode1);

    std::cout << "Summed list: ";
    printList(sumList);

    // Free allocated memory
    while (sumList != nullptr) {
        SumOfTwoLinkedList::Node* temp = sumList;
        sumList = sumList->next;
        delete temp;
    }

    return 0;
}
