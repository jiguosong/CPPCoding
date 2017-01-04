/*

*/

#include "searchRangeBST.h"
#include <climits>

void searchRangeBST::dummy() {
}

static void helper(TreeNode *root, int key, pair<int, int> &res) {

    if(root == nullptr) return;
    if(root->val < key) {
        res.first = root->val;
        helper(root->right, key, res);
    } else if(root->val >= key) {    // if equals, find the closet lower range
        res.second = root->val;
        helper(root->left, key, res);
    }
//    } else {
//        res.first = root->val;
//        res.second = root->val;
//    }
}

pair<int, int> searchRangeBST::searchRangeinBST(TreeNode *root, int key) {
    pair<int, int> res{INT_MIN, INT_MAX};
    helper(root, key, res);
    return res;
};
