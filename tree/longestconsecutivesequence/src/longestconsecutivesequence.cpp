/*
 Given a binary tree, find the length of the longest consecutive sequence
 path. The path refers to any sequence of nodes from some starting node to
 any node in the tree along the parent-child connections.

 The longest consecutive path need to be from parent to child
 (cannot be the reverse).

 For example,

 1
 3
 / \
   2   4
 5

 Longest consecutive sequence path is 3-4-5, so return 3.

 2
 3
 /
 2
 /
 1

 Longest consecutive sequence path is 2-3,not3-2-1, so return 2.

 */

#include "longestconsecutivesequence.h"

void longestconsecutivesequence::dummy()
{
}

static void helper(TreeNode *root, int level, int &res)
{
	if (root == nullptr)
		return;
	res = std::max(res, level);

	if (root->left) {
		if (root->val == root->left->val - 1)
			helper(root->left, level + 1, res);
		else
			helper(root->left, 1, res);
	}

	if (root->right) {
		if (root->val == root->right->val - 1)
			helper(root->right, level + 1, res);
		else
			helper(root->right, 1, res);
	}

}

int longestconsecutivesequence::longestConsecutive(TreeNode* root)
{
	int res = 0;
	helper(root, 1, res);
	return res;
}

