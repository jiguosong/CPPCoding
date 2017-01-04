/*
 * pathsum.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: songjiguo
 */

#include "pathsum.h"

/*Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.*/

bool pathsum::hasPathSum(TreeNode *root, int sum)
{
	if(!root) return false;

	if(root->val == sum && !root->left && !root->right) return true;

	return hasPathSum(root->left, sum - root->val) ||
			hasPathSum(root->right, sum - root->val);
}


static void helper(TreeNode *root, int sum,  vector<int> &tmp, vector<vector<int>> &res)
{
	if(!root->left && !root->right && root->val == sum) {
		res.push_back(tmp);
		return;
	}

	if(root->left) {
		tmp.push_back(root->left->val);
		helper(root->left, sum-root->val, tmp, res);
		tmp.pop_back();
	}

	if(root->right) {
		tmp.push_back(root->right->val);
		helper(root->right, sum-root->val, tmp, res);
		tmp.pop_back();
	}
}


/*Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return

[
   [5,4,11,2],
   [5,8,4,5]
]*/
vector<vector<int> > pathsum::allpathSum(TreeNode *root, int sum)
{
	vector<vector<int>> res;
	if(!root) return res;

	vector<int> tmp;
	tmp.push_back(root->val);
	helper(root, sum, tmp, res);

	return res;
}


