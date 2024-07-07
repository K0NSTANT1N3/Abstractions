#include <iostream>
#include "simpio.h"
#include "error.h"
#include <limits.h>

using namespace std;


class CacheMap {
public:
    struct Node {
        int key;
        int val;

        Node *left;
        Node *right;

        int index;
        bool deleted;

        Node() {
            key = val = index = -1;
            left = right = nullptr;
            deleted = false;
        }

        Node(int key, int val, int index) {
            this->key = key;
            this->val = val;
            this->index = index;

            left = right = nullptr;
            deleted = false;
        }

        bool operator<(const Node &other) const {
            return key < other.key;
        }

        bool operator==(const Node &other) const {
            return key == other.key;
        }
    };

    CacheMap(int cacheSize);

    void put(int key, int value);

    int get(int key);

    int size();

    void remove(int key);

    bool containsKey(int key);

private:
//    int *keys;
//    int *values;

    int length;
    int cacheSize;
    int lastIndex;

    Node *rootKey;
    Node *rootIndex;

    int removeMin(Node *&root);
    Node* getKeyNode(Node *root, int key);
    Node* getIndexNode(Node *root, int index);

};