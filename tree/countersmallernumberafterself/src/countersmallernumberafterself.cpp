/*
 * countersmallernumberafterself.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: songjiguo
 */

/*
 You are given an integer array nums and you have to return a new counts array.
 The counts array has the property where counts[i] is the number of smaller
 elements to the right of nums[i].

 Example:

 Given nums = [5, 2, 6, 1]

 To the right of 5 there are 2 smaller elements (2 and 1).
 To the right of 2 there is only 1 smaller element (1).
 To the right of 6 there is 1 smaller element (1).
 To the right of 1 there is 0 smaller element.

 Return the array [2, 1, 1, 0].
 */

#include "countersmallernumberafterself.h"

struct compareNode {
    int val, smaller;
    compareNode *left, *right;

    compareNode(int v, int s) : val(v), smaller(s), left(nullptr), right(nullptr) { }
};

static int insertNode(compareNode *&root, int val) {
    if (!root) {
        root = new compareNode(val, 0);
        return 0;
    }

    if (root->val > val) {
        root->smaller++;
        return insertNode(root->left, val);
    } else {
        return insertNode(root->right, val) + root->smaller + (root->val < val ? 1 : 0);
    }
}

vector<int> countersmallernumberafterself::countSmaller(vector<int> &nums) {
    vector<int> res(nums.size());

    compareNode *root = nullptr;
    for (int i = nums.size() - 1; i >= 0; i--) {
        res[i] = insertNode(root, nums[i]);
    }

    return res;
}

