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
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    SumOfTwoLinkedList::Node* node5 = new SumOfTwoLinkedList::Node(5, nullptr);
    SumOfTwoLinkedList::Node* node4 = new SumOfTwoLinkedList::Node(4, node5);
    SumOfTwoLinkedList::Node* node3 = new SumOfTwoLinkedList::Node(3, node4);
    SumOfTwoLinkedList::Node* node2 = new SumOfTwoLinkedList::Node(2, node3);
    SumOfTwoLinkedList::Node* node1 = new SumOfTwoLinkedList::Node(1, node2);

    std::cout << "Original list: ";
    printList(node1);

    SumOfTwoLinkedList solver;
    SumOfTwoLinkedList::Node* reversedList = solver.reverseList(node1);

    std::cout << "Reversed list: ";
    printList(reversedList);

    // Free allocated memory
    while (reversedList != nullptr) {
        SumOfTwoLinkedList::Node* temp = reversedList;
        reversedList = reversedList->next;
        delete temp;
    }

    return 0;
}
