//
// Created by konstantine on 6/15/24.
//

#include "SumOfTwoLinkedList.h"



void SumOfTwoLinkedList::reverseHelper(SumOfTwoLinkedList::Node *root, SumOfTwoLinkedList::Node *tail,
                                       SumOfTwoLinkedList::Node *&ans) {
    if (tail == nullptr) {
        ans = root;
        return;
    }
    if (tail->next == nullptr) {
        ans = tail;
        ans->next = root;
        root->next = nullptr;
        return;
    }

    reverseHelper(root->next, tail->next, ans);
    root->next->next = root;
    root->next = nullptr;
}

SumOfTwoLinkedList::Node *SumOfTwoLinkedList::reverseList(SumOfTwoLinkedList::Node *root) {
    Node *ans;
    reverseHelper(root, root->next, ans);
    return ans;
}


SumOfTwoLinkedList::Node *
SumOfTwoLinkedList::sumOfTwoList(SumOfTwoLinkedList::Node *one, SumOfTwoLinkedList::Node *two) {
    Node *first = reverseList(one);
    Node *second = reverseList(two);

    Node *head = new Node;
    Node *tail = head;
    int carry = 0;

    while (first != nullptr || second != nullptr || carry > 0) {
        int sum = carry;
        if (first != nullptr) {
            sum += first->val;
            first = first->next;
        }
        if (second != nullptr) {
            sum += second->val;
            second = second->next;
        }

        carry = sum / 10;
        int newVal = sum % 10;
        tail->next = new Node(newVal, nullptr);
        tail = tail->next;
    }
    Node* realHead = head->next;
    delete head;

    tail = reverseList(realHead);

    return tail;
}

