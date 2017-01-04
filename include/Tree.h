/*
 * Tree.h
 *
 *  Created on: Nov 9, 2016
 *      Author: songjiguo
 */

#ifndef TREE_TREE_H_
#define TREE_TREE_H_

#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <random>
#include <algorithm>
#include <memory>
#include <iostream>
#include <iomanip>

using std::cout;
using std::string;
using std::vector;
using std::queue;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    };

    TreeNode() :
            val(0), left(nullptr), right(nullptr) {
    };
};

static TreeNode *generateTree_helper(vector<int> nums, int left, int right) {
    if (left > right)
        return nullptr;

    int mid = left + (right - left) / 2;

    //std::unique_ptr<TreeNode> t(new TreeNode(nums[mid]));
    //TreeNode *root = t.get();
    TreeNode *root = new TreeNode(nums[mid]);

    root->left = generateTree_helper(nums, left, mid - 1);
    root->right = generateTree_helper(nums, mid + 1, right);

    return root;
}

static void getUniqueArray(const unsigned int size, const int lower_bound,
                           const int upper_bound, vector<int> &init_array, bool sorted) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(lower_bound, upper_bound);

    std::set<int> myset;
    while (myset.size() < size) {
        auto e = dist(gen);
        assert(e >= lower_bound && e <= upper_bound);
        const bool is_in = myset.find(e) != myset.end();
        if (is_in == false) {
            myset.insert(e);
            init_array.push_back(e);
        }
    }

    if (sorted == true)
        std::sort(init_array.begin(), init_array.end());

}

static TreeNode *randomBST(const unsigned int size, const int lower_bound,
                           const int upper_bound) {
    assert(size != 0);
    unsigned int range = upper_bound - lower_bound + 1;
    assert(range > 0 && range >= size);

    vector<int> init_array;
    bool sorted = true;
    getUniqueArray(size, lower_bound, upper_bound, init_array, sorted);
    return generateTree_helper(init_array, 0, init_array.size() - 1);
}

static TreeNode *randomBT(const unsigned int size, const int lower_bound,
                          const int upper_bound) {
    assert(size != 0);
    unsigned int range = upper_bound - lower_bound + 1;
    assert(range > 0 && range >= size);

    vector<int> init_array;
    bool sorted = false;
    getUniqueArray(size, lower_bound, upper_bound, init_array, sorted);
    return generateTree_helper(init_array, 0, init_array.size() - 1);
}

// Pretty Print

#define placeholder (1<<31)

static void getLine(const TreeNode *root, int depth, vector<int> &vals) {
    if (depth <= 0 && root != nullptr) {
        vals.push_back(root->val);
        return;
    }
    if (root->left != nullptr)
        getLine(root->left, depth - 1, vals);
    else if (depth - 1 <= 0)
        vals.push_back(placeholder);
    if (root->right != nullptr)
        getLine(root->right, depth - 1, vals);
    else if (depth - 1 <= 0)
        vals.push_back(placeholder);
}

static void printRow(const TreeNode *p, const int height, int depth) {
    vector<int> vec;
    getLine(p, depth, vec);
    std::cout << std::setw((height - depth) * 2); // scale setw with depth
    bool toggle = true; // start with left
    if (vec.size() > 1) {
        for (int v : vec) {
            if (v != placeholder) {
                if (toggle)
                    cout << "/" << "   ";
                else
                    cout << "\\" << "   ";
            }
            toggle = !toggle;
        }
        std::cout << std::endl;
        std::cout << std::setw((height - depth) * 2);
    }
    for (int v : vec) {
        if (v != placeholder)
            cout << v << "   ";
    }
    std::cout << std::endl;
}

static int getHeight(const TreeNode *root) {
    if (root == nullptr)
        return 0;
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    return std::max(left, right) + 1;
}

static void postorderPrettyPrint(TreeNode *p) {
    int height = getHeight(p) * 2;
    for (int i = 0; i < height; i++) {
        printRow(p, height, i);
    }
}

