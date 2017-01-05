/*
Problem statement: Consider a row of n coins of values v1 . . . vn, where n is even. We play a game against an opponent by alternating turns. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin. Determine the maximum possible amount of money we can definitely win if we move first.

Note: The opponent is as clever as the user.

Let us understand the problem with few examples:

    1. 5, 3, 7, 10 : The user collects maximum value as 15(10 + 5)

    2. 8, 15, 3, 7 : The user collects maximum value as 22(7 + 15)
*/

#include "pickcoinmaxgain.h"

void pickcoinmaxgain::dummy() {
}


// dp(i, j) = coins(i) + min(dp(i+2, j), dp(i+1, j-1))
// or dp(i, j) = coins(j) + min(dp(i+1, j-1), dp(i, j-2))

int pickcoinmaxgain::MaxGainPickupCoin(vector<int> coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    int i, j , gap;
    for (gap = 0; gap < n; ++gap) {
        for (i = 0, j = gap; j < n; ++j, ++i) {
            int a = (i + 2 <= j) ? dp[i + 2][j] : 0;
            int b = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
            int c = (i <= j - 2) ? dp[i][j - 2] : 0;
            int A = coins[i] + std::min(a, b);
            int B = coins[j] + std::min(b, c);
            dp[i][j] = std::max(A, B);
        }
    }

    return dp[0][n-1];
}


