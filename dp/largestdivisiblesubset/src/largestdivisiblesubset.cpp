/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)

Example 2:

nums: [1,2,4,8]

Result: [1,2,4,8]
*/


#include "largestdivisiblesubset.h"

#include <algorithm>

void largestdivisiblesubset::dummy()
{
}

vector<int> largestdivisiblesubset::largestdivset(vector<int> &nums)
{
	// pair: first is len, second is idx
	vector<std::pair<int, int>> dp(nums.size());
	vector<int> res;
	int max = 0;
	int max_idx = 0;

	std::sort(nums.begin(), nums.end());

	for(int i = 0; i < nums.size(); ++i) {
		for (int j = i; j >= 0; --j) {
			if(nums[i] % nums[j] == 0 && dp[i].first < dp[j].first + 1) {
				dp[i].first = dp[j].first + 1;
				dp[i].second = j;
				if(dp[i].first > max) {
					max = dp[i].first;
					max_idx = i;
				}
			}
		}
	}

	for(int i = 0; i < max; ++i) {
		res.push_back(nums[max_idx]);
		max_idx = dp[max_idx].second;  // this is just like linked list, we jump back
	}

	return res;
}
