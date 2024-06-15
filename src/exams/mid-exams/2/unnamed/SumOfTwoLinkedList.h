//
// Created by konstantine on 6/15/24.
//

#ifndef ABSTRACTIONS_SUMOFTWOLINKEDLIST_H
#define ABSTRACTIONS_SUMOFTWOLINKEDLIST_H


class SumOfTwoLinkedList {
public:
    struct Node {
        int val;
        Node *next;

        Node() {
            val = 0;
            next = nullptr;
        }

        Node(int val, Node *next) {
            this->val = val;
            this->next = next;
        }
    };

    Node* sumOfTwoList(Node* one, Node* two);

private:
    void reverseHelper(Node* root, Node* tail, Node*& ans);
    Node* reverseList(Node* root);
};


#endif //ABSTRACTIONS_SUMOFTWOLINKEDLIST_H
