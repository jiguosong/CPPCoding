/*
 * inorder_traversal.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: songjiguo
 */

#include "traversal_inorder.h"
#include <stack>

static void inOrder_helper(TreeNode *root, vector<int> &res)
{
	if (!root)
		return;
	inOrder_helper(root->left, res);
	res.push_back(root->val);
	inOrder_helper(root->right, res);
}

vector<int> inorder_traversal::inOrder(TreeNode *root)
{
	vector<int> res = { };
	//inOrder_helper(root, res);

	std::stack<TreeNode *> stk;
	TreeNode *p = root;
	while (!stk.empty() || p != nullptr) {
		if(p != nullptr) {
			stk.push(p);
			p = p->left;
		} else {
			p = stk.top();
			stk.pop();
			res.push_back(p->val);
			p = p->right;
		}
	}

	return res;
}

