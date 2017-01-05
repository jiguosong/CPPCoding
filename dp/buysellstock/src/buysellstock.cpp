/*

Say you have an array for which the ith element is the price of a given stock
on day i.

If you were only permitted to complete at most one transaction (ie, buy one and
sell one share of the stock), design an algorithm to find the maximum profit.

*/

#include "buysellstock.h"
#include <limits>

void buysellstock::dummy() 
{
}

int buysellstock::maxStockProfit(vector<int> prices)
{
	int res = 0;
	int minp_sofar = prices[0];

	for(int i = 1; i< prices.size(); ++i) {
		res = std::max(res, prices[i] - minp_sofar);
		minp_sofar = std::min(minp_sofar, prices[i]);
	}

	return res;
}
