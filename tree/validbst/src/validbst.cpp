/*
 * validbst.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: songjiguo
 */

#include "validbst.h"
#include <stack>


static bool isValidBST_helper(TreeNode *root, long min, long max)
{
	if (!root)
		return true;

	if (root->val <= min || root->val >= max)
		return false;

	return isValidBST_helper(root->left, min, root->val) && isValidBST_helper(
			root->right, root->val, max);

}

bool validbst::isValidBST(TreeNode *root)
{
	//return isValidBST_helper(root, LONG_MIN, LONG_MAX);

	if (root == nullptr)
		return true;
	std::stack<TreeNode *> stk;
	TreeNode *current = root;
	TreeNode *prev = nullptr;
	while (!stk.empty() || current) {
		if (current) {
			stk.push(current);
			current = current->left;
		} else {
			current = stk.top();
			stk.pop();
			if (prev && current->val < prev->val)
				return false;
			prev = current;
			current = current->right;
		}
	}

	return true;
}
