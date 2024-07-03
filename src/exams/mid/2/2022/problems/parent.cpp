#include "parent.h"
#include "strlib.h"

bool isChild(TreeNode *root, TreeNode *one){
    /* Inductive Step */
    if(root == NULL)return false;
    if(root == one)return true;

    return isChild(root->left, one) || isChild(root->right, one);
}

TreeNode *getParent(TreeNode *root, TreeNode *one, TreeNode *two) {
    if(root == NULL)return NULL;
    if(root == one || root == two)return root;

    bool firstOnLeft = isChild(root->left, one);
    bool secondOnLeft = isChild(root->left, two);

    if(firstOnLeft && secondOnLeft){
        return getParent(root->left, one, two);
    }
    if(!firstOnLeft && !secondOnLeft){
        return getParent(root->right, one, two);
    }
    return root;
}
