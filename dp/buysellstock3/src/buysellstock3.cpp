/*
 Say you have an array for which the ith element is the price of a given stock
 on day i.

 Design an algorithm to find the maximum profit. You may complete at most
 two transactions.

 Note:
 You may not engage in multiple transactions at the same time (ie, you must
 sell the stock before you buy again).

 */

#include "buysellstock3.h"

void buysellstock3::dummy()
{
}

int buysellstock3::maxStockProfit(vector<int> prices)
{
	int n = prices.size();
	vector<vector<int>> local(n, vector<int>(3, 0));
	vector<vector<int>> global(n, vector<int>(3, 0));

	for (int i = 1; i < n; ++i) {
		int diff = prices[i] - prices[i - 1];
		for (int j = 1; j <= 2; ++j) {
			local[i][j] = std::max(global[i - 1][j - 1] + std::max(diff, 0),
					local[i - 1][j] + diff);
			global[i][j] = std::max(global[i - 1][j], local[i][j]);
		}
	}

	return global[n - 1][2];

}
