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

