/* Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

If you notice carefully in the flattened tree,
each node's right child points to the next node of a pre-order travel
*/
#include "flattenBTtolinkedlist.h"

void flattenBTtolinkedlist::dummy() 
{
}

void flattenBTtolinkedlist::flattendBTlist(TreeNode *root)
{
	if(root == nullptr) return;

	flattendBTlist(root->left);
	flattendBTlist(root->right);

	TreeNode *tmp = root->right;
	root->right = root->left;
	root->left = nullptr;

	TreeNode *p = root;
	while(p->right) p = p->right;
	p->right = tmp;
}
