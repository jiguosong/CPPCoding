/*
There are a row of n houses, each house can be painted with one of the three colors:
red, blue or green. The cost of painting each house with a certain color is different.
You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost
matrix. For example, costs[0][0] is the cost of painting house 0 with color red;
costs[1][2] is the cost of painting house 1 with color green, and so on...

Find the minimum cost to paint all houses.

Note:
All costs are positive integers.
*/

#include "painthouses.h"

void painthouses::dummy()
{
}

unsigned int painthouses::minCost(vector<vector<int>>& costs)
{
	vector<vector<int>> dp = costs;

	for (int i = 1; i < costs.size(); ++i) {
		dp[i][0] += std::min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] += std::min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] += std::min(dp[i - 1][0], dp[i - 1][1]);
	}

	return std::min(std::min(dp.back()[0], dp.back()[1]), dp.back()[2]);
}
