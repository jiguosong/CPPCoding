/*

 Given a collection of candidate numbers (C) and a target number (T),
 find all unique combinations in C where the candidate numbers sums to T.
 Each number in C may only be used once in the combination.

 Note:
 All numbers (including target) will be positive integers.
 Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 The solution set must not contain duplicate combinations.

 For example, given candidate set 10,1,2,7,6,1,5 and target 8,
 A solution set is:
 [1, 7]
 [1, 2, 5]
 [2, 6]
 [1, 1, 6] */

#include "combination_sum2.h"
#include <algorithm>

void combination_sum2::dummy()
{
}

static void helper(vector<int> &candidate, int target, int level,
		vector<int> &tmp, vector<vector<int>> &res)
{
	if (target < 0)
		return;
	if (target == 0) {
		res.push_back(tmp);
		return;
	}

	for (int i = level; i < candidate.size(); ++i) {
		if(i > level && candidate[i-1] == candidate[i]) continue;
		int s = candidate[i];
		tmp.push_back(s);
		helper(candidate, target - s, i + 1, tmp, res);
		tmp.pop_back();
	}
}

vector<vector<int>> combination_sum2::combinationSum2(vector<int> &candidates,
		int target)
{
	vector<vector<int>> res;
	vector<int> tmp;
	std::sort(candidates.begin(), candidates.end());

	helper(candidates, target, 0, tmp, res);

	return res;
}
