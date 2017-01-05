/*
 * N_sum.cpp
 *
 *  Created on: Nov 24, 2016
 *      Author: songjiguo
 */

#include "N_sum.h"
#include <unordered_map>
#include <algorithm>

vector<int> N_sum::twoSum(vector<int> &nums, int target)
{
	std::unordered_map<int, int> map;

	for (int i = 0; i < nums.size(); ++i) {
		int k = target - nums[i];
		if (map.count(k) && (map.at(k) != i)) {
			return {i, map.at(k)};
		}
		map[nums[i]] = i;
	}

	return {};
}

/*Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
 * Find all unique triplets in the array which gives the sum of zero.*/
vector<vector<int>> N_sum::threeSum(vector<int>& nums)
{
	vector<vector<int>> res;
	std::sort(nums.begin(), nums.end());

	for (int i = 0; (size_t) i < nums.size(); i++) {
		if (nums[i] > 0)
			break;
		if (i > 0 && nums[i] == nums[i - 1])
			continue;
		int target = 0 - nums[i];
		int left = i + 1;
		int right = nums.size() - 1;
		while (left < right) {
			if (nums[left] + nums[right] == target) {
				res.push_back( { nums[i], nums[left], nums[right] });
				while (left < right && nums[left] == nums[left + 1])
					left++;
				while (left < right && nums[right] == nums[right - 1])
					right--;
				left++;
				right--;
			} else if (nums[left] + nums[right] < target) {
				left++;
			} else {
				right--;
			}
		}
	}
	return res;

}
