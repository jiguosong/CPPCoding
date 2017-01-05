/*

Say you have an array for which the ith element is the price of a given stock
on day i.

Design an algorithm to find the maximum profit. You may complete as many
transactions as you like (ie, buy one and sell one share of the stock
multiple times). However, you may not engage in multiple transactions at
the same time (ie, you must sell the stock before you buy again).

*/

#include "buysellstock2.h"

void buysellstock2::dummy() 
{
}

int buysellstock2::maxStockProfit(vector<int> prices)
{
	int res = 0;

	for(int i = 1; i < prices.size(); ++i) {
		int tmp = prices[i] - prices[i-1];
		res += tmp > 0 ? tmp : 0;
	}

	return res;
}
