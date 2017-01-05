#ifndef bstiterator_H_
#define bstiterator_H_

#include <vector>
#include <string>
#include <stack>
#include "Tree.h"
using std::vector;
using std::string;

class bstiterator {
public:
    bstiterator(TreeNode *root) {
        TreeNode *p = root;
        while(p) {
            stk.push(p);
            p = p->left;
        }
    }

    bool hasNext() {
        return !stk.empty();
    }

    int next() {
        TreeNode *p = stk.top();
        stk.pop();
        int res = p->val;
        if(p->right) {
            p = p->right;
            while(p) {
                stk.push(p);
                p = p->left;
            }
        }
        return res;
    }

private:
	std::stack<TreeNode *> stk;
};

#endif
