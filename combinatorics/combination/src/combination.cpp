/*
 * combination.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: songjiguo
 */

#include "combination.h"
#include <string>

/*Given two integers n and k, return all possible
 combinations of k numbers out of 1 ... n.*/

static void combine_helper(int n, int k, int level, vector<int> &tmp,
                           vector<vector<int>> &res);

vector<vector<int>> combination::combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> tmp;

    if (n == 0 || n < k)
        return res;

    combine_helper(n, k, 1, tmp, res);

    return res;
}

static void combine_helper(int n, int k, int level, vector<int> &tmp,
                           vector<vector<int>> &res) {
    if (tmp.size() == k) {
        res.push_back(tmp);
        return;
    }

    for (int i = level; i <= n; i++) {
        tmp.push_back(i);
        combine_helper(n, k, i + 1, tmp, res);
        tmp.pop_back();
    }
}
