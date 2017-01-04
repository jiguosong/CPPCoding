/*

*/

#include "lcaBST.h"

void lcaBST::dummy() {
}

// assume p and q always valid?
TreeNode *lcaBST::lcainBST(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr || p == nullptr || q == nullptr) return nullptr;

    if (p->val > q->val) lcainBST(root, q, p);
    if (root->val >= p->val && root->val <= q->val) return root;
    if (root->val > q->val) return lcainBST(root->left, p, q);
    if (root->val < p->val) return lcainBST(root->right, p, q);
}