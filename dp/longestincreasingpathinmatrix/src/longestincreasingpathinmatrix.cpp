/*
 Given an integer matrix, find the length of the longest increasing path.

 From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

 Example 1:

 nums = [
 [9,9,4],
 [6,6,8],
 [2,1,1]
 ]

 Return 4
 The longest increasing path is [1, 2, 6, 9].

 Example 2:

 nums = [
 [3,4,5],
 [3,2,6],
 [2,2,1]
 ]

 Return 4
 The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
 */

#include "longestincreasingpathinmatrix.h"
#include <algorithm>
#include <iostream>

void longestincreasingpathinmatrix::dummy() {
}

static int helper(vector<vector<int>> &matrix, int i, int j,
                  vector<vector<int>> &dp) {
    if (dp[i][j])
        return dp[i][j];
    int mx = 1, m = matrix.size(), n = matrix[0].size();
    int x, y;

    x = i - 1;
    y = j;
    if (x >= 0 && x < m && y >= 0 && y < n && matrix[i][j] < matrix[x][y]) {
        mx = std::max(mx, 1 + helper(matrix, x, y, dp));
    }
    x = i + 1;
    y = j;
    if (x >= 0 && x < m && y >= 0 && y < n && matrix[i][j] < matrix[x][y]) {
        mx = std::max(mx, 1 + helper(matrix, x, y, dp));
    }
    x = i;
    y = j - 1;
    if (x >= 0 && x < m && y >= 0 && y < n && matrix[i][j] < matrix[x][y]) {
        mx = std::max(mx, 1 + helper(matrix, x, y, dp));
    }
    x = i;
    y = j + 1;
    if (x >= 0 && x < m && y >= 0 && y < n && matrix[i][j] < matrix[x][y]) {
        mx = std::max(mx, 1 + helper(matrix, x, y, dp));
    }

    dp[i][j] = mx;
    return mx;
}

int longestincreasingpathinmatrix::longestincreasingpath(
        vector<vector<int>> &matrix) {
    int res = 0;
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            res = std::max(res, helper(matrix, i, j, dp));
        }
    }
    return res;
}

