/*




 */

#include "deletenodeinBST.h"

void deletenodeinBST::dummy() {
}

TreeNode *deletenodeinBST::deleteNode(TreeNode *root, int key) {
    if (root == nullptr)
        return root;
    if (root->val < key)
        root->right = deleteNode(root->right, key);
    else if (root->val > key)
        root->left = deleteNode(root->left, key);
    else {
        if (root->left == nullptr || root->right == nullptr) {
            root = (root->left == nullptr) ? root->right : root->left;
        } else {
            TreeNode *q = root->right;
            while (q->left) q = q->left;
            root->val = q->val;
            root->right = deleteNode(root->right, q->val);
        }
    }

    return root;

}
