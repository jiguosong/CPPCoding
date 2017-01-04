/*
 * inorder_traversal.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: songjiguo
 */

#include "traversal_sideview.h"

vector<int> sidevieworder_traversal::sideviewOrder(TreeNode *root)
{
	vector<int> res;
	if (!root)
		return res;

	queue<TreeNode *> queue;
	queue.push(root);
	while (!queue.empty()) {
		res.push_back(queue.back()->val);
		int sz = queue.size();
		for (int i = 0; i < sz; i++) {
			TreeNode *tmp = queue.front();
			queue.pop();
			if (tmp->left)
				queue.push(tmp->left);
			if (tmp->right)
				queue.push(tmp->right);
		}
	}

	return res;
}

