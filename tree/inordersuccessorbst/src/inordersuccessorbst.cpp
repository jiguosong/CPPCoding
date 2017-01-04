/*
 * inordersuccessorbst.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: songjiguo
 */

#include "inordersuccessorbst.h"

TreeNode* inordersuccessorbst::inorderSuccessor(TreeNode *root, TreeNode *p)
{
	if(!root || !p) return nullptr;
	TreeNode *res = nullptr;

	// keep tracking the last change to the left
	// only when the p is smaller, and the last one could be potential successor
	while(root) {
		if(root->val > p->val) {
			res = root;
			root = root->left;
		} else root = root->right;
	}

	return res;
}
