#include "pathSum.h"


using namespace std;



void pathSum(TreeNode* root, int s, Set<TreeNode*>& nodes) {
	if (root == NULL)return;

	if (s == root->v) {
		if (root->left == NULL && root->right == NULL) {
			nodes.add(root);
			return;
		}
	}

	/* Base Case */
	pathSum(root->right, s - root->v, nodes);
	pathSum(root->left, s - root->v, nodes);
}