/*

*/

#include "lcaBT.h"

void lcaBT::dummy() {
}

TreeNode *lcaBT::lcainBT(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr || p == root || q == root) return root;

    TreeNode *left = lcainBT(root->left, p, q);
    TreeNode *right = lcainBT(root->right, p, q);

    if (left && right) return root;
    return left ? left : right;
}