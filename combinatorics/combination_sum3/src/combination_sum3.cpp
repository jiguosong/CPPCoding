/*

 Find all possible combinations of k numbers that add up to a number n,
 given that only numbers from 1 to 9 can be used and each combination
 should be a unique set of numbers.

 Ensure that numbers within the set are sorted in ascending order.

 Example 1:

 Input: k = 3, n = 7

 Output:

 [[1,2,4]]


 Example 2:

 Input: k = 3, n = 9

 Output:

 [[1,2,6], [1,3,5], [2,3,4]]

 */

#include "combination_sum3.h"

void combination_sum3::dummy()
{
}

static void helper(int k, int n, int level, vector<int>&tmp,
		vector<vector<int>> &res)
{
	if (n < 0)
		return;
	if (n == 0 && tmp.size() == k) {
		res.push_back(tmp);
		return;
	}

	for (int i = level; i <= 9; ++i) {
		tmp.push_back(i);
		helper(k, n - i, i + 1, tmp, res);
		tmp.pop_back();
	}

}

vector<vector<int>> combination_sum3::combinationSum3(int k, int n)
{
	vector<vector<int>> res;
	vector<int> tmp;

	helper(k, n, 1, tmp, res);

	return res;
}
