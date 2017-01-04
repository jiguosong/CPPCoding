/*

*/

#include "traversal_levelorder.h"
#include "../Tree.h"

vector<vector<int>> levelorder_traversal::levelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if(!root) return res;

    queue<TreeNode *> q;
    q.push(root);

    while(!q.empty()) {
        int sz = q.size();
        vector<int> tmp;
        for (int i = 0; i < sz; i++) {
            TreeNode *p = q.front();
            q.pop();
            tmp.push_back(p->val);
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }

        res.push_back(tmp);
    }

    return res;
}


