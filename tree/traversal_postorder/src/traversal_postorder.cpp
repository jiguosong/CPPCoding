/*
 * inorder_traversal.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: songjiguo
 */

#include "traversal_postorder.h"
#include <stack>

static void postOrder_helper(TreeNode *root, vector<int> &res)
{
	if (!root)
		return;
	postOrder_helper(root->left, res);
	postOrder_helper(root->right, res);
	res.push_back(root->val);
}

vector<int> postorder_traversal::postOrder(TreeNode *root)
{
	vector<int> res = { };
	// postOrder_helper(root, res);

	if (root == nullptr)
		return {};
	std::stack<TreeNode *> s1, s2;
	s1.push(root);

	while (!s1.empty()) {
		TreeNode *p = s1.top();
		s1.pop();
		s2.push(p);
		if (p->left)
			s1.push(p->left);
		if (p->right)
			s1.push(p->right);
	}

	while (!s2.empty()) {
		res.push_back(s2.top()->val);
		s2.pop();
	}

	return res;
}

