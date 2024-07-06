#include "SumOfLeftLeaves.h"

#include "iostream"

bool isLeaf(TreeNode * node) {
    return node ->left == NULL && node ->right == NULL;
}

void leftLeavesSum(TreeNode * root, int &sum) {
   if(root == NULL) return;
   if(isLeaf(root)) {
       sum += root ->v;
       return;
   }
    if(root->left != NULL){
        leftLeavesSum(root ->left, sum);
    }

    if(root->right != NULL && !isLeaf(root ->right)){
        leftLeavesSum(root ->right, sum);
    }
}

int sumOfLeftLeaves(TreeNode * root) {
    int sum1 = 0;
    int sum2 = 0;
    if(root == NULL || isLeaf(root)) return 0;
    leftLeavesSum(root->left, sum1);

    if(!isLeaf(root ->right)){
        leftLeavesSum(root->right, sum2);
    }

    cout << "answer is "  << sum1 + sum2 << endl;

    return sum1 + sum2;
}