static void postorderPrint(TreeNode *p, int indent = 0) {
    if (p != NULL) {
        if (p->right) {
            postorderPrint(p->right, indent + 4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->right)
            std::cout << " /\n" << std::setw(indent) << ' ';
        std::cout << p->val << "\n ";
        if (p->left) {
            std::cout << std::setw(indent) << ' ' << " \\\n";
            postorderPrint(p->left, indent + 4);
        }
    }
}

// http://articles.leetcode.com/how-to-pretty-print-binary-tree/
#include <fstream>
#include <iostream>
#include <deque>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

// Find the maximum height of the binary tree
static int maxHeight(TreeNode *p) {
    if (!p)
        return 0;
    int leftHeight = maxHeight(p->left);
    int rightHeight = maxHeight(p->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// Convert an integer value to string
static string intToString(int val) {
    ostringstream ss;
    ss << val;
    return ss.str();
}

// Print the arm branches (eg, /    \ ) on a line
static void printBranches(int branchLen, int nodeSpaceLen, int startLen,
                          int nodesInThisLevel, const deque<TreeNode *> &nodesQueue, ostream &out) {
    deque<TreeNode *>::const_iterator iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel / 2; i++) {
        out << ((i == 0) ? setw(startLen - 1) : setw(nodeSpaceLen - 2)) << ""
        << ((*iter++) ? "/" : " ");
        out << setw(2 * branchLen + 2) << "" << ((*iter++) ? "\\" : " ");
    }
    out << endl;
}

// Print the branches and node (eg, ___10___ )
static void printNodes(int branchLen, int nodeSpaceLen, int startLen,
                       int nodesInThisLevel, const deque<TreeNode *> &nodesQueue, ostream &out) {
    deque<TreeNode *>::const_iterator iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
        out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << ""
        << ((*iter && (*iter)->left) ? setfill('_') : setfill(' '));
        out << setw(branchLen + 2)
        << ((*iter) ? intToString((*iter)->val) : "");
        out << ((*iter && (*iter)->right) ? setfill('_') : setfill(' '))
        << setw(branchLen) << "" << setfill(' ');
    }
    out << endl;
}

// Print the leaves only (just for the bottom row)
static void printLeaves(int indentSpace, int level, int nodesInThisLevel,
                        const deque<TreeNode *> &nodesQueue, ostream &out) {
    deque<TreeNode *>::const_iterator iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
        out << ((i == 0) ? setw(indentSpace + 2) : setw(2 * level + 2))
        << ((*iter) ? intToString((*iter)->val) : "");
    }
    out << endl;
}

// Pretty formatting of a binary tree to the output stream
// @ param
// level  Control how wide you want the tree to sparse (eg, level 1 has the minimum space between nodes, while level 2 has a larger space between nodes)
// indentSpace  Change this to add some indent space to the left (eg, indentSpace of 0 means the lowest level of the left node will stick to the left margin)

// how to use example: printPretty(root, 1, 0, cout);
static void printPretty(TreeNode *root, int level, int indentSpace,
                        ostream &out) {
    int h = maxHeight(root);
    int nodesInThisLevel = 1;

    int branchLen = 2 * ((int) pow(2.0, h) - 1) - (3 - level) * (int) pow(2.0,
                                                                          h -
                                                                          1);  // eq of the length of branch for each node of each level
    int nodeSpaceLen = 2 + (level + 1) * (int) pow(2.0,
                                                   h); // distance between left neighbor node's right arm and right neighbor node's left arm
    int startLen = branchLen + (3 - level) +
                   indentSpace; // starting space to the first node to print of each level (for the left most node of each level only)

    deque<TreeNode *> nodesQueue;
    nodesQueue.push_back(root);
    for (int r = 1; r < h; r++) {
        printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel,
                      nodesQueue, out);
        branchLen = branchLen / 2 - 1;
        nodeSpaceLen = nodeSpaceLen / 2 + 1;
        startLen = branchLen + (3 - level) + indentSpace;
        printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel,
                   nodesQueue, out);

        for (int i = 0; i < nodesInThisLevel; i++) {
            TreeNode *currNode = nodesQueue.front();
            nodesQueue.pop_front();
            if (currNode) {
                nodesQueue.push_back(currNode->left);
                nodesQueue.push_back(currNode->right);
            } else {
                nodesQueue.push_back(NULL);
                nodesQueue.push_back(NULL);
            }
        }
        nodesInThisLevel *= 2;
    }
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel,
                  nodesQueue, out);
    printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);

    out << "\n";
}

#endif /* TREE_TREE_H_ */

