/*
 * findvalueinbst.cpp
 *
 *  Created on: Nov 21, 2016
 *      Author: songjiguo
 */

#include "findvalueinbst.h"


/*bool findvalInBST::findvalueinbst(TreeNode *root, int val)
{
	if(!root) return false;
	if(root->val == val) return true;
	if(root->val > val) return findvalueinbst(root->left, val);
	else return findvalueinbst(root->right, val);
}*/


bool findvalInBST::findvalueinbst(TreeNode *root, int val)
{
	if(!root) return false;

	TreeNode *p = root;
	while(p) {
		if(p->val == val) return true;
		else if (p->val < val) p = p->right;
		else p = p->left;
	}

	return false;
}
