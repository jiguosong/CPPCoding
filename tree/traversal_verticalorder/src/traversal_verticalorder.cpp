/*
 * inorder_traversal.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: songjiguo
 */

#include "traversal_verticalorder.h"

#include <utility>
#include <map>
using std::map;

vector<vector<int>> verticalorder_traversal::verticalOrder(TreeNode *root)
{
	vector<vector<int>> res;
	if (!root)
		return res;

	map<int, vector<int>> map;
	queue<std::pair<int, TreeNode *>> queue;
	queue.push( { 0, root });
	while (!queue.empty()) {
		auto tmp = queue.front();
		queue.pop();
		map[tmp.first].push_back(tmp.second->val);
		if (tmp.second->left)
			queue.push( { tmp.first - 1, tmp.second->left });
		if (tmp.second->right)
			queue.push( { tmp.first + 1, tmp.second->right });
	}

	for (auto i : map)
		res.push_back(i.second);

	return res;
}

