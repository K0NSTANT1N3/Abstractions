#include "longest_path.h"
#include "strlib.h"

int deepestChild(Node *root) {
    /* Base Case */
    if (root == NULL)return 0;
    if (root->left == NULL && root->right == NULL)return 1;

    /* Inductive Step */
    int ans = 0;
    ans = max(ans, deepestChild(root->right));
    ans = max(ans, deepestChild(root->left));
    return ++ans;
}


int getLongestPath(Node *root) {
    /* Base Case */
    if (root == NULL)return 0;
    if (root->left == NULL && root->right == NULL)return 1;

    /* Inductive Step */
    int ans = 0;
    ans = max(ans, getLongestPath(root->right));
    ans = max(ans, getLongestPath(root->left));
    ans = max(ans, deepestChild(root->left) + deepestChild(root->right) + 1);
    return ans;
}

