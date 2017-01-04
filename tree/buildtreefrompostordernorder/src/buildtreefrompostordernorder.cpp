/*
 Given inorder and postorder traversal of a tree, construct the binary tree.

 Note:
 You may assume that duplicates do not exist in the tree. */

#include "buildtreefrompostordernorder.h"

void buildtreefrompostordernorder::dummy() {
}

static TreeNode *helper(vector<int> &postorder, int pLeft, int pRight,
                        vector<int> &inorder, int iLeft, int iRight) {
    if (pLeft > pRight || iLeft > iRight)
        return nullptr;
    TreeNode *root = new TreeNode(postorder[pRight]);
    int i = 0;
    for (i = iLeft; i < iRight; ++i) {
        if (postorder[pRight] == inorder[i])
            break;
    }

    root->left = helper(postorder, pLeft, pLeft + i - iLeft - 1, inorder, iLeft,
                        i - 1);
    root->right = helper(postorder, pLeft + i - iLeft, pRight - 1, inorder,
                         i + 1, iRight);
    return root;
}

TreeNode *buildtreefrompostordernorder::buildTree(vector<int> &postorder,
                                                  vector<int> &inorder) {
    return helper(postorder, 0, postorder.size() - 1, inorder, 0,
                  inorder.size() - 1);
}
