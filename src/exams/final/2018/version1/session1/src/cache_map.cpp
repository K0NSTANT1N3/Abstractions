#include "cache_map.h"


CacheMap::CacheMap(int size) {
    length = 0;
    cacheSize = size;
    rootKey = rootIndex = nullptr;
}

void CacheMap::put(int key, int value) {
    if (rootKey == nullptr) {
        rootKey = new Node(key, value, 0);
        rootIndex = new Node(key, value, 0);
        length++;
        lastIndex++;
        return;
    }
    if (cacheSize <= length && get(key) == -1) {
        int k = removeMin(rootIndex);
        remove(k);
    }

    Node *tmp = rootKey;
    Node *parent = nullptr;
    bool isKey = false;
    int index;

    while (tmp != nullptr) {
        parent = tmp;
        if (tmp->key > key) {
            tmp = tmp->left;
        } else if (tmp->key < key) {
            tmp = tmp->right;
        } else {
            tmp->val = value;
            if (tmp->deleted) {
                tmp->deleted = false;
                tmp->index = ++lastIndex;
                length++;
            }
            index = tmp->index;
            isKey = true;
            break;
        }
    }

    if (!isKey){
        length++;
        lastIndex++;
        if (parent != nullptr) {
            if (parent->key >= key) {
                parent->left = new Node(key, value, lastIndex);
            } else {
                parent->right = new Node(key, value, lastIndex);
            }
        }
        index = lastIndex;
    }

    tmp = rootIndex;
    parent = nullptr;

    while(tmp != nullptr){
        parent = tmp;
        if(tmp->index > index){
            tmp = tmp->left;
        }
        else if(tmp->index < index){
            tmp = tmp->right;
        }
        else{
            tmp->val = value;
                tmp->deleted = false;
            return;
        }
    }

    if(parent != nullptr){
        if(parent->index > index){
            parent->left = new Node(key, value, index);
        }
        else{
            parent->right = new Node(key, value, index);
        }
    }
}


int CacheMap::get(int key) {
    Node *cur = getKeyNode(rootKey, key);
    if (cur == nullptr || cur->deleted)return -1;
    return cur->val;
}

int CacheMap::size() {
    return length;
}

void CacheMap::remove(int key) {
    Node *cur = getKeyNode(rootKey, key);
    if (cur == nullptr || cur->deleted)return;

    length--;
    cur->deleted = true;
    int index = cur->index;

    Node *nextCur = getIndexNode(rootIndex, index);
    if (nextCur == nullptr || nextCur->deleted)return;
    nextCur->deleted = true;
}

bool CacheMap::containsKey(int key) {
    Node *cur = getKeyNode(rootKey, key);
    if (cur == nullptr || cur->deleted)return false;
    return true;
}

/** private */

int CacheMap::removeMin(CacheMap::Node *&root) {
    if (root == nullptr)return -1;
    if (root->left == nullptr) {
        Node *right = root->right;
        int k = root->key;
        delete root;
        root = right;
        return k;
    }

    return removeMin(root->left);
}

CacheMap::Node *CacheMap::getKeyNode(CacheMap::Node *root, int key) {
    if (root == nullptr)return nullptr;

    if (root->key == key)return root;

    if (root->key > key)return getKeyNode(root->left, key);
    return getKeyNode(root->right, key);
}

CacheMap::Node *CacheMap::getIndexNode(CacheMap::Node *root, int index) {
    if (root == nullptr)return nullptr;

    if (root->index == index)return root;

    if (root->index > index)return getIndexNode(root->left, index);
    return getIndexNode(root->right, index);
}



//
//void CacheMap::put(int key, int val, CacheMap::Node *&node)
//{
//
//}