/*
 * buildtreefrompreordernorder.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: songjiguo
 */

/*
Given a list of nodes from a binary tree given in preorder and inorder fashion, can you reconstruct the tree without ambiguity?

You can use this tree as an example:

  int preorder[] = {7, 10, 4, 3, 1, 2, 8, 11};
  int inorder[] = {4, 10, 3, 1, 7, 11, 8, 2};

Note that this is not a binary search tree: the nodes are not in sorted order in the tree.

Note You may assume that duplicates do not exist in the tree.
*/

#include "buildtreefrompreordernorder.h"

static TreeNode *buildTree_helper(vector<int> &preorder, int pLeft, int pRight,
								   vector<int> &inorder, int iLeft, int iRight)
{
	if(pLeft > pRight || iLeft > iRight) return nullptr;
	int i = 0;
	for(i = iLeft; i <= iRight; ++i) {
		if(preorder[pLeft] == inorder[i]) break;
	}

	TreeNode *root = new TreeNode(preorder[pLeft]);
	root->left = buildTree_helper(preorder, pLeft+1, pLeft + i - iLeft,
								    inorder, iLeft, i-1);
	root->right = buildTree_helper(preorder, pLeft + i - iLeft + 1, pRight,
								    inorder, i+1, iRight);

	return root;
}


TreeNode * buildtreefrompreordernorder::buildTree(vector<int> &preorder, vector<int> &inorder)
{
	TreeNode *root;

	root = buildTree_helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);

	return root;
}
