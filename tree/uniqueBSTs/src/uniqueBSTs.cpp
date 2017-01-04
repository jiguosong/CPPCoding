/*
 Given n, generate all structurally unique BST's (binary search trees) that store
 values 1...n.

 For example,
 Given n = 3, your program should return all 5 unique BST's shown below.

 1         3     3      2      1
 \       /     /      / \      \
     3     2     1      1   3      2
 /     /       \                 \
   2     1         2                 3



 confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

 OJ's Binary Tree Serialization:

 The serialization of a binary tree follows a level order traversal, where '#' signifies a
 path terminator where no node exists below.

 Here's an example:

 1
 / \
 2   3
 /
 4
 5

 The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
 */

#include "uniqueBSTs.h"

void uniqueBSTs::dummy()
{
}

#include <iostream>
using namespace std;

static vector<TreeNode *> *helper(int low, int high)
{
	vector<TreeNode *> *res = new vector<TreeNode *>();
	if (low > high)
		res->push_back(nullptr);
	else {
		for (int i = low; i <= high; ++i) {
			vector<TreeNode *> *left = helper(low, i - 1);
			vector<TreeNode *> *right = helper(i + 1, high);
			for (int j = 0; j < left->size(); ++j) {
				for (int k = 0; k < right->size(); ++k) {
					TreeNode *node = new TreeNode(i);
					node->left = (*left)[j];
					node->right = (*right)[k];
					res->push_back(node);
				}
			}
		}
	}

	return res;
}

vector<TreeNode *> uniqueBSTs::generateTrees(int n)
{
	if (n == 0)
		return {};
	vector<TreeNode *> *res = helper(1, n);

	return *res;
}
