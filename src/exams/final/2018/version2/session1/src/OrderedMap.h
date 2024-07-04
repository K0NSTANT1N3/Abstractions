//
// Created by konstantine on 7/4/24.
//

#ifndef ABSTRACTIONS_ORDEREDMAP_H
#define ABSTRACTIONS_ORDEREDMAP_H


class OrderedMap {
public:
    struct Pair {
        int key;
        int value;

        Pair(int k, int v) {
            key = k;
            value = v;
        }

        Pair() {
            key = value = -1;
        }
    };

    struct Node {
        Pair pair;
        Node *left;
        Node *right;
        int index;

        Node() {
            pair.key = pair.value = index = -1;
            left = right = nullptr;
        }

        Node(Pair p, int i) : pair(p), index(i), left(nullptr), right(nullptr) {}
    };

    OrderedMap();

    void put(int key, int value);

    int get(int key);

    int size();

    void remove(int key);

    bool containsKey(int key);

    void resetIterator();

    bool hasNext();

    int next();

    Node *leftMostParent(Node *head);

    void swapNode(Node *node1, Node *node2);

    void correctPosition(Node *curr);

private:
    Node *root;
    Pair *cont;
    int logLen;
    int allocLen;
    int iterator;
    int lastElemIndex;


};


#endif //ABSTRACTIONS_ORDEREDMAP_H
