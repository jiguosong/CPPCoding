/*
 * preorder_traversal.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: songjiguo
 */

#include "traversal_preorder.h"
#include <stack>

static void preOrder_helper(TreeNode *root, vector<int> &res)
{
	if (!root)
		return;
	res.push_back(root->val);
	preOrder_helper(root->left, res);
	preOrder_helper(root->right, res);
}

vector<int> preorder_traversal::preOrder(TreeNode *root)
{
	vector<int> res = { };
	//preOrder_helper(root, res);

	if (root == nullptr)
		return {};
	std::stack<TreeNode *> stk;
	stk.push(root);
	while (!stk.empty()) {
		TreeNode *p = stk.top();
		stk.pop();
		res.push_back(p->val);
		if (p->right)
			stk.push(p->right);
		if (p->left)
			stk.push(p->left);
	}

	return res;
}

