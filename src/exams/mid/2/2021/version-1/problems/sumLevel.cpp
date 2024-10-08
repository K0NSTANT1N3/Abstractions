#include "sumLevel.h"

int sumLevel(nodeT * root, int lvl) {
    if(root == NULL)return 0;
    if(lvl == 0)return root->v;

    return sumLevel(root->left, lvl - 1) + sumLevel(root->right, lvl - 1);
}

